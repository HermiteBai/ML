#ifndef _LOGISTIC_
#define _LOGISTIC_

#include <iostream>
#include <list>
#include <vector>
#include "math_vector.h"
typedef struct Data
{
	vector<double> parameters;
	double kind;
}Data;

double sigmoid(double x);

Math_vector gradAscent(list<Data> dataSet);

#endif