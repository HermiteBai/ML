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
	map<string, string> features;
	string label;
} Data;

double bayes(string label, Data target);

#endif