#include "DestructorDemo.h"
#include <iostream>

using namespace std;

BadBase::BadBase()
{
    cout<<"Constructor called.\n";
}

BadBase::~BadBase()
{
    cout<<"BadBase Destructor called.\n";
}

BadDerived::BadDerived()
{
    cout<<"Bad Base Constructor called: Allocating dynamic memory.\n";
    rawPointerData = new int[100];
}

BadDerived::~BadDerived()
{
    cout<<"Destructor called: Freeing dynamic memory.\n";
    delete[] rawPointerData;
}

GoodBase::GoodBase()
{
    cout<<"GoodBase Constructor called.\n";
}

GoodBase::~GoodBase()
{
    cout<<"GoodBase Destructor called.\n";
}

GoodDerived::GoodDerived()
{
    cout<<"GoodDerived Constructor called: Allocating dynamic memory.\n";
    rawPointerData = new int[100];
}

GoodDerived::~GoodDerived()
{
    cout<<"GoodDerived Destructor called: Freeing dynamic memory.\n";
    delete[] rawPointerData;
}
