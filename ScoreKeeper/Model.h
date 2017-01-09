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
	
	int CalculateScore(); // räkna ut dagarna. 
	void Model::AddScore(int, char*); // addera poängen



private:

//	char* hej = "hej"
int m_Kajsa; 
int m_Johan;
time_t now;
int diff;
time_t lasttime = 0;


};

