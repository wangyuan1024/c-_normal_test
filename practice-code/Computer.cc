/*************************************************************************
*     File Name: Computer.cc
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Thu 11 Jul 2019 12:02:32 AM PDT
************************************************************************/
#pragma once
#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

class Computer
{
public:
    Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(char * ,double)" << endl;
        _totalprice+=_price;
    }

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout << "Computer(const Computer &)" << endl;
        _totalprice+=_price;
    }

    Computer & operator=(const Computer & rhs)
    {
        cout << "Computer & operator=(const Computer &)" << endl;
        if(this!=&rhs)
        {
            delete [] _brand;
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand,rhs._brand);
            this->_price = rhs._price;
        }
        _totalprice+=_price;
        return *this;
    }

    void print() const
    {
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

    ~Computer()
    {
        delete [] _brand;
        cout << "~Computer()" << endl;
    }

    static void printTotalPrice()
    {
        cout <<"Total Price:" << _totalprice << endl;
    }
private:
    char * _brand;
    double _price;
    static double _totalprice;
};

double Computer::_totalprice = 0;

void test0()
{
    Computer pc1("matebook",1111);
    cout << "pc1: " << endl;
    pc1.print();
    Computer pc2 = pc1;
    pc2.print();
    Computer pc3("thinkpad",2222);
    pc3.print();
    pc3 = pc1;
    pc3.print();
    Computer::printTotalPrice();
}

int main()
{
    test0();
    Computer::printTotalPrice();
    return 0;
}

