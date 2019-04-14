//
// Created by Marquise Bell on 4/12/2019.
//

#include "BruteForce.h"
#include "cfloat"
#include "cmath"
using namespace std;

double bruteForce(vector<point> pointVector){
    double minimum = DBL_MAX;

    for(int i = 0; i < pointVector.size(); i++){
        for(int j = 0; j < pointVector.size(); j++){
            minimum = min(pointDistance(pointVector[i], pointVector[j]), minimum);
        }
    }
    return minimum;
}

double pointDistance(point p1, point p2){
    return sqrt((p2.getX() - p1.getX())*(p2.getX() - p1.getX()) +
                (p2.getY() - p1.getY()*(p2.getY() - p1.getY())));
}
