#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

bool Input::isAccesible(string nazovSuboru)
{
    ifstream file(nazovSuboru);
    return file.good();
}

void Input::nacitajUdaje(vector<Connection*>* connections, vector<Connection*>* hladaneCesty, string nazovSuboru)
{
    ifstream file(nazovSuboru);
    string uncatConnections;
    getline(file, uncatConnections);
    string tempUncatConnections = uncatConnections;
    string tempCutConnections;
    for (size_t i = 0; i < count(uncatConnections.begin(), uncatConnections.end(), ','); i++)
    {
        
        tempCutConnections = tempUncatConnections.substr(0, tempUncatConnections.find(","));
        connections->push_back(new Connection(tempCutConnections.substr(0, tempCutConnections.find("-")),
            tempCutConnections.substr(tempCutConnections.find("-") + 1, tempCutConnections.length())));
        tempUncatConnections = tempUncatConnections.substr(tempUncatConnections.find(",") + 1, tempUncatConnections.length());
    }
    tempCutConnections = tempUncatConnections;
    connections->push_back(new Connection(tempCutConnections.substr(0, tempCutConnections.find("-")),
        tempCutConnections.substr(tempCutConnections.find("-") + 1, tempCutConnections.length())));

    string str;
    while (getline(file, str))
    {
        hladaneCesty->push_back(new Connection(str.substr(0, str.find(",")), str.substr(str.find(",") + 1, str.length())));
    }

    uncatConnections = "";
    tempUncatConnections = "";
    tempCutConnections = "";
    str = "";
    file.close();
}
