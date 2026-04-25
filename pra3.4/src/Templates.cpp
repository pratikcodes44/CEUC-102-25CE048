#include "Templates.h"
#include <iostream>
#include<string>

using namespace std;
int i;

template <typename T>
T Max(T arr[], int size)
{
    T maxValue=arr[0];
    for(i=1; i<size; i++)
    {
        if(arr[i]>maxValue)
        {
            maxValue=arr[i];
        }
    }
    return maxValue;
}

template <typename T>
void Reverse(T arr[], int size)
{
    int start=0;
    int end=size-1;

    while(start<end)
    {
        T temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start++;
        end--;
    }
}

template <typename T>
void display(T arr[], int size)
{
    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout <<endl;
}

template int Max<int>(int arr[], int size);
template void Reverse<int>(int arr[], int size);
template void display<int>(int arr[], int size);

template double Max<double>(double arr[], int size);
template void Reverse<double>(double arr[], int size);
template void display<double>(double arr[], int size);

template char Max<char>(char arr[], int size);
template void Reverse<char>(char arr[], int size);
template void display<char>(char arr[], int size);
