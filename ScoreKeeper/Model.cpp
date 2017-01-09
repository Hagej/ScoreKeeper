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