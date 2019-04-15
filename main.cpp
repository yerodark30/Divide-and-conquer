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
    vector<point>* vectorPtr = new vector<point>;

    cout << "Points in the vector..." << endl;

    srand(time(0));
    for(int i = 0; i < 8; i++){
        point p(rand() % 50 + i, rand() % 50);
        vectorPtr->push_back(p);
        (*vectorPtr)[i].display(cout);
    }
    cout << endl;


    cout << "\nBrute Force: " << bruteForce((*vectorPtr)) << endl;
    cout << "Divide and Conquer" << closest(vectorPtr, (*vectorPtr).size()) << endl;
    return 0;
}






