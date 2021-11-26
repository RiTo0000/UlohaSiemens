#include <iostream>
#include "Input.h"
#include "Connection.h"
#include "FindWays.h"


int main()
{
    std::cout << "Hello World!\n";
    Input* in = new Input();
    vector<Connection*> connections; 
    vector<Connection*> hladaneCesty;
    in->nacitajUdaje(&connections, &hladaneCesty, "D:\\vstupnySubor.txt");
    cout << "------------------------------------vypis z mainu-----------------------------------------" << endl;
    for (size_t i = 0; i < connections.size(); i++)
    {
        cout << connections[i]->getStart() << " " << connections[i]->getEnd() << endl;
    }
    cout << endl;
    for (size_t i = 0; i < hladaneCesty.size(); i++)
    {
        cout << hladaneCesty[i]->getStart() << " " << hladaneCesty[i]->getEnd() << endl;
    }
    cout << "\n\n\n" << endl;



    FindWays* findWays = new FindWays(&connections, &hladaneCesty);
}

