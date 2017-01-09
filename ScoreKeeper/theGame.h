#pragma once
#include <ctime>
#include <iostream>

class theGame
{
public:
	theGame();
	~theGame();
	int CalculateScore(); // räkna ut poängen. 
private:

int m_Kajsa; 
int m_Johan;
std::time_t time(std::time_t* arg); // ?


};

