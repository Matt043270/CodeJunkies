#include"MyAI.h"

MyAI::MyAI()
{
    speed = 2;
}
Point MyAI::Update()
{
        //if there are more points in the stack, calculate path
        //else, return curent location
    if(!(pointStack.isEmpty()) && fuel > 0)
    {


        displayPointA();
        displayPointB();

        if(fuel < 50)
        {
            gotFuel = true;
            getMoreFuel();
        }

            //calculate new dist and travel values if its a new starting point
        if(needNewDist)
        {
            i = 0;
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

        i++;
        //displayPointA();

            //check if AI has reached destination, and set new current position
            //and get new destination if true
                    //so this condition here will cause problems; because the current point isn't always starting at less than
                    //the next point (sometimes its greater than and moving in the negative direction
        //so this revised condition works on the idea that the number of required iterations must be equal to speed
        //as speed is the divisor (makes perfect sense)
        if(i >= speed)//if(pointA.x >= pointB.x && pointA.y >= pointB.y && pointA.z >= pointB.z)
        {
                //if current point is fuel point
            if(gotFuel == true)
            {
                    //refill fuel
                fuel = 100;
                gotFuel = false;
            }
            pointA = pointB;
            pointB = pointStack.pop();
            cout << "Reached pointB, changed to Point A. Displaying new PointA and PointB" << endl;
            displayPointA();
            displayPointB();

            needNewDist = true;

            i = 0;
            calcRotation();


        }

        fuel -= 20;
        return pointA;
    }

    displayPointA();
    displayPointB();


    return pointA;




}

void MyAI::calcRotation()
{
    pointA.rot = cos((pointA.x*pointB.x + pointA.y*pointB.y + pointA.z*pointB.z)/
                        (sqrt(pow(pointA.x, 2) + pow(pointA.y, 2) + pow(pointA.z, 2)) * sqrt(pow(pointB.x, 2) + pow(pointB.y, 2) + pow(pointB.z, 2))));

    printf("PointA.rot: %f", pointA.rot);

}

void MyAI::getMoreFuel()
{
    printf("Need more fuel \n");

    Point tempPoint;

    if(!(fuelPointStack.isEmpty()))
    {
        tempPoint = fuelPointStack.pop();

            //preserve path destination
        pointStack.push(pointB);

            //make next goal fuel point
        pointB = tempPoint;

        needNewDist = true;
    }
    else
        printf("No more fuel available\n");

}
bool MyAI::readInFile(string fileString)
{
    ifstream infile(fileString);
    string line;
    stringstream ss;
    double tempx, tempy, tempz;
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

    calcRotation();

    return true;
}

bool MyAI::readFuelFile(string fileString)
{

    ifstream infile(fileString);
    string line;
    stringstream ss;
    double tempx, tempy, tempz;
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

        fuelPointStack.push(tempPoint);
    }
}
void MyAI::setPointA(double x, double y, double z)
{
    pointA.x = x;
    pointA.y = y;
    pointA.z = z;
}


void MyAI::setPointB(double x, double y, double z)
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

