// math stuff that other libraries haven't taken care of
#ifndef _2D_MATH_H
#define _2D_MATH_H

#include <cmath>

typedef unsigned int uint;

// important math constants
const float PI = 3.14159f;

// essential math functions
template <class T> 
T ABS(T n)
{
	return ( (n<0) ? -n : n);
}

int round(float f);


// essential math concepts
class Vector
{
public:

	float x, y;

	Vector(float x0,float y0):x(x0),y(y0){}
	Vector() {};

	Vector floor() { return Vector( std::floor(x), std::floor(y) ); }
	Vector Round() { return Vector( (float)round(x), (float)round(y) ); }

	float	Length() const; // Get the Vector2D's magnitude.	
	float	LengthSqr() const; // Get the Vector2D's magnitude squared.

	// Vector Transformation Functions
	void RotateVectorCounterClockwise(float angle);

	int     operator==(const Vector& rhs);
	int     operator!=(const Vector& rhs);
	Vector  operator* (const float rhs);
	Vector  operator/ (const float rhs);
	Vector&  operator*= (const float rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}
	Vector& operator*= (const Vector& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}
	Vector& operator/= (const float rhs);
	Vector  operator+ (const Vector& rhs);
	Vector& operator+=(const Vector& rhs)
	{
		x+=rhs.x;
		y+=rhs.y;
		return (*this);
	}
	Vector  operator- (const Vector& rhs);
	Vector& operator-=(const Vector& rhs);
	//Vector& operator/= (const int rhs);
	//Vector operator/ (const int rhs);
	
};

class Rectangle
{
public:

	Rectangle();
	Rectangle(size_t left, size_t top, size_t right, size_t bottom);

	~Rectangle() {}

	size_t left, top, right, bottom;

	bool Intersect(Rectangle& otherRect);
};

#endif
