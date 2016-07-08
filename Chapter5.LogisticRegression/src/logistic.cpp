#include <iostream>
#include <cmath>
#include <vector>
#include "logistic.h"
#include "matrix.h"



double sigmoid(double x)
{
	return 1.0 / (1 + exp(x));
}

Matrix gradAscent(std::vector<Data> dataSet)
{
	Matrix dataMat(dataSet.size(), dataSet[0].parameters.size());
	Matrix labels(1, dataSet.size());
	double alpha = 0.001;
	int maxCycle = 500;
	Matrix weights(dataSet[0].parameters.size(), 1);
	for (int i = 0; i < maxCycle; i++)
	{
		double h = sigmoid((dataMat * weights)[0][0]);
		Matrix hMat(1, dataSet.size());
		for (int j = 0; j < dataSet.size(); j++)
		{
			hMat[j][0] = h;
		}
		Matrix error = (labels - hMat);
		weights = weights + alpha * dataMat.transpose() * error;
	}
	return weights;
}



