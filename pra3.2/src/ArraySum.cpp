#include "ArraySum.h"
#include <iostream>

using namespace std;

ArraySum::ArraySum(int s)
{
    size = s;
    arr = new int[size];
}

ArraySum::~ArraySum()
{
    delete[] arr;
}

void ArraySum::inputElements()
{
    for(int i=0;i<size;++i)
    {
        cin>>arr[i];
    }
}

long long ArraySum::iterativeSum()
{
    long long sum = 0;

    for(int i=0;i<size;++i)
    {
        sum+=arr[i];
    }
    return sum;
}

long long ArraySum::recursiveSum(int index)
{
    if(index<0)
    {
        return 0;
    }
    return arr[index]+recursiveSum(index-1);
}

int ArraySum::getSize()
{
    return size;
}
