#pragma once
class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	float DeltaTime();

	void UpdateDeltaTime();

private:
	float previousTime = 0.0f;
	float newTime = 0.0f;
	float deltaTime = 0.0f;
};