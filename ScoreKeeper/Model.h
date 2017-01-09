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
	int AddScore(int, char*); // addera po�ngen
	int	getScore(const char*); // f� po�ngen



private:

//	char* hej = "hej"
int m_Kajsa = 0, m_Johan = 0;
time_t now;
int diff;
time_t lasttime = 0;


};

