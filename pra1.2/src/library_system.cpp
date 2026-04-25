#include "library_system.h"
using namespace std;

void library_system :: add_new_book()
{
    cout<<"Enter Book ID: ";
    cin>>id;
    cout<<"Enter Book Title: ";
    cin>>title;
    cout<<"Enter Book Author: ";
    cin>>author;
    cout<<"Enter Book copies: ";
    cin>>copies;
}

int library_system :: issue_book(string x)
{
    if(title==x)
    {
        if(copies>0)
        {
            cout<<"\n Book Issue Sussesfully ";
            cout<<"\n Book ID: "<<id;
            cout<<"\n Book Title: "<<title;
            cout<<"\n Book Author: "<<author;
            cout<<"\n Available Copies: "<<copies-1<<endl;
            copies--;
        }
        else
        {
            cout<<"Insuficient Copies !!"<<endl;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int library_system :: return_book(string x)
{
    if(title==x)
    {
        cout<<"\n Book Return Sussesfully ";
        cout<<"\n Book ID: "<<id;
        cout<<"\n Book Title: "<<title;
        cout<<"\n Book Author: "<<author;
        cout<<"\n Available Copies: "<<copies+1<<endl;
        copies++;
        return 1;
    }
    else
    {
        return 0;
    }


}

void library_system :: display_book(int x)
{
    if(x==0)
    {
        cout<<"\n Library is Empty";
    }
    else
    {
            cout<<"\n Book ID: "<<id;
            cout<<"\n Book Title: "<<title;
            cout<<"\n Book Author: "<<author;
            cout<<"\n Available Copies: "<<copies<<endl;

    }
}

