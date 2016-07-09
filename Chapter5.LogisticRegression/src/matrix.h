#ifndef _MATRIX_
#define _MATRIX_

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

private:
	double** coordinates;
	std::size_t width;
	std::size_t height;
};

#endif