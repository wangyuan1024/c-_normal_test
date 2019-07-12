/*************************************************************************
*     File Name: TestMylogger.cc
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Fri 12 Jul 2019 11:26:17 AM CST
************************************************************************/
#pragma once
#include "Mylogger.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void test()
{
    LogError("请求产生错误，请纠正。");
    LogWarn("请求产生错误，请纠正。");
}

int main()
{
    test();
    Mylog::Mylogger::getInstance()->destroy();
    return 0;
}

