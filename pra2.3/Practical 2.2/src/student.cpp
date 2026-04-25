#include "student.h"
#include <iostream>
#include<string>

using namespace std;

void student :: get_stu_details()
{
    cout<<"Enter Student Name: ";
    cin>>name;
    cout<<"Enter The Student ID: ";
    cin>>ID;
    cout<<"Enter Maths Mark: ";
    cin>>m1;
    cout<<"Enter Physics Mark: ";
    cin>>m2;
    cout<<"Enter CCP Mark: ";
    cin>>m3;
    cout<<endl;
}

int student :: calc_avg(int x)
{
    if(ID==x)
    {
        avg=(m1+m2+m3)/3;
        cout<<"AVG Of The Student is: "<<avg<<endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
