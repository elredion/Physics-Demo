#include "CColShape.h"

CColRectangle::CColRectangle() {
    X = NULL;
    Y = NULL;

    Width = 0;
    Height = 0;
}

CColRectangle::CColRectangle(float* eX, float* eY, int W, int H) {
    X = eX;
    Y = eY;

    Width = W;
    Height = H;
}

float CColRectangle::FindCenterX() {
    float CenterX = *Entity.X + ((float) Entity.Width) / 2;

    return CenterX;
}

float CColRectangle::FindCenterY() {
    float CenterY = *Entity.Y - ((float) Entity.Height) / 2;

    return CenterY;
}

int CColRectangle::getHeight() {
    return Height;
}

int CColRectangle::getWidth() {
    return Width;
}
