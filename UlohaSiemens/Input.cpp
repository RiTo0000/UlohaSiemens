#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::nacitajUdaje(vector<Connection*>* connections, vector<Connection*>* hladaneCesty, string nazovSuboru)
{
    ifstream file(nazovSuboru);
    string uncatConnections;
    getline(file, uncatConnections);
    cout << uncatConnections << "\n" << endl;
    string tempUncatConnections = uncatConnections;
    string tempCutConnections;
    for (size_t i = 0; i < count(uncatConnections.begin(), uncatConnections.end(), ','); i++)
    {
        //cout << tempUncatConnections.substr(0, tempUncatConnections.find(",")) << endl;
        tempCutConnections = tempUncatConnections.substr(0, tempUncatConnections.find(","));
        connections->push_back(new Connection(tempCutConnections.substr(0, tempCutConnections.find("-")),
            tempCutConnections.substr(tempCutConnections.find("-") + 1, tempCutConnections.length())));
        tempUncatConnections = tempUncatConnections.substr(tempUncatConnections.find(",") + 1, tempUncatConnections.length());
    }
    tempCutConnections = tempUncatConnections;
    connections->push_back(new Connection(tempCutConnections.substr(0, tempCutConnections.find("-")),
        tempCutConnections.substr(tempCutConnections.find("-") + 1, tempCutConnections.length())));
    //cout << tempCutConnections << "\n" << endl;

    string str;
    while (getline(file, str))
    {
        string start = str.substr(0, str.find(","));
        string end = str.substr(str.find(",") + 1, str.length());
        hladaneCesty->push_back(new Connection(start, end));
        //cout << str << endl;
    }
}
