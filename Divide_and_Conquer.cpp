//
// Created by Marquise Bell on 4/11/2019.
//

#include "Divide_and_Conquer.h"
#include "Point.h"
#include "BruteForce.h"
#include "SDL_PLotter.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;





// TODO pass in a sdl object and check that the plotting will work


// TODO try using a combined merge sort with the heapsort to change runtime to n*log(n) instead of n*log(n)^2







bool vector2 = true;

int compX(const void* ptr1, const void* ptr2){
    auto *pointptr1 = (point*)ptr1;
    auto *pointptr2 = (point*)ptr2;

    return (pointptr1->getX() - pointptr2->getX());
}

int compY(const void* ptr1, const void* ptr2){
    auto *pointptr1 = (point*)ptr1;
    auto *pointptr2 = (point*)ptr2;

    return (pointptr1->getY() - pointptr2->getY());
}

double closestSplit(vector<point>* vectorPtr, int size, double d){
    double minimum = d;
    bool sortX = false;

    heapSort(vectorPtr, (*vectorPtr).size(), sortX);

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size && ((*vectorPtr)[j].getY() - (*vectorPtr)[j].getY()) < minimum; ++j){
            if(pointDistance((*vectorPtr)[i],(*vectorPtr)[j]) < minimum){
                minimum = pointDistance((*vectorPtr)[i],(*vectorPtr)[j]);
            }
        }
    }
    return minimum;
}

double closestUtil(vector<point>* vectorPtr, int size){
    if(size <= 3){
        return bruteForce((*vectorPtr));
    }

    int middle = size/2;
    point midPoint = (*vectorPtr)[middle];


    double dl = closestUtil(vectorPtr, middle);


    double dr = closestUtil(&(*(vectorPtr + middle)), size - middle);
    double d = min(dl, dr);

    vector<point>* strip = new vector<point>;
    int count = 0;

    for(int i = 0; i < size; i++){
        if(abs((*vectorPtr)[i].getX() - midPoint.getX()) < d){
            strip->push_back((*vectorPtr)[i]);
            count++;
        }
    }

    return min(d, closestSplit((strip), count, d));
}

double closest(vector<point>* vectorPtr, int size){
    bool sortX = true;
    heapSort(vectorPtr, size, sortX);

    return closestUtil(vectorPtr, size);
}


void merge(vector<point> pointVector, int l, int m, int r, int decide){
    int n1 = m - l + 1;
    int n2 = r - m;

    point leftPoint[n1], rightPoint[n2];

    for(int i = 0; i < n1; i++){
        leftPoint[i] = pointVector[l + i];
    }
    for(int i = 0; i < n2; i++){
        rightPoint[i] = pointVector[m + 1 + i];
    }

    while(!pointVector.empty()){
        pointVector.pop_back();
    }

    // Merge temp arrays back into pointVector
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        // sort by x-coordinate
        if(decide == 1){
            if(leftPoint[i].getX() <= rightPoint[i].getX()){
                pointVector.push_back(leftPoint[i]);
                i++;
            }
            else{
                pointVector.push_back(rightPoint[j]);
                j++;
            }
            k++;
        }
        // sort by y-coordinate
        
        
        // TODO check to make sure th sorting by y coordinates maintains the integrity of the vector
        
        else if(decide == 0){
            if(leftPoint[i].getY() <= rightPoint[i].getY()){
                pointVector.push_back(leftPoint[i]);
                i++;
            }
            else{
                pointVector.push_back(rightPoint[j]);
                j++;
            }
            k++;
        }
    }

    while(i < n1){
        pointVector.push_back(leftPoint[i]);
        i++;
        k++;
    }
    while(j < n2){
        pointVector.push_back(rightPoint[j]);
        j++;
        k++;
    }
}

void mergeSort(vector<point> pointVector, int l, int r, int decide){
    if(l < r){
        int middle = l + (r - 1)/2;

        mergeSort(pointVector, l, middle, decide);
        mergeSort(pointVector, middle + 1, r, decide);

        merge(pointVector, l, middle, r, decide);
    }
}

void heapify(vector<point>* vectorPtr, int size, int index, bool decide){
    int maximum = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(decide){
        if(left < size && (*vectorPtr)[left].getX() > (*vectorPtr)[maximum].getX()){
            maximum = left;
        }
        if(right < size && (*vectorPtr)[right].getX() > (*vectorPtr)[maximum].getX()){
            maximum = right;
        }
    }
    else{
        if(left < size && (*vectorPtr)[left].getY() > (*vectorPtr)[maximum].getY()){
            maximum = left;
        }
        if(right < size && (*vectorPtr)[right].getY() > (*vectorPtr)[maximum].getY()){
            maximum = right;
        }
    }


    if(maximum != index){
        swap((*vectorPtr)[index], (*vectorPtr)[maximum]);

        heapify(vectorPtr, size, maximum, decide);
    }
}

void heapSort(vector<point>* vectorPtr, int size, bool decide){
    for(int i = size/2 - 1; i >=0; i--){
        heapify(vectorPtr, size, i, decide);
    }

    for(int i = size - 1; i >= 0; i--){
        swap((*vectorPtr)[0], (*vectorPtr)[i]);
        heapify(vectorPtr, i, 0, decide);
    }
}


