#ifndef _VECTOR_
#define _VECTOR_


class Math_vector
{
public:
	Math_vector(std::size_t dim);
	Math_vector(const Math_vector& vec);
	virtual ~Math_vector();

	Math_vector& operator+(const Math_vector& vec)const;
	Math_vector& operator-(const Math_vector& vec)const;
	Math_vector& operator=(const Math_vector& vec)const;
	void operator+=(const Math_vector& vec);
	void operator-=(const Math_vector& vec);
	Math_vector& operator*(double a)const;
	void operator*=(double a);
	double operator*(const Math_vector& vec)const;
	double operator[](std::size_t index);
private:
	double* coordinates;
	std::size_t dim;
	std::size_t dim();
};


#endif