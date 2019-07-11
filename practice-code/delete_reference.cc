/*************************************************************************
*     File Name: delete_reference.cc
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Wed 10 Jul 2019 01:10:22 AM PDT
************************************************************************/
#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void test1()
{
    int num = 1;
    int & ref = num;
    cout << "ref = " << ref << endl;
    int num2 = 2;
    ref = num2;
    cout << "ref = " << ref << endl;
    cout << "num = " << num << endl;
}

int & func()
{
    int *p = new int(1);
    return *p;
}

void test0()
{
    int &ref = func();
    cout << "ref = " << ref << endl;
    delete &ref;
    cout << "ref = " << ref << endl;
}

int main()
{
    test1();
    return 0;
}

