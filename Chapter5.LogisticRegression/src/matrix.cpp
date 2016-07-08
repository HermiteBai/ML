#include "math_vector.h"
#include "matrix.h"

Matrix::Matrix(std::size_t width, std::size_t height)
{
	rows = new Math_vector[height];
	for (int i = 0; i < height; i++)
	{
		rows[i] = new Math_vector(width);
	}
}

Matrix::Matrix(const Matrix& mat)const
{
	this->rows = new Math_vector[height];
	for (int i = 0; i < height; i++)
	{
		this->rows[i] = mat[i];
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < height; i++)
	{
		delete rows[i];
	}
	delete[] rows;
}

Matrix& Matrix::operator+(const Matrix& mat)const
{
	Matrix ret;
	for (int i = 0; i < height; i++)
	{
		ret[i] = (*this)[i] + mat[i];
	}
	return ret;
}

Matrix& Matrix::operator-(const Matrix& vec)const
{
	Matrix ret;
	for (int i = 0; i < height; i++)
	{
		ret[i] = (*this)[i] - mat[i];
	}
	return ret;
}

Matrix& Matrix::operator=(const Matrix& vec)const
{
	for (int i = 0; i < height; i++)
	{
		(*this)[i] = mat[i];
	}
}

void Matrix::operator+=(const Matrix& vec)
{
	for (int i = 0; i < height; i++)
	{
		(*this)[i] += mat[i];
	}
}

void Matrix::operator-=(const Matrix& vec)
{
	for (int i = 0; i < height; i++)
	{
		(*this)[i] -= mat[i];
	}
}

Matrix& Matrix::operator*(double a)const
{
	Matrix ret;
	for (int i = 0; i < height; i++)
	{
		ret[i] = (*this)[i] * a;
	}
	return ret;
}

void Matrix::operator*=(double a)
{
	for (int i = 0; i < height; i++)
	{
		(*this)[i] *= mat[i];
	}
}

Matrix& Matrix::operator*(const Matrix& vec)const
{
	if (this->width != vec.height)
	Matrix ret;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			for (int k = 0; k < width; k++)
			{

				(((ret.rows)[j]).coordinates)[i] += (*this)[j][k] * vec[k][j];
			}
		}
	}
	return ret;
}

Math_vector Matrix::operator[](std::size_t index)
{
	return rows[index];
}


