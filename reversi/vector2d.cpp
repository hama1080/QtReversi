#include "vector2d.h"
#include <math.h>

Vector2d::Vector2d()
{
    x_ = 0;
    y_ = 0;
}

Vector2d::Vector2d(unsigned int x, unsigned int y)
{
    x_ = x;
    y_ = y;
}

unsigned int Vector2d::GetX()
{
	return x_;
}

unsigned int Vector2d::GetY()
{
	return y_;
}

unsigned int Vector2d::Length() const
{
	return sqrt(static_cast<double>(x_ * x_ + y_ * y_));
}


const Vector2d Vector2d::operator+(const Vector2d& rhs)
{
    return Vector2d(x_ + rhs.x_, y_ + rhs.y_);
}

const Vector2d Vector2d::operator-(const Vector2d& rhs)
{
    return Vector2d(x_ - rhs.x_, y_ - rhs.y_);
}

bool Vector2d::operator==(const Vector2d& rhs)
{
	return (x_ == rhs.x_ && y_ == rhs.y_);
}

bool Vector2d::operator!=(const Vector2d& rhs)
{
	return !(*this == rhs);
}
