#pragma once
#include <vector>
#include <iostream>
#include "Connection.h"

using namespace std;

class FindWays
{
public:
	FindWays(vector<Connection*>* connections, vector<Connection*>* hladaneCesty);
	~FindWays();
	bool findWayFromStartToEnd(string pStart, string pEnd, vector<Connection*>* connections);
private:
	vector<int> indexKontrolovanychPravidiel;
	bool pravidloBoloKontrolovane;
};

