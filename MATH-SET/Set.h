#ifndef SET_H
#define SET_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


class Set
{

    public:
        enum SetError{EMPTY_SET};
        Set();
        void ins(int a);
        void rem(int a);
        bool isEmpty();
        bool contain(int a);
        int max()throw (SetError);
        int random()throw (SetError);

        unsigned int getLength() const {return vec.size();}
        vector<int> getItems() const;

        friend std::ostream& operator<<(std::ostream& s, const Set& q);


    private:
        vector<int> vec;


};

#endif
