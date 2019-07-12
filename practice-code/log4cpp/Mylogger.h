/*************************************************************************
*     File Name: Mylogger.h
*     Author: WangYuan
*     mail: 853283581@qq.com
*     Created Time: Fri 12 Jul 2019 10:49:08 AM CST
************************************************************************/
#pragma once

#include <log4cpp/Category.hh>

using namespace log4cpp;

namespace Mylog
{

class Mylogger
{
public:
    static Mylogger* getInstance();
    static void destroy();

    void error(const char * msg);
    template<class... Args>
    void error(Args... args)
    {
        _root.error(args...);
    }

    void warn(const char * msg);
    void info(const char * msg);
    void debug(const char * msg);

private:
    Mylogger();
    ~Mylogger();

private:
    static Mylogger * _pInstance;
    Category & _root;
};
}

#define prefix(msg) string("[").append(__FILE__)\
        .append(":").append(__FUNCTION__)\
        .append(":").append(std::to_string(__LINE__))\
        .append("]").append(msg).c_str()

#define LogError(msg, ...) Mylog::Mylogger::getInstance()->error(prefix(msg), ##__VA_ARGS__)
//#define LogError(msg) Mylog::Mylogger::getInstance->error(prefix(msg))
#define LogWarn(msg) Mylog::Mylogger::getInstance()->warn(prefix(msg))
#define LogInfo(msg) Mylog::Mylogger::getInstance()->info(prefix(msg))
#define LogDebug(msg) Mylog::Mylogger::getInstance()->debug(prefix(msg))
