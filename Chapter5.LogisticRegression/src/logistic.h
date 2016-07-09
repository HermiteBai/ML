#ifndef _LOGISTIC_
#define _LOGISTIC_

#include <iostream>
#include <list>
#include <vector>

typedef struct Data
{
	std::vector<double> parameters;
	double kind;
}Data;

Data loadData(char* filename);

double sigmoid(double x);

Math_vector gradAscent(list<Data> dataSet);

#endif