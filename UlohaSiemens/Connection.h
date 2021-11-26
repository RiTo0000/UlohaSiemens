#pragma once
#include <string>

using namespace std;

class Connection
{
public:
	Connection(string pStart, string pEnd);
	~Connection();
	string getStart();
	string getEnd();
private:
	string start;
	string end;
};