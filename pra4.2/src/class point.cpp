#include "point.h"

 point:: point(int x, int y)
{
    this->x=x;
    this->y=y;
}

point :: point* move(int dx, int dy)
{
    this->+=dx;
    this->+=dy;
    return this;
}

point :: updatepoint(point* p , int dx , int dy)
{
    p->move(dx,dy);

}

void point :: display()
{
    cout<<x<<y;
}


