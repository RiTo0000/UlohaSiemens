#include "Output.h"

Output::Output(string nazovSuboru)
{
	file.open(nazovSuboru);	
}

Output::~Output()
{
	file.close();
}

void Output::writeLine(string outputLine)
{
	file << outputLine << "\n";
}
