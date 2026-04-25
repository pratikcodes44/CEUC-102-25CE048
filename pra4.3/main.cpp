#include "Dynamic.h"
#include <iostream>

using namespace std;

int main()
{
    int n,m;

    cout<<"Enter The Size of First Array  ";
    cin>>n;

    cout<<"Enter The Size of Second Array  ";
    cin>>m;

    Dynamic D(n,m);

    D.inputdata();
    D.mergedata();

    D.display();

    return 0;
}
