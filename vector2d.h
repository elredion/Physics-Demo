#ifndef _VECTOR2D_H_
    #define _VECTOR2D_H_

class Vector2D //Defines a 2 dimensional vector object
{
private:
    float X_;
    float Y_;

public:
    Vector2D();
    Vector2D(float X, float Y);
    Vector2D(const Vector2D& v);
    Vector2D& operator=(const Vector2D& v);

    void SetX(float X);
    void SetY(float Y);
    float GetX() const;
    float GetY() const;
    float Mag() const;
    float MagSquare() const;
    float Theta() const;
    Vector2D Unit() const;

    float Cross(const Vector2D& v) const;
    float Dot(const Vector2D& v) const;     // Z COMPONENT

    Vector2D operator+(const Vector2D& v) const;
    Vector2D operator-(const Vector2D& v) const;
    Vector2D operator*(const float& s) const;
    Vector2D operator/(const float& s) const;

    Vector2D operator+=(const Vector2D& v);
    Vector2D operator*=(const float& s);

    bool operator==(const Vector2D& v) const;
    bool operator!=(const Vector2D& v) const;
};

#endif // _VECTOR2D_H_
