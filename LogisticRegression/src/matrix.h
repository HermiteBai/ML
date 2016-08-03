#ifndef _MATRIX_
#define _MATRIX_

#include <cstdio>
#include <vector>

class Matrix
{
public:
	Matrix(std::size_t width, std::size_t weight);
	Matrix(std::vector<Data> dataSet);
	Matrix(const Matrix& mat);
	virtual ~Matrix();

	std::size_t getWidth()const;
	std::size_t getHeight()const;

	Matrix& operator+(const Matrix& mat)const;
	Matrix& operator-(const Matrix& vec)const;
	Matrix& operator=(const Matrix& vec)const;
	void operator+=(const Matrix& vec);
	void operator-=(const Matrix& vec);
	Matrix& operator*(double a)const;
	void operator*=(double a);
	double operator*(const const Matrix& vec)const;
	double* operator[](std::size_t index);
	void transpose();
	Matrix& covMat()const;

private:
	double** coordinates;
	std::size_t width;
	std::size_t height;

	std::vector<double> sample(std::size_t n)const;
	static double cov(std::vector<double> vec1, std::vector<double> vec2)const;
	static double average(std::vector<double> vec)const;
};

#endif