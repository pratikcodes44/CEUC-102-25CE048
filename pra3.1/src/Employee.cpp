#include "Employee.h"
#include <iostream>
#include<string>

using namespace std;

Employee :: Employee(string x,int y, int z)
{
    name=x;
    bsalary=y;
    bonus=z;
}

void Employee :: showdata()
{
    cout<<"Employee Name: "<<name<<endl;
    cout<<"Basic Salary: "<<bsalary<<endl;
    cout<<"Bonus: "<<bonus<<endl;
    cout<<"Total Salary"<<totalsalary()<<endl;
}
