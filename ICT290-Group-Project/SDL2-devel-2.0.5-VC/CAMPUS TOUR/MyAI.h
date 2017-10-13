#ifndef MyAI_H
#define MyAI_H

#include<fstream>
#include<sstream>
#include<iostream>
#include"mystack.h"
#include<string>
#include<math.h>

using namespace std;
struct Point
{
    double x = 0;
    double y = 0;
    double z = 0;
    double rot = 0;
};
//for Movement, the class should subtract podouble A from podouble B
//it should divide the result by some number X
//and add the result Y to its current position in the Update function.
//The value of X will determine the speed at which the AI moves

    /**
    @class MyAI

    @author Chris Wright
    @version 1
    @date 4/10

    @todo Calculate a path between a set of 3D points as given in a file.
    The 'path' is a larger subset of intermediate points, that it returns as caculated

    @bug Rounding errors may result in the AI's current position being a little erratic (jumping
        back or fowards.).  The effect should be minimal.
        Currently, the last point of a given path is never reached, as the Stack is checked for being empty
        before updating current position, and the last point has been removed, but not moved towards.

    */
class MyAI{

public:

    MyAI();
        /**
        @brief Updates the AI's current position and checks if it has reached its destination
        (Podouble B)

        @retval A Point structure, which represents the AI's current position on the path
        */
    Point Update();

        /**
        @brief Reads in a file referred to by inFile, of 3D podouble data.
        Stores each podouble in a struct 3DPodouble, then stores
        each struct in member podoubleStack in order received
        */
    bool readInFile(string fileString);

    bool readFuelFile(string fileString);

    void setSpeed(double s) { speed = s; };



private:

        /**
        @brief used in Update to set a new starting podouble
        */
    void setPointA(double x, double y, double z);

        /**
        @brief used in Update to set a new destination podouble
        */
    void setPointB(double x, double y, double z);

    void calcRotation();

    void getMoreFuel();



    //below are 2 methods useful for debugging
    void displayPointA();

    void displayPointB();

    void displayDist();

    void displayTravel();

        ///A stack containing all the podoubles in the AI path
    MyStack<Point> pointStack;

    MyStack<Point> fuelPointStack;
        ///current podouble
    Point pointA;
        ///destination podouble
    Point pointB;

        //the distance to travel between pointA and B is divided by the speed
        //thus, the higher the value of speed, the SLOWER it will be
        ///how quickly it reaches pointB; higher value is slower
    double speed;
        ///how far the AI travels each update
    double travelx, travely, travelz;
        ///how far to travel between pointA and B
    double distx, disty, distz;
        ///determines if new dist and travel values need calculating
    bool needNewDist;

    int i = 0;

    int fuel = 100;

    bool gotFuel = false;


};
#endif // MyAI_H
