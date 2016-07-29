#ifndef _BAYES_
#define _BAYES_

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <cmath>
#include <cstring>

using namespace std;

typedef struct Data
{
	map<string, double> features;
	string label;
} Data;

map<Data, map<string, double> > bayes(string label, Data target, list<Data> dataSet);

#endif