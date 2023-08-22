// Effective C++条款07
class TimeKeeper
{
public:
    TimeKeeper();
    ~TimeKeeper();
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

int main()
{
    TimeKeeper *ptk = getTimeKeeper(); //从TimeKeeper继承体系获得一个动态分配对象。
    
    delete ptk; //释放它，避免资源泄露。
}