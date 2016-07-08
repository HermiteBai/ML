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
	
}