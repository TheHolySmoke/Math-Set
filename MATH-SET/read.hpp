//Author:    Gregorics Tibor
//Date:     2015.02.22.
//Title:    Universal reading from keyboard

#pragma once

#include <iostream>
#include <string>

template <typename Int>
int read( const std::string &msg, const std::string &err, bool valid(int))
{
    int n;
    bool wrong;
    do{
        std::cout << msg;
        std::cin >> n;
        if((wrong = std::cin.fail())) std::cin.clear();
        std::string tmp = "";
        getline(std::cin, tmp);
        wrong = wrong || tmp.size()!=0 || !valid(n);
        if(wrong) std::cout << err << std::endl;
    }while(wrong);
    return n;
}
