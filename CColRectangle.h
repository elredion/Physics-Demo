#ifndef _CCOLRECTANGLE_H_
    #define _CCOLRECTANGLE_H_

#include "CColShape.h"

class CColRectangle : public CColShape {
public:
    CColRectangle();
    CColRectangle(float* eX, float* eY, int W, int H);

private:
    int Width;
    int Height;

public:
    int getWidth();
    int getHeight();

};

#endif // _CCOLRECTANGLE_H_
