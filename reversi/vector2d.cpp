#include "vector2d.h"

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

const Vector2d Vector2d::operator+(const Vector2d& rhs)
{
    return Vector2d(x_ + rhs.x_, y_ + rhs.y_);
}

const Vector2d Vector2d::operator-(const Vector2d& rhs)
{
    return Vector2d(x_ - rhs.x_, y_ - rhs.y_);
}
