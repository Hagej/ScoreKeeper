#pragma once
#include <ctime>
#include <iostream>
#include <string>

class theGame
{
public:
	theGame();
	~theGame();
	
	int CalculateScore(); // räkna ut dagarna. 
	void theGame::AddScore(int, char*); // addera poängen



private:

//	char* hej = "hej"
int m_Kajsa; 
int m_Johan;
time_t now;
double diff;
time_t lasttime = 0;


};

