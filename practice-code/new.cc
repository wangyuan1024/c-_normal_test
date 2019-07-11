/*************************************************************************
*     File Name: new.cc
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Wed 10 Jul 2019 01:03:19 AM PDT
************************************************************************/
#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void test0()
{
    int * p1 = new int(10);
    cout << "p1 = " << *p1 << endl;
    delete p1;

    int * p2 = new int[10]();
    cout << "p2 = " << *p2 << endl;
    for(int i = 0;i < 10; ++i)
    {
        cout << "p2 = " << p2[i] << endl;
    }
    delete [] p2;
}

int main()
{
    test0();
    return 0;
}

