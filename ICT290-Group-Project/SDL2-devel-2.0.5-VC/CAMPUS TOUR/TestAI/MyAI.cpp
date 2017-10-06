#include"MyAI.h"

MyAI::MyAI()
{
    speed = 2;
}
Point MyAI::Update()
{
        //if there are more points in the stack, calculate path
        //else, return curent location
    if(!(pointStack.isEmpty()))
    {


        displayPointA();
        displayPointB();

            //calculate new dist and travel values if its a new starting point
        if(needNewDist)
        {
                //determine distance between points
            distx = pointB.x - pointA.x;
            disty = pointB.y - pointA.y;
            distz = pointB.z - pointA.z;

            displayDist();

                //determine unit of distance travelled each update (travel)

            travelx = distx / speed;
            travely = disty / speed;
            travelz = distz / speed;

            displayTravel();

            needNewDist = false;
        }


            //update PointA to reflect new current posiiton (travel to new position)
        pointA.x += travelx;
        pointA.y += travely;
        pointA.z += travelz;

        displayPointA();

            //check if AI has reached destination, and set new current position
            //and get new destination if true
        if(pointA.x == pointB.x && pointA.y == pointB.y && pointA.z == pointB.z)
        {
            pointA = pointB;
            pointB = pointStack.pop();
            cout << "Reached pointB, changed to Point A. Displaying new PointA and PointB" << endl;
            displayPointA();
            displayPointB();

            needNewDist = true;

        }


        return pointA;
    }

    displayPointA();
    displayPointB();


    return pointA;




}


bool MyAI::readInFile(string fileString)
{
    ifstream infile(fileString);
    string line;
    stringstream ss;
    float tempx, tempy, tempz;
    Point tempPoint;

    if(!infile)
    {
        return false;
    }

    while(getline(infile, line))
    {
        ss.clear();

        ss << line;

        ss >> tempx >> tempy >> tempz;

        tempPoint.x = tempx;
        tempPoint.y = tempy;
        tempPoint.z = tempz;

        pointStack.push(tempPoint);


    }

    //get initial starting point
    pointA = pointStack.pop();
        //get initial destination point
    pointB = pointStack.pop();

    return true;
}

void MyAI::setPointA(float x, float y, float z)
{
    pointA.x = x;
    pointA.y = y;
    pointA.z = z;
}


void MyAI::setPointB(float x, float y, float z)
{
    pointB.x = x;
    pointB.y = y;
    pointB.z = z;
}


void MyAI::displayPointA()
{
    cout << "Point A.x: " << pointA.x << endl;
    cout << "Point A.y: " << pointA.y << endl;
    cout << "Point A.z: " << pointA.z << endl;
}

void MyAI::displayPointB()
{
    cout << "Point B.x: " << pointB.x << endl;
    cout << "Point B.y: " << pointB.y << endl;
    cout << "Point B.z: " << pointB.z << endl;
}

void MyAI::displayDist()
{

    cout << "distx: " << distx << endl;
    cout << "disty: " << disty << endl;
    cout << "distz: " << distz << endl;
}

void MyAI::displayTravel()
{

    cout << "travelx: " << travelx << endl;
    cout << "travely: " << travely << endl;
    cout << "travelz: " << travelz << endl;
}

