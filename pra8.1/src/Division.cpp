#include "Division.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Division::Division()
{
    numerator = 0;
    denominator = 0;
}

void Division::processInputAndDivide()
{
    cin.exceptions(ios_base::failbit | ios_base::badbit);

    cout<<"Enter the numerator and denominator (separated by a space): ";

    try
    {
        cin>>numerator>>denominator;

        if(denominator==0)
        {
            throw runtime_error("Division by zero is undefined.");
        }

        double result = static_cast<double>(numerator) / denominator;
        cout<<"Result: "<<result<<"\n";

    }
    catch(ios_base::failure& e)
    {
        cout<<"\n Invalid input detected! You must enter integers only.\n";
        cin.clear();
    }
    catch(runtime_error& e)
    {
        cout<<"\n Math exception: "<<e.what()<<"\n";
    }
}
