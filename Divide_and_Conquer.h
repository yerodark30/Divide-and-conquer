//
// Created by Marquise Bell on 4/11/2019.
//

#ifndef DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H
#define DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "BruteForce.h"
using namespace std;


int compX(const void*, const void*);
int compY(const void*, const void*);

point* convertVector(vector<point>*);
double closestSplit(point* pointArray, int, double);
double closestUtil(point* pointArray, int);
void heapify(point* pointArray, int, int);
void heapSort(point* pointArray, int, bool);
double closest(point* pointArray, int);

void merge(vector<point>, int, int, int, int);
void mergeSort(vector<point>, int, int, int);



#endif //DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H
