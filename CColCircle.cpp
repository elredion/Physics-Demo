#include "CColShape.h"

CColCircle::CColCircle() {
    X = NULL;
    Y = NULL;

    Radius = 0;
}

CColCircle::CColCircle(float* eX, float* eY, float R) {
    X = eX;
    Y = eY;

    Radius = R;
}

float CColCircle::FindCenterX() {
    float CenterX = *X + Radius;

    return CenterX;
}

float CColCircle::FindCenterY() {
    float CenterY = *Y - Radius;

    return CenterY;
}

float CColCircle::getRadius() {
    return Radius;
}

bool CColCircle::Collides(CColCircle Circle) {                         // Find if distance between two circles is less than r1 + r2
    float Distance, DistanceX, DistanceY;

    DistanceX = FindCenterX() - Circle.FindCenterX();
    DistanceX *= DistanceX;

    DistanceY = FindCenterY() - Circle.FindCenterY();
    DistanceY *= DistanceY;

    Distance = sqrt(DistanceX + DistanceY);

    if(Distance < (getRadius() + Circle.GetRadius())) return true;

    return false;
}

bool CColCircle::Collides(CColPlane Plane) {
    float Distance, DistanceX, DistanceY;
    float NormalVel;

    DistanceX = FindCenterX() * Plane.getNormalX();
    DistanceX *= DistanceX;

    DistanceY = FindCenterY() * Plane.getNormalY();
    DistanceY *= DistanceY;

    Distance = sqrt(DistanceX + DistanceY);
    NormalVel =

}
