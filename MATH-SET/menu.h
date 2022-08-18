#ifndef MENU_H
#define MENU_H
#include "Set.h"
#include "read.hpp"


class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void addNum();
        void remNum();
        void isEmpty();
        void randNum();
        void containNum();
        void max();
        void print();
        Set Q;

};

#endif // MENU_H
