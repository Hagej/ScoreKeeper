#pragma once
#include <ctime>
#include <iostream>
#include <string>

class Model
{
public:
	Model();
	~Model();
	
	int CalculateScore(); // r�kna ut dagarna. 
	void Model::AddScore(int, char*); // addera po�ngen



private:

//	char* hej = "hej"
int m_Kajsa; 
int m_Johan;
time_t now;
double diff;
time_t lasttime = 0;


};

