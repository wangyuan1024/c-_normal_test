/*************************************************************************
*     File Name: const.cc
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Wed 10 Jul 2019 12:22:24 AM PDT
************************************************************************/
#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void test0()
{
    //const int num0;//error,常量必须初始化
    const int num = 1;
    //num = 2;//error,无法修改
    cout << ">> n = " << num << endl;
}

void test1()
{
    int num1 = 1;
    int num2 = 2;
    const int * p1 = &num1;
    p1 = &num2;
    cout << "p1 = " << *p1 << endl;
    //*p1 = 3;
    int * const p2 = &num1;
    *p2 = 4;
    cout <<"num1 = " << num1 <<endl;
}

int main()
{
    test1();
    return 0;
}

