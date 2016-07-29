#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "logistic.h"
#include "matrix.h"

std::vector<Data> loadData(char* filename)
{
	FILE* filename =fopen(filename. "r");
	if (!file)
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
		return Data();
	}

	std::vector<Data> ret;
	char* buffer = NULL;
	std::size_t length = 0;
	while (getline(&buffer, &length, file) != -1)
	{
		Data data;
		data.parameters.push_back(1.0);
		char* token = strtok(buffer, "\t");
		while (!token)
		{
			data.parameters.push_back(atof(token));
		}
		ret.push_back(data);
	}
	return ret;
}

double sigmoid(double x)
{
	return 1.0 / (1 + exp(-x));
}

Matrix gradAscent(std::vector<Data> dataSet)
{
	Matrix dataMat(dataSet);
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



