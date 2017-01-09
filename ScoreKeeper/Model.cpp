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

	return diff;
}


void Model::AddScore(int score, char* player)
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