#include <iostream>
#include <vector>
#include "Set.h"
#include "menu.h"

#define NORMAL_MODE
#ifdef NORMAL_MODE

using namespace std;

int main()
{
    cout << "Set" << endl;

    Menu menu;
    menu.Run();


    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"



TEST_CASE("isEmpty()","[Set]")
{
    Set Q1;
    CHECK( Q1.isEmpty() == TRUE );

    int e = 1;
    Q1.ins(e);
    CHECK( Q1.isEmpty() == FALSE );

    Q1.rem(e);
    CHECK( Q1.isEmpty() == TRUE );
}

TEST_CASE("add","[Set]")
{
    Set Q;
    int e1 = 1;
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;

    {
        Q.ins(e1);
        vector<int> v= Q.getItems();
        CHECK( 1 == Q.getLength());
        CHECK( v[0] == e1);
    }

    {
        Q.ins(e2);Q.ins(e3);Q.ins(e4);Q.ins(e5);
        CHECK( 5 == Q.getLength());
        vector<int> v= Q.getItems();
        CHECK( v[1] == e2); CHECK(v[2] == e3); CHECK(v[3] == e4); CHECK(v[4] == e5);
    }
}

TEST_CASE("max","[max] [Set]")
{
    ///maxindex and remMax
    SECTION("Exception Throws")
    {
        Set Q;
        CHECK_THROWS(Q.max());

    }

    ///Items for testing
    int e;
    int e1 = 1;
    int e2 = 2;
    int e3 = 3;
    int e5 = 5;
    SECTION("one item")
    {
        Set Q;
        Q.ins(e1);
        e=Q.max();
        CHECK( e == e1 );
        Q.rem(e1);
        CHECK( 0 == Q.getLength());
    }


    SECTION("more items, first is maximal")
    {
        Set Q;
        Q.ins(e5); Q.ins(e2); Q.ins(e3);
        e=Q.max();
        CHECK( e == e5 );
        Q.rem(e5);
        CHECK( 2 == Q.getLength());
        CHECK( e == e5 );
        vector<int> v=Q.getItems();
        CHECK(v[0]==e2); CHECK(v[1]==e3);
    }

    SECTION("more items, last is maximal")
    {
        Set Q;
        Q.ins(e1); Q.ins(e2); Q.ins(e3);

        e=Q.max();
        CHECK( e == e3 );
        Q.rem(e3);
        CHECK( 2 == Q.getLength());
        CHECK( e == e3 );
        vector<int> v=Q.getItems();
        CHECK(v[0]==e1); CHECK(v[1]==e2);
    }

    SECTION("more items, middle is maximal")
    {
        Set Q;
        Q.ins(e1); Q.ins(e3); Q.ins(e2);
        e=Q.max();
        CHECK( e == e3 );
        Q.rem(e3);
        CHECK( 2 == Q.getLength());
        CHECK( e == e3 );
        vector<int> v=Q.getItems();
        CHECK(v[0]==e1); CHECK(v[1]==e2);
    }

}
TEST_CASE("random","[random] [Set]")
{
    int e;
    int e1 = 1;
    int e2 = 2;
    int e3 = 3;
    int e5 = 5;
    SECTION("one item")
    {
        Set Q;
        Q.ins(e1);
        e=Q.random();
        CHECK( e == e1 );
        Q.rem(e1);
        CHECK( 0 == Q.getLength());
    }

    SECTION("many item")
    {
        Set Q;
        Q.ins(e1); Q.ins(e3); Q.ins(e2);Q.ins(e5);
        e=Q.random();

        CHECK( Q.contain(e) );
    }
}

#endif
