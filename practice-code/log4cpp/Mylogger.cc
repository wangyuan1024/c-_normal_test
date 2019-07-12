/*************************************************************************
*     File Name: Mylogger.cc
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Fri 12 Jul 2019 11:09:02 AM CST
************************************************************************/
#pragma once
#include "Mylogger.h"

#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

namespace Mylog
{
Mylogger * Mylogger::_pInstance = nullptr;

Mylogger * Mylogger::getInstance()
{
    if(_pInstance == nullptr)
    {
        _pInstance = new Mylogger();
    }
    return _pInstance;
}

void Mylogger::destroy()
{
    if(_pInstance)
    {
        delete _pInstance;
    }
}

void Mylogger::error(const char * msg)
{
    _root.error(msg);
}

void Mylogger::warn(const char * msg)
{
    _root.warn(msg);
}

void Mylogger::info(const char * msg)
{
    _root.info(msg);
}

void Mylogger::debug(const char * msg)
{
    _root.debug(msg);
}

Mylogger::Mylogger()
: _root(Category::getRoot().getInstance("root"))
{
    PatternLayout * ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d [%p] %m%n");

    FileAppender * fileAppender = new FileAppender("fileAppender", "log.log");
    fileAppender->setLayout(ptn1);

    _root.addAppender(fileAppender);
    _root.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    Category::shutdown();
}
}

