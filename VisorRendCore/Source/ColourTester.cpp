#include "ColourTester.h"
#include <iostream>

ColourTester::ColourTester(int startingColour)
{
	*currentColour = (startingColour % 3);
	*colours[*currentColour] = 1.0f;
}

ColourTester::~ColourTester()
{
	delete currentColour;
	for (int i = 0; i < 3; i++)
	{
		delete colours[i];
	}
}

void ColourTester::CycleColoursNext(int* currentColour)
{
	if (*currentColour == 0)
		std::cout << "Red!" << std::endl;
	else if (*currentColour == 1)
		std::cout << "Green!" << std::endl;
	else if (*currentColour == 2)
		std::cout << "Blue!" << std::endl;
	*currentColour = (*currentColour + 1) % 3;
}

void ColourTester::CycleColours()
{
	float valueCap = 1;
	float valueMin = 0;
	float* nowColour = colours[*currentColour];
	float* pastColour = colours[(*currentColour + 2) % 3];

	if (*nowColour >= valueCap)
	{
		*nowColour = valueCap;
		*pastColour = valueMin;
		CycleColoursNext(currentColour);
	}
	*nowColour += speed;
	*pastColour -= speed;
}