#include "FindWays.h"

FindWays::FindWays(vector<Connection*>* connections, vector<Connection*>* hladaneCesty, Output* out)
{
	this->pravidloBoloKontrolovane = false;
	for (size_t i = 0; i < hladaneCesty->size(); i++)
	{
		if (findWayFromStartToEnd(hladaneCesty->at(i)->getStart(), hladaneCesty->at(i)->getEnd(), connections)) 
			out->writeLine("Yes");
		else 
			out->writeLine("No");
		indexKontrolovanychPravidiel.clear();
	}
}

FindWays::~FindWays()
{

}

bool FindWays::findWayFromStartToEnd(string pStart, string pEnd, vector<Connection*>* connections)
{
	for (size_t i = 0; i < connections->size(); i++)
	{
		pravidloBoloKontrolovane = false;
		for (size_t y = 0; y < indexKontrolovanychPravidiel.size(); y++)
		{
			if (indexKontrolovanychPravidiel[y] == i)
				pravidloBoloKontrolovane = true;
		}
		if (!pravidloBoloKontrolovane)
		{
			if ((connections->at(i)->getStart() == pStart && connections->at(i)->getEnd() == pEnd) || (connections->at(i)->getEnd() == pStart && connections->at(i)->getStart() == pEnd)) {
				return true;
			}
			else if (connections->at(i)->getStart() == pStart)
			{
				indexKontrolovanychPravidiel.push_back(i);
				if (findWayFromStartToEnd(connections->at(i)->getEnd(), pEnd, connections))
					return true;
				else
				{
					indexKontrolovanychPravidiel.erase(find(indexKontrolovanychPravidiel.begin(), indexKontrolovanychPravidiel.end(), i));
				}
			}
			else if (connections->at(i)->getEnd() == pStart)
			{
				indexKontrolovanychPravidiel.push_back(i);
				if (findWayFromStartToEnd(connections->at(i)->getStart(), pEnd, connections))
					return true;
				else
				{
					indexKontrolovanychPravidiel.erase(find(indexKontrolovanychPravidiel.begin(), indexKontrolovanychPravidiel.end(), i));
				}
			}
		}
	}
	return false;
}
