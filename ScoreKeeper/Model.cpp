#include "stdafx.h"
#include "Model.h"
#include <time.h>
#include <string>
#include <iostream>
using namespace std;

Model::Model()
{
}


Model::~Model()
{
}

int Model::CalculateScore()
{	
	now = time(NULL);
	diff = difftime(lasttime, now);
	lasttime = now; 

	cout << diff << "days";

	return (int)diff;
}


int Model::AddScore(int score, char* player)
{

	if (player == "Johan")
	{
		m_Johan += score;
		return m_Johan;
	}
	else
	{
		m_Kajsa += score;
		return m_Kajsa;
	}
	
}

int Model::getScore(const char* player) {
		
	if (player == "Johan") {
		return m_Johan;
	}
	else {
		return m_Kajsa;
	}
	
}