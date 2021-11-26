#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Connection.h"

using namespace std;

class Input
{
public:
	Input();
	~Input();
	void nacitajUdaje(vector<Connection*>* connections, vector<Connection*>* hladaneCesty, string nazovSuboru);
private:
	wifstream subor;
};

