#include <iostream>
#include"MyAI.h"
#include<string>

using namespace std;

int main()
{
    MyAI ai;
    int i = 0;


    string line = "path2.txt";
    if(ai.readInFile(line) == 0)
    {
        cout << "Failed to read file" << endl;
    }
    else
    {
        while(i == 0)
        {
            cout << "Press 1 to stop" << endl;
            cin >> i;

            ai.Update();
        }

    }



    cout << "Hello world!" << endl;
    return 0;
}
