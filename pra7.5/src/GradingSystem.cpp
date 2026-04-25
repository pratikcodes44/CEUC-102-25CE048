#include "GradingSystem.h"
#include <iostream>

using namespace std;

GradingSystem::GradingSystem(string name, double m)
{
    studentName=name;
    marks=m;
}

double GradingSystem::getMarks()
{
    return marks;
}

void GradingSystem::display()
{
    cout<<"Name  : "<<studentName<<"\nMarks : "<<marks<<"\n";
}

Undergraduate::Undergraduate(string name, double m) : GradingSystem(name, m)
{

}

char Undergraduate::computeGrade()
{
    double m = getMarks();

    if(m >= 80)
    {
        return 'A';
    }
    if(m >= 60)
    {
        return 'B';
    }
    if(m >= 40)
    {
        return 'C';
    }
    return 'F';
}

void Undergraduate::display()
{
    cout<<"Undergraduate Record \n";
    GradingSystem::display();

    cout<<"Grade : "<<computeGrade()<<"\n";
}

Postgraduate::Postgraduate(string name, double m) : GradingSystem(name, m)
{

}

char Postgraduate::computeGrade()
{
    double m = getMarks();
    if(m >= 90)
    {
        return 'A';
    }
    if(m >= 70)
    {
        return 'B';
    }
    if(m >= 50)
    {
        return 'C';
    }
    return 'F';
}

void Postgraduate::display()
{
    cout<<"Postgraduate Record\n";
    GradingSystem::display();

    cout<<"Grade : "<<computeGrade()<<"\n";
}
