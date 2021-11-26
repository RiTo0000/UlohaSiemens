#include "Connection.h"

Connection::Connection(string pStart, string pEnd)
{
	this->start = pStart;
	this->end = pEnd;
}

Connection::~Connection()
{
	this->start = "";
	this->end = "";
}

string Connection::getStart()
{
	return this->start;
}

string Connection::getEnd()
{
	return this->end;
}
