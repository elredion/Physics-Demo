#include "vector2d.h"
#include <cmath>

Vector2D::Vector2D() : X_(0), Y_(0)
{

}

Vector2D::Vector2D(float X, float Y) : X_(X), Y_(Y)
{

}

Vector2D::Vector2D(const Vector2D& v)
{
    X_ = v.X_;
    Y_ = v.Y_;
}

Vector2D& Vector2D::operator=(const Vector2D& v)
{
    if (this != &v)
    {
        X_ = v.X_;
        Y_ = v.Y_;
    }

    return *this;
}

void Vector2D::SetX(float X)
{
    X_ = X;
    return;
}

void Vector2D::SetY(float Y)
{
    Y_ = Y;
    return;
}

float Vector2D::GetX() const
{
    return X_;
}

float Vector2D::GetY() const
{
    return Y_;
}

float Vector2D::Mag() const
{
    float Mag;
    Mag = sqrt(X_ * X_ + Y_ * Y_);
    return Mag;
}

float Vector2D::MagSquare() const
{
    float Mag;
    Mag = X_ * X_ + Y_ * Y_;
    return Mag;
}

float Vector2D::Theta() const
{
   // float Theta = atan2(Y_/X_);
   // return Theta;
   return 0;
}

Vector2D Vector2D::Unit() const
{
    Vector2D Unit = *this / Mag();
    return Unit;
}

float Vector2D::Cross(const Vector2D& v) const
{
    float Cross = X_*v.Y_ - Y_*v.X_;
    return Cross;
}

float Vector2D::Dot(const Vector2D& v) const
{
    float Dot = X_*v.X_ + Y_*v.Y_;
    return Dot;
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
    return Vector2D((X_ + v.X_),(Y_ + v.Y_));
}

Vector2D Vector2D::operator-(const Vector2D& v) const
{
    return Vector2D((X_ - v.X_),(Y_ - v.Y_));
}

Vector2D Vector2D::operator*(const float& s) const
{
    return Vector2D((X_ * s),(Y_ * s));
}

Vector2D Vector2D::operator/(const float& s) const
{
    return Vector2D((X_ / s),(Y_ / s));
}

Vector2D Vector2D::operator+=(const Vector2D& v)
{
    X_ += v.X_;
    Y_ += v.Y_;
    return *this;
}

Vector2D Vector2D::operator*=(const float& s)
{
    X_ *= s;
    Y_ *= s;
    return *this;
}

bool Vector2D::operator==(const Vector2D& v) const
{
    if(X_ == v.X_ && Y_ == v.Y_) return true;
    else return false;
}

bool Vector2D::operator!=(const Vector2D& v) const
{
    return !(*this == v);
}
