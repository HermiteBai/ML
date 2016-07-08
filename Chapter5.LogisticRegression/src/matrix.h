#ifndef _MATRIX_
#define _MATRIX_

class Matrix
{
public:
	Matrix(std::size_t width, std::size_t weight);
	~Matrix();

	Matrix& operator+(const Matrix& mat)const;
	Matrix& operator-(const Matrix& vec)const;
	Matrix& operator=(const Matrix& vec)const;
	void operator+=(const Matrix& vec);
	void operator-=(const Matrix& vec);
	Matrix& operator*(double a)const;
	void operator*=(double a);
	double operator*(const const Matrix& vec)const;
	double operator[](std::size_t index);
	void transpose();

private:
	Math_vector* rows;
	std::size_t width;
	std::size_t height;
};

#endif