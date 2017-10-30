#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2d
{
    unsigned int x_, y_;

public:
    Vector2d();
    Vector2d(unsigned int x, unsigned int y);

    const Vector2d operator+(const Vector2d& rhs);
    const Vector2d operator-(const Vector2d& rhs);
};

#endif // VECTOR2D_H
