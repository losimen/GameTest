// GameTest by losimen 20.01.2023

#ifndef GAMETEST_VECTOR2D_H
#define GAMETEST_VECTOR2D_H

#include <iostream>


class Vector2D
{
public:
    float x;
    float y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& add(const Vector2D& vec);
    Vector2D& subtract(const Vector2D& vec);
    Vector2D& multiply(const Vector2D& vec);
    Vector2D& divide(const Vector2D& vec);

    friend Vector2D& operator+(Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator-(Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator*(Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator/(Vector2D& vec1, const Vector2D& vec2);

    Vector2D operator+=(const Vector2D& vec);
    Vector2D operator-=(const Vector2D& vec);
    Vector2D operator*=(const Vector2D& vec);
    Vector2D operator/=(const Vector2D& vec);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};

#endif //GAMETEST_VECTOR2D_H
