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
    double smallestDistance1, smallestDistance2;

    vector<point>* vectorPtr = new vector<point>;

    cout << "Points in the vector..." << endl;

    srand(time(0));
    for(int i = 0; i < 12; i++){
        point p(rand() % 20, rand() % 20);
        vectorPtr->push_back(p);
        (*vectorPtr)[i].display(cout);
    }
    cout << endl;

//    mergeSort((*vectorPtr), 0, (*vectorPtr).size() - 1, 1);

    // sortX is true for sorting by x-coordinate
    // sort Y is false for sorting by y-coodinate
    double holder = 9.8;
    bool SortX = false;
    heapSort(vectorPtr,(*vectorPtr).size(),SortX);

    cout << "Sorted point vector" << endl;
    for (auto &i : (*vectorPtr)) {
        i.display(cout);
    }

    cout << endl;





    smallestDistance1 = bruteForce((*vectorPtr));
    cout << "\n" << smallestDistance1 << endl;
    cout << closest((vectorPtr), (*vectorPtr).size()) << endl;
    return 0;
}






