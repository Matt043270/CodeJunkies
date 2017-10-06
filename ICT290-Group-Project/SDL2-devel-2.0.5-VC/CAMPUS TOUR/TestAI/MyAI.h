#ifndef MyAI_H
#define MyAI_H

#include<fstream>
#include<sstream>
#include<iostream>
#include"mystack.h"
#include<string>

using namespace std;
struct Point
{
    float x;
    float y;
    float z;
};
//for Movement, the class should subtract pofloat A from pofloat B
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

    */
class MyAI{

public:

    MyAI();
        /**
        @brief Updates the AI's current position and checks if it has reached its destination
        (Pofloat B)

        @retval A Point structure, which represents the AI's current position on the path
        */
    Point Update();

        /**
        @brief Reads in a file referred to by inFile, of 3D pofloat data.
        Stores each pofloat in a struct 3DPofloat, then stores
        each struct in member pofloatStack in order received
        */
    bool readInFile(string fileString);



private:

        /**
        @brief used in Update to set a new starting pofloat
        */
    void setPointA(float x, float y, float z);

        /**
        @brief used in Update to set a new destination pofloat
        */
    void setPointB(float x, float y, float z);



    //below are 2 methods useful for debugging
    void displayPointA();

    void displayPointB();

    void displayDist();

    void displayTravel();

        ///A stack containing all the pofloats in the AI path
    MyStack<Point> pointStack;
        ///current pofloat
    Point pointA;
        ///destination pofloat
    Point pointB;

        //the distance to travel between pointA and B is divided by the speed
        //thus, the higher the value of speed, the SLOWER it will be
        ///how quickly it reaches pointB; higher value is slower
    float speed;
        ///how far the AI travels each update
    float travelx, travely, travelz;
        ///how far to travel between pointA and B
    float distx, disty, distz;
        ///determines if new dist and travel values need calculating
    bool needNewDist;


};
#endif // MyAI_H
