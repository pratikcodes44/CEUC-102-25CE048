#include "shape.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(double l, double w)
{
    length=l;
    width=w;
}

double Rectangle::Area()
{
    return length * width;
}

void Rectangle::display()
{
    cout<<"Shape   : Rectangle"<<endl;
    cout<<"Length  : "<<length<<endl;
    cout<<" Width  : "<<width<<endl;
    cout<<"Area    : "<<Area()<<endl;
}

Circle::Circle(double r)
{
    radius = r;
}

double Circle::Area()
{
    return PI * radius * radius;
}

void Circle::display()
{
    cout<<"Shape  : Circle"<<endl;
    cout<<"Radius : "<<radius<<endl;
    cout<<"Area   : "<<Area()<<endl;
}
