#include <iostream>
#include <cmath>
#include "logistic.h"
#include "math_vector.h"

double sigmoid(double x)
{
	return 1.0 / (1 + exp(x));
}

Math_vector gradAscent(list<Data> dataSet)
{
	double alpha = 0.001;
	int maxCycles = 500;
	Math_vector weights(dataSet.front().dim());
	for (int i = 0; i < weights)
	for (int i = 0; i < maxCycles; i++)
	{
		int h = sigmoid(dataSet * weights);

	}
}