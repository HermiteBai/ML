#include "matrix.h"

//Constructor
Matrix::Matrix(std::size_t width, std::size_t weight)
{
	coordinates = new double*[height]();
	for (int i = 0; i < height; i++)
	{
		coordinates[i] = new double[width]();
	}
}

Matrix::Matrix(std::vector<Data> dataSet)
{
	coordinates = new double*[height]();
	for (int i = 0; i < height; i++)
	{
		coordinates[i] = new double[width]();
		for (int j = 0; j < width; j++)
		{
			coordinates[i][j] = ((dataSet[i]).parameters)[j];
		}
	}
}

Matrix::Matrix(const Matrix& mat)
{
	coordinates = new double*[height];
	for (int i = 0; i < height; i++)
	{
		coordinates[i] = new double[width];
		for (int j = 0; j < width; j++)
		{
			coordinates[i][j] = mat[i][j];
		}
	}
}

//Destructor
Matrix::~Matrix()
{
	for (int j = 0; j < width; j++)
	{
		delete coordinates[i];
	}
	delete[] coordinates;
}

//Access to member attributes

std::size_t Matrix::getWidth()const
{
	return width;
}

std::size_t Matrix::getHeight()const
{
	return height;
}

//Basic Operations
Matrix& Matrix::operator+(const Matrix& mat)const
{
	Matrix ret;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ret[i][j] = (*this)[i][j] + mat[i][j];
		}
	}
	return ret;
}

Matrix& Matrix::operator-(const Matrix& vec)const
{
	Matrix ret;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ret[i][j] = (*this)[i][j] - mat[i][j];
		}
	}
	return ret;
}

Matrix& Matrix::operator=(const Matrix& vec)const
{
	if (*this == mat)
		return *this;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			(*this)[i][j] = mat[i][j];
		}
	}
	return *this;
}

void Matrix::operator+=(const Matrix& vec)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			(*this)[i][j] += mat[i][j];
		}
	}
}

void Matrix::operator-=(const Matrix& vec)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			(*this)[i][j] -= mat[i][j];
		}
	}
}

Matrix& Matrix::operator*(double a)const
{
	Matrix ret;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ret[i][j] = (*this)[i][j] * a;
		}
	}
	return ret;
}

void Matrix::operator*=(double a)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			(*this)[i][j] *= mat[i][j];
		}
	}
}

double Matrix::operator*(const const Matrix& vec)const
{
	Matrix ret;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			for (int k = 0; k < width; k++)
			{
				ret[j][i] += (*this)[j][k] * mat[k][j];
			}
		}
	}
	return ret;
}

double* Matrix::operator[](std::size_t index)
{
	return coordinates[index];
}

Matrix& Matrix::transpose()
{
	Matrix ret(height, width);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ret[i][j] = (*this)[j][i];
		}
	}
	return ret;
}

std::vector<double> Matrix::sample(std::size_t n)
{
	std::vector<double> ret;
	for (int i = 0; i < dim; i++)
	{
		ret.push_back((this*)[i][n]);
	}
	return ret;
}

Matrix& Matrix::covMat()const
{
	std::size_t dim = width;
	std::size_t size = height;
	Matrix ret(dim, dim);
	for (std::size_t i = 0; i < dim; i++)
	{
		for (std::size_t j = 0; j < dim; j++)
		{
			ret.coordinates[j][i] = cov(sample(j), sample(i));
		}
	}
	return ret;
}

static double Matrix::cov(std::vector<double> vec1, std::vector<double> vec2)const
{
	std::size_t size = vec.size();
	double sum = 0;
	double average1 = average(vec1);
	double average2 = average(vec2);
	for (std::size_t i = 0; i < vec1.size(); i++)
	{
		sum += (vec1[i] - average1) * (vec2[i] - average2);
	}
	return sum;
}

static double Matrix::average(std::vector<double> vec)const
{
	double sum = 0;
	for (double num : vec)
	{
		sum += num;
	}
	return sum / vec.size();
}
