/*************************************************************************
*     File Name: Singleton.cc
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Thu 11 Jul 2019 06:36:02 AM PDT
************************************************************************/
#pragma once
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
            atexit(destory);
        }
        return _pInstance;
    }

    void print() const
    {
        cout << "data:" << _data << endl;
    }

    static void destory()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }
private:
    Singleton()
    : _data(1)
    {
        cout << "Singleton()" << endl;
    }
    
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }

private:
    int _data;
    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;

int main()
{
    Singleton * p1 = Singleton::getInstance();
    cout << p1 << endl;
    p1->print();
    Singleton * p2 = Singleton::getInstance();
    cout << p2 << endl;
    p2->print();
    return 0;
}

