//
// Created by Marquise Bell on 4/11/2019.
//

#ifndef DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H
#define DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H

#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

//struct coordinate{
//    bool compareX;
//    bool compareY;
//
//    void setCompareX(bool x) { compareX = x; compareY = false; }
//    void setCompareY(bool y) { compareX = false; compareY = y; }
//
//    bool getCompareX() { return compareX; }
//    bool getCompareY() { return compareY; }
//};


int compX(const void*, const void*);
int compY(const void*, const void*);


double closestSplit(vector<point>*, int, double);
double closestUtil(vector<point>*, int);
void heapify(vector<point>*, int, int);
void heapSort(vector<point>*, int, bool);
double closest(vector<point>*, int);

void merge(vector<point>, int, int, int, int);
void mergeSort(vector<point>, int, int, int);



#endif //DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H
