#include "CPlane.h"

CPlane::CPlane(float nX, float nY) {
    NormalX = nX;
    NormalY = nY;

    ColShape = new CColPlane(&X, &Y, NormalX, NormalY);

    MaxSpeedX = MaxSpeedY = 0.0f;

    InvMass = 0.0f;
}

CPlane::~CPlane() {
    delete ColShape;
}
