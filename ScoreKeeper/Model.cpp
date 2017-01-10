#include "stdafx.h"
#include "Model.h"
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// cAMILLA VILL VA MED -- REtaRd

Model::Model()
{
	ifstream myfile("data.txt");
	string line;
	vector<string> points;

	if (myfile.is_open())
	{
		while (getline(myfile, line))		// ersätt med inifil sen.
		{
			points.push_back(line);
		}
	}

	m_Kajsa = stoi(points[0]);
	m_Johan = stoi(points[1]);
}


Model::~Model()
{
}


// Make a tm structure representing this date
std::tm make_tm(int year, int month, int day)
{
	tm tm = { 0 };
	tm.tm_year = year - 1900; // years count from 1900
	tm.tm_mon = month - 1;    // months count from January=0
	tm.tm_mday = day;         // days count from 1
	return tm;
}

int Model::CalculateScore()
{	
	tm nyår = make_tm(2017, 01, 01);
	time_t n = mktime(&nyår);


	now = time(NULL);
	diff = difftime(now, n);
	lasttime = now; 

	int dagarSenNyår = (int)(diff / (3600 * 24));

	cout << diff << "days";

	return dagarSenNyår;
}


void Model::AddScore(char* player)
{
	int temp_points = CalculateScore();

	if (player == "Johan")
	{
		m_Johan = m_Johan + temp_points;
	}
	else if (player == "Kajsa")
	{
		m_Kajsa = m_Kajsa + temp_points;	
	}
	
}


int Model::getScore(const char* person)// få poängen // retunera en integer m_kajsa eller johan
{
	if (person == "Johan")
	{
		return m_Johan;
	}
	else if (person == "Kajsa")
	{
		return m_Kajsa;
	}
	else
	{
		return -1;
	}
}
