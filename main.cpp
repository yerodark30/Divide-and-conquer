#include <iostream>
#include "Point.h"
#include "BruteForce.h"
#include <vector>
#include <cfloat>
#include <cmath>
#include <time.h>
#include "Divide_and_Conquer.h"
using namespace std;

int main() {
    vector<point> pointVector;
    double smallestDistance1;

    vector<point>* vectorPtr = new vector<point>;
    point* pointArrayPtr;

    cout << "Points in the vector..." << endl;

    srand(time(0));
    for(int i = 0; i < 8; i++){
        point p(rand() % 10 + i, rand() % 20);
        vectorPtr->push_back(p);
        (*vectorPtr)[i].display(cout);
    }
    cout << endl;

    pointArrayPtr = convertVector(vectorPtr);

    // sortX is true for sorting by x-coordinate
    // sort Y is false for sorting by y-coodinate
    bool SortX = false;
    heapSort(pointArrayPtr,(*vectorPtr).size(),SortX);

    cout << "Sorted point vector" << endl;
    for(int i = 0; i < (*vectorPtr).size(); i++){
        pointArrayPtr[i].display(cout);
    }
    cout << endl;

    smallestDistance1 = bruteForce((*vectorPtr));
    cout << "\n" << smallestDistance1 << endl;
    cout << closest(pointArrayPtr, (*vectorPtr).size()) << endl;
    return 0;
}






