#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <time.h>

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
int diff;
time_t lasttime = 0;


};

