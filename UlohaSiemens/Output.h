#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Output
{
public:
	Output(string nazovSuboru);
	~Output();
	void writeLine(string outputLine);
private:
	ofstream file;
};

