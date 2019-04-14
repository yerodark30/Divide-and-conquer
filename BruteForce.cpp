//
// Created by Marquise Bell on 4/12/2019.
//

#include "BruteForce.h"
#include "cfloat"
#include "cmath"
using namespace std;

double bruteForce(vector<point> pointVector){
    if(pointVector.empty()){

    }
    if(pointVector.size() == 1){
        // if there is only one point
        return 0;
    }
    double minimum = DBL_MAX;

    for(int i = 0; i < pointVector.size(); ++i){
        for(int j = i + 1; j < pointVector.size(); ++j){
            minimum = Min(pointDistance(pointVector[i], pointVector[j]), minimum);

        }
    }
    return minimum;
}

double pointDistance(point p1, point p2){
    return sqrt( (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
                 (p1.getY() - p2.getY())*(p1.getY() - p2.getY()));
}

double Min(double n1, double n2){
    if(n1 < n2){
        return n1;
    }
    else{
        return n2;
    }
}