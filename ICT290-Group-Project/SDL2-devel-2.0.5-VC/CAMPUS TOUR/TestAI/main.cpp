#include <iostream>
#include"MyAI.h"
#include<string>

using namespace std;

int main()
{
    MyAI ai;
    int i = 0;
    Point b;


    string line = "path.txt";
    string line2 = "fuelPath.txt";
    if(ai.readInFile(line) == 0 || ai.readFuelFile(line2) == 0)
    {
        cout << "Failed to read file" << endl;
    }


    else
    {
        while(i == 0)
        {
            cout << "Press 1 to stop" << endl;
            cin >> i;

            b = ai.Update();
            cout << b.x << " " << b.y << " " << b.z << " " << b.rot << endl;
        }

    }



    cout << "Hello world!" << endl;
    return 0;
}
