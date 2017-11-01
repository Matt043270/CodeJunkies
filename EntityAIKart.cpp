#include"EntityAIKart.h"

EntityAIKart::EntityAIKart(string fileString)
{
	EntityKart::Initialize();
	readInFile(fileString);
}
Point EntityAIKart::Update()
{
	//if there are more points in the stack, calculate path
	//else, return curent location
	if (!(pointStack.isEmpty()))
	{


		//displayPointA();
		//displayPointB();

		//calculate new dist and travel values if its a new starting point
		if (needNewDist)
		{
			//determine distance between points
			distx = pointB.x - pointA.x;
			disty = pointB.y - pointA.y;
			distz = pointB.z - pointA.z;

			//displayDist();

			//determine unit of distance travelled each update (travel)

			travelx = distx / m_speed;
			travely = disty / m_speed;
			travelz = distz / m_speed;

			//displayTravel();

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
		//so this revised condition works on the idea that the number of required iterations must be equal to m_speed
		//as m_speed is the divisor (makes perfect sense)
		if (i >= m_speed)//if(pointA.x >= pointB.x && pointA.y >= pointB.y && pointA.z >= pointB.z)
		{
			pointA = pointB;
			pointB = pointStack.pop();
			cout << "Reached pointB, changed to Point A. Displaying new PointA and PointB" << endl;
			//displayPointA();
			//displayPointB();

			needNewDist = true;

			i = 0;
			calcRotation();


		}


		return pointA;
	}

	//displayPointA();
	//displayPointB();


	return pointA;




}

void EntityAIKart::calcRotation()
{
	pointA.rot = 0;

}
bool EntityAIKart::readInFile(string fileString)
{
	ifstream infile(fileString);
	string line;
	stringstream ss;
	double tempx, tempy, tempz;
	Point tempPoint;

	if (!infile)
	{
		return false;
	}

	while (getline(infile, line))
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

void EntityAIKart::Tick()
{
	Update();
	Translate(pointA.x, pointB.y, pointA.z);
	Rotate(pointA.rot, 0, 0);
}
void EntityAIKart::setPointA(double x, double y, double z)
{
	pointA.x = x;
	pointA.y = y;
	pointA.z = z;
}


void EntityAIKart::setPointB(double x, double y, double z)
{
	pointB.x = x;
	pointB.y = y;
	pointB.z = z;
}


void EntityAIKart::displayPointA()
{
	cout << "Point A.x: " << pointA.x << endl;
	cout << "Point A.y: " << pointA.y << endl;
	cout << "Point A.z: " << pointA.z << endl;
}

void EntityAIKart::displayPointB()
{
	cout << "Point B.x: " << pointB.x << endl;
	cout << "Point B.y: " << pointB.y << endl;
	cout << "Point B.z: " << pointB.z << endl;
}

void EntityAIKart::displayDist()
{

	cout << "distx: " << distx << endl;
	cout << "disty: " << disty << endl;
	cout << "distz: " << distz << endl;
}

void EntityAIKart::displayTravel()
{

	cout << "travelx: " << travelx << endl;
	cout << "travely: " << travely << endl;
	cout << "travelz: " << travelz << endl;
}