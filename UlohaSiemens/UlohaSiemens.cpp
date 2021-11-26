#include <iostream>
#include "Input.h"
#include "Connection.h"
#include "FindWays.h"
#include "Output.h"


int main()
{
    Input* in = new Input();
    vector<Connection*> connections; 
    vector<Connection*> hladaneCesty;
    string nazovSuboru;
    cout << "Zadajte cestu ku vstupnemu suboru" << endl;
    cin >> nazovSuboru;
    if (!in->isAccesible(nazovSuboru))
    {
        cout << "!!!Zadany vstupny subor neexistuje!!!" << endl;
        exit(0);
    }
    in->nacitajUdaje(&connections, &hladaneCesty, nazovSuboru);

    Output* out = new Output(nazovSuboru.substr(0, nazovSuboru.length() - 4) + ".out");

    FindWays* findWays = new FindWays(&connections, &hladaneCesty, out);
    cout << "\n\nProgram prebehol uspesne" << endl;

    //uvolnovanie pamate
    for (size_t i = 0; i < connections.size(); i++)
    {
        connections[i]->~Connection();
    }
    connections.clear();
    for (size_t i = 0; i < hladaneCesty.size(); i++)
    {
        hladaneCesty[i]->~Connection();
    }
    hladaneCesty.clear();
    in->~Input();
    out->~Output();
    findWays->~FindWays();
}

