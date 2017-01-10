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
	void AddScore(const std::string& player); // addera poängen
	int getScore(const std::string& player); // få poängen

private:

//	char* hej = "hej"
	int m_Kajsa = 0, m_Johan = 0;
	time_t now;
	double diff;
	time_t lasttime = 0;


};

