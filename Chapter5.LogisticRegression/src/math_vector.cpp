#include "vector.h"

Math_vector::Math_vector(std::size_t dim)
{
	coordinates = new double[dim];
	this->dim = dim;
}

Math_vector::~Math_vector()
{
	delete[] coordinates;
}

Math_vector& Math_vector::operator+(const Math_vector& vec)const
{
	Math_vector ret;
	for (int i = 0; i < dim; i++)
	{
		ret.coordinates[i] = this->at(i) + vec.at(i);
	}
	return ret;
}

Math_vector& Math_vector::operator-(const Math_vector& vec)const
{
	Math_vector ret;
	for (int i = 0; i < dim; i++)
	{
		ret.coordinates[i] = this->at(i) - vec.at(i);
	}
	return ret;
}

void Math_vector::operator+=(const Math_vector& vec)
{
	for (int i = 0; i < dim; i++)
	{
		this->at(i) += vec.at(i);
	}
}

void Math_vector::operator-=(const Math_vector& vec)
{
	for (int i = 0; i < dim; i++)
	{
		this->at(i) -= vec.at(i);
	}
}

Math_vector& operator=(const Math_vector& vec)const
{
	if (*this == vec)
		return *this;
	Math_vector ret;
	for (int i = 0; i < dim; i++)
	{
		ret.coordinates[i] = this->at(i);
	}
	return *this;
}

Math_vector& Math_vector::operator*(double a)const
{
	Math_vector ret;
	for (int i = 0; i < dim; i++)
	{
		ret.coordinates[i] = this->at(i) * a;
	}
	return ret;
}

void Math_vector::operator*=(double a)
{
	for (int i = 0; i < dim; i++)
	{
		this->at(i) *= a;
	}
}

double Math_vector::operator*(const Math_vector& vec)const
{
	double sum = 0.0;
	for (int i = 0; i < dim; i++)
	{
		sum = this->at(i) * vet.at(i);
	}
	return sum;
}

double Math_vector::at(std::size_t num)
{
	return coordinates[num];
}

std::size_t dim()
{
	return dim;
}