#include <string>

// Effective C++条款07
class TimeKeeper
{
public:
    TimeKeeper();
    virtual ~TimeKeeper();
    // ...
};

class AtomicClock : public TimeKeeper
{
}; // 原子钟
class WaterClock : public TimeKeeper
{
}; // 水钟
class WristWatch : public TimeKeeper
{
}; // 腕表

TimeKeeper *getTimeKeeper(); // 返回一个指针，指向一个TimeKeeper派生类的动态分配对象

class SpecialString : public std::string
{ // 馊主意！std::string有个non-virtual析构函数
    // ...
};

class AWOV {    //AWOV="Abstract w/o Virtuals"
public:
    virtual ~AWOV() = 0;    //声明pure virtual析构函数
};

AWOV::~AWOV() {}    //pure virtual析构函数的定义

int
main()
{
    TimeKeeper *ptk = getTimeKeeper(); // 从TimeKeeper继承体系获得一个动态分配对象。
    // ...
    delete ptk; // 释放它，避免资源泄露

    // SpecialString* pss = new SpecialString("Impending Doom");
    // std::string* ps;
    // ...
    // ps = pss;       //SpecialString* => std::string*
    // ...
    // delete ps;      //未有定义！现实中*ps的SpecialString资源会泄露，因为SpecialString析构函数没被调用
}