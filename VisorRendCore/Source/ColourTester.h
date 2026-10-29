#pragma once
class ColourTester
{
public:
	float* colours[3] = { new float(0), new float(0), new float(0) };
	float speed = 0.01f;

	/// <param name="startingColour">Red = 0, Green = 1, Blue = 2</param>
	ColourTester(int startingColour);
	~ColourTester();

	void CycleColours();

private:
	int* currentColour = new int(0);
	
	void CycleColoursNext(int* currentColour);
};