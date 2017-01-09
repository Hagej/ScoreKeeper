#include "stdafx.h"
#include "theGame.h"
#include <time.h>
#include <string>
#include <iostream>
using namespace std;

theGame::theGame()
{
}


theGame::~theGame()
{
}

int theGame::CalculateScore()
{	
	now = time(NULL);
	diff = difftime(lasttime, now);
	lasttime = now; 

	cout << diff << "days";

	return diff;
}


void theGame::AddScore(int score, char* player)
{

	if (player == "Johan")
	{
		m_Johan = score;
	}
	else
	{
		m_Kajsa = score;
	}
	
}