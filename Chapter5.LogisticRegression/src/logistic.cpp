#include <iostream>
#include <cmath>
#include <vector>
#include "logistic.h"
#include "math_vector.h"
#include "matrix.h"

double sigmoid(double x)
{
	return 1.0 / (1 + exp(x));
}

Math_vector gradAscent(std::vector<Data> dataSet)
{
	double alpha = 0.001;
	int maxCycles = 500;
	Matrix dataMat(dataSet.size(), dataSet.front().dim());
	for (int i = 1; i < dataSet.size(); i++)
	{
		dataMat[i] = dataSet[i].coordinates;
	}
	Math_vector weights(dataSet.front().dim());
	for (int i = 0; i < weights.dim(); i++)
	{
		weights[i] = 1.0;
	}
	for (int i = 0; i < maxCycles; i++)
	{
		int h = sigmoid(dataSet * weights);

	}
}