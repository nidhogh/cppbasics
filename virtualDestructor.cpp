#include <iostream>

/*
 * 如果一个 C++ 基类的析构函数没有声明为 virtual，那么当我们通过一个基类指针删除一个派生类对象时，只会调用基类的析构函数，而不会调用派生类的析构函数。
 * 这可能导致派生类对象中的资源没有被正确释放，从而引起内存泄漏等问题。
*/

class Base
{
public:
    Base() {}
    ~Base() { std::cout << "Base destructor called" << std::endl; }
    // virtual ~Base() { std::cout << "Base destructor called" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() { std::cout << "Derived destructor called" << std::endl; }
};

int main()
{
    Base *ptr = new Derived();
    delete ptr;
    return 0;
}