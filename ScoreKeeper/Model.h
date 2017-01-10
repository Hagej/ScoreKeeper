#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <time.h>

class Model
{
public:
	Model();
	~Model();
	
	int CalculateScore(); // r�kna ut dagarna. 
	int AddScore(int score, char* player); // addera po�ngen
	int getScore(const char*); // f� po�ngen

	int m_Kajsa = 0, m_Johan = 0;

private:

//	char* hej = "hej"

time_t now;
double diff;
time_t lasttime = 0;


};

