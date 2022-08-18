#include "Set.h"
#include "menu.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

    using namespace std;

    vector<int> vec;
    Set::Set()
    {
        vec = {};
    }
    void Set::ins(int a)
    {
        vec.push_back(a);
        sort(vec.begin(),vec.end());
        vec.erase( unique(vec.begin(), vec.end()), vec.end());
    }

    void Set::rem(int a)
    {
        for(int i = 0 ; i < vec.size() ; i++)
        {
            if( a == vec[i])
            {
                vec.erase(vec.begin() + i);
            }
        }
    }

    bool Set::isEmpty()
    {
        return vec.size()==0;
    }

    bool Set::contain(int a)
    {
        for(int i = 0 ; i < vec.size() ; ++i)
        {
            if(vec[i]==a)
            {
                return true;
                break;
            }
        }
        return false;
    }

    int Set::random()throw (SetError)
    {
        if(vec.size()==0) throw EMPTY_SET;
        srand((unsigned)time(0));
        int result =(rand() % vec.size());
        return vec[result];
    }

    int Set::max()throw (SetError)
    {
        if(vec.size()==0) throw EMPTY_SET;
        int ind=0;
        for(unsigned i=1; i<vec.size(); ++i)
        {
            if(vec[i]>vec[ind])
            {
                ind=i;
            }
        }
        return vec[ind];
    }

    ostream& operator<<(std::ostream& s, const Set& q)
    {
        s<<"\n*******************************************\n";
        s<<"Number of elements: "<<q.vec.size()<<"\nContent: "<<endl;
        for(unsigned i=0; i<q.vec.size(); ++i)
            {
            s<<" "<<q.vec[i]<<" ";
            }
        s<<"\n*******************************************\n\n";
    return s;
    }

    vector<int> Set::getItems() const
{
    vector<int> v;
    for(unsigned i=0; i<vec.size(); ++i)
        v.push_back(vec[i]);
    return v;
}

