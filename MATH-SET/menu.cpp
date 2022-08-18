#include "menu.h"
#include <iostream>
#include "read.hpp"
#include <sstream>
#define menuCount 8

using namespace std;

bool check(int a){return a>=0 && a<=menuCount;}
bool checktwo(int a){return a * 1 == a;}

void Menu::Run()
{
    int v;
    do{
        v=MenuPrint();
        switch(v)
        {
            case 1:
                addNum();
                print();
                break;
            case 2:
                remNum();
                print();
                break;
            case 3:
                max();
                print();
                break;
            case 4:
                isEmpty();
                print();
                break;
            case 5:
                randNum();
                print();
                break;
            case 6:
                containNum();
                print();
                break;
            case 7:
                print();
                break;
            default:
                cout<<"\nGoodbye!\n";
                break;

        }
    }while(v!=0);
}

int Menu::MenuPrint()
{
    int choice;
    cout<<"\n ----------------------------------------\n";
    cout<<"| 0. Exit                                |\n";
    cout<<"| 1. Add Number                          |\n";
    cout<<"| 2. remove Number                       |\n";
    cout<<"| 3. maximum Element                     |\n";
    cout<<"| 4. Is empty?                           |\n";
    cout<<"| 5. random Number                       |\n";
    cout<<"| 6. Contain?                            |\n";
    cout<<"| 7. Print Elements                      |\n";
    cout<<" ----------------------------------------\n";

    ostringstream s;
    s<<"choose a number between 0 and "<<menuCount<<"!";
    string errmsg=s.str();

    choice = read<int>("Choose a menuitem: ",errmsg,check);

    return choice;
}

void Menu::addNum()
{
    int e;


    e=read<int>("Number:","Integer is needed!",checktwo);

    Q.ins(e);
}

void Menu::remNum()
{
    int e;
    cout<<"Number:\n";
    cin >> e;
    Q.rem(e);
}

void Menu::isEmpty()
{
    if(Q.isEmpty())
        cout<<"The Set is empty.\n";
    else
        cout<<"The Set is not empty.\n";
}

void Menu::randNum()
{
    int e;
    bool error=false;
    try{
        e=Q.random();
    }catch(Set::SetError err)
    {
        error=true;
        if(err==Set::EMPTY_SET)
            cerr<<"Random Element can not be given as the Set is empty.\n";
        else
            cerr<<"Unknown error.\n";
    }
    if (!error) cout<<"Random element is:\n"<<e<<endl;
}

void Menu::containNum()
{
    int e;
    cout<<"Number:\n";
    cin >> e;
    if(Q.contain(e))
        cout<<"The set contains element " << e <<endl;
    else
        cout<<"The set does not contain element " << e <<endl;
}

void Menu::max()
{
    int e;
    bool error=false;
    try{
        e=Q.max();
    }catch(Set::SetError err)
    {
        error=true;
        if(err==Set::EMPTY_SET)
            cerr<<"Maximum cannot be checked as the Set is empty.\n";
        else
            cerr<<"Unknown error.\n";
    }
    if (!error) cout<<"Maximal element is:\n"<<e<<endl;
}

void Menu::print()
{
    cout<<Q;
}

