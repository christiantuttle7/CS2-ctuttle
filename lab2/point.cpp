#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    x = X;
    y = Y;
    nearestPoint = closestPoint;
    
}
//Destructor
points::Point::~Point()
{
    x = 0;
    y = 0;
    nearestPoint = nullptr;
}

//Getters
int points::Point::getX()
{

    return x;
}

int points::Point::getY()
{
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    /*
        sets the point with the shortest distance to the very first point in the array 
        (it will then compare it to every other point)
    */
    int pointWithShortestDistanceIndex = 0;
    float shortestDistance = distPoints(*pointList[0]);
    //for loop that goes through every point in the array
    for(int i = 1; i < arrSize; i++){
        //gets the distance of the point the loop is on
        float distance = distPoints(*pointList[i]);

        if(distance < shortestDistance){
            //if the distance is shorter than any other distance found so far then update the distance and index;
            pointWithShortestDistanceIndex = i;
            shortestDistance = distance;
        }
    }

    //return the point in the array that had the shortest distance
    return pointList[pointWithShortestDistanceIndex];
}

//Setters
void points::Point::setX(int newVal)
{
  x = newVal;
}

void points::Point::setY(int newVal)
{
    y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    
    float distance;
    //math of the distance formula
    distance = sqrt( pow((x - point.getX()), 2)  +  pow((y - point.getY()), 2) );

    return distance;
}