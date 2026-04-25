#include "SuperDigit.h"
#include <iostream>
#include<string>

using namespace std;

int SuperDigit::calculateRecursive(long num)
{
    while(num>0)
    {
        currentSum+=num%10;
        num=num/10;
    }
    return currentSum;
}

int SuperDigit::findSuperDigit(string& n, int k)
{
    for(char digit : n)
    {
        initialSum+=(digit-'0');
    }

    initialSum*=k;

    return calculateRecursive(initialSum);
}
