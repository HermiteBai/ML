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
