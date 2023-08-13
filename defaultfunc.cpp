#include <iostream>

class Empty
{
public:
    Empty() { std::cout << "default构造函数\n"; }
    Empty(const Empty &rhs) { std::cout << "copy构造函数\n"; }
    ~Empty() { std::cout << "析构函数\n"; }
    Empty &operator=(const Empty &rhs) { std::cout << "copy assignment操作符\n"; }
};

int main()
{
    Empty e1; // default构造函数
              // 析构函数
    Empty e2(e1); // copy构造函数
    e2 = e1;      // copy assignment操作符
    return 0;
}