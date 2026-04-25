#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray()
{
    currentSize=0;
    arr=new int[1];
}

DynamicArray::~DynamicArray()
{
    delete[] arr;
}

void DynamicArray::insertdata(int value)
{
    arr[currentSize]=value;
    currentSize++;
}

void DynamicArray::deletedata(int index)
{
    if(index<0 || index>=currentSize)
    {
        cout<<"Error: Invalid index.\n";
        return;
    }

    for(int i=index; i<currentSize-1; i++)
    {
        arr[i]=arr[i+1];
    }

    currentSize--;
    cout<<"Element at index "<<index<<"deleted successfully.\n";
}

void DynamicArray::display()
{
    if(currentSize==0)
    {
        cout<<"The array is currently empty.\n";
        return;
    }

    cout<<"Array Contents: ";
    for(int i=0;i<currentSize;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"Current Size: "<<currentSize<<"\n";
}
