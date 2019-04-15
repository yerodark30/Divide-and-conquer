//
// Created by Marquise Bell on 4/11/2019.
//

#include "Divide_and_Conquer.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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

double closestSplit(point* pointArray, int size, double d){
    double minimum = d;
    bool sortX = false;

    heapSort(pointArray, size, sortX);

    for(int i = 0; i < size; ++i){
        for(int j = i + 1; j < size && (pointArray[j].getY() - pointArray[i].getY()) < minimum; ++j){
            if(pointDistance(pointArray[i],pointArray[j]) < minimum){
                minimum = pointDistance(pointArray[i],pointArray[j]);
            }
        }
    }
    return minimum;
}

double closestUtil(point* pointArray, int size){
    if(size <= 3){
        vector<point> pointVector;
        for(int i = 0; i < size; i++){
            pointVector.push_back(pointArray[i]);
        }
        return bruteForce(pointVector);
    }

    int middle = size/2;
    point midPoint = pointArray[middle];

    double dl = closestUtil(pointArray, middle);
    double dr = closestUtil(pointArray + middle, size - middle);

    double d = Min(dl, dr);


    int count = 0;
    point strip[size];

    for(int i = 0; i < size; i++){
        if(abs(pointArray[i].getX() - midPoint.getX()) < d){
            strip[count] = pointArray[i];
            count++;
        }
    }

    return Min(d, closestSplit(strip, count, d));
}

double closest(vector<point>* vectorPtr, int size){
    point *pointArray;
    pointArray = convertVector(vectorPtr);
    bool sortX = true;
    heapSort(pointArray, size, sortX);

    return closestUtil(pointArray, size);
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

void heapify(point* pointArray, int size, int index, bool decide){
    int maximum = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(decide){
        if(left < size && pointArray[left].getX() > pointArray[maximum].getX()){
            maximum = left;
        }
        if(right < size && pointArray[right].getX() > pointArray[maximum].getX()){
            maximum = right;
        }
    }
    else{
        if(left < size && pointArray[left].getY() > pointArray[maximum].getY()){
            maximum = left;
        }
        if(right < size && pointArray[right].getY() > pointArray[maximum].getY()){
            maximum = right;
        }
    }


    if(maximum != index){
        swap(pointArray[index], pointArray[maximum]);

        heapify(pointArray, size, maximum, decide);
    }
}

void heapSort(point* pointArray, int size, bool decide){
    for(int i = size/2 - 1; i >=0; i--){
        heapify(pointArray, size, i, decide);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(pointArray[0], pointArray[i]);
        heapify(pointArray, i, 0, decide);
    }
}

point* convertVector(vector<point>* pointVector){
    point* pointArrayPtr = &(*pointVector)[0];
    return pointArrayPtr;
}
