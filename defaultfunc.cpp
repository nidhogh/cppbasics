#include <iostream>

class Empty
{
public:
    Empty() { std::cout << "default构造函数\n"; }
    Empty(const Empty &rhs) { std::cout << "copy构造函数\n"; }
    ~Empty() { std::cout << "析构函数\n"; }
    Empty &operator=(const Empty &rhs) { std::cout << "copy assignment操作符\n"; }
};

// template <typename T>
// class NamedObject
// {
// public:
//     NamedObject(const char *name, const T &value) {}
//     ~NamedObject(const std::string &name, const T &value) {}

// private:
//     std::string nameValue;
//     T objectValue;
// };

template <class T>
class NamedObject
{
public:
    // 以下构造函数如今不再接受一个const名称，因为nameValue
    // 如今是个reference-to-non-const string。先前那个char*构造函数
    // 已经过去了，因为必须有个string可供指涉。
    NamedObject(std::string &name, const T &value);
    //如前，假设并未声明operator=

private:
    std::string& nameValue; //这如今是个reference
    const T objectValue;    //这如今是个const
};

int main()
{
    Empty e1;     // default构造函数
                  // 析构函数
    Empty e2(e1); // copy构造函数
    e2 = e1;      // copy assignment操作符

    // NamedObject<int> no1("Smallest Prime Number", 2);
    // NamedObject<int> no2(no1); // 调用copy构造函数

    std::string newDog("Persephone");
    std::string oldDog("Satch");
    NamedObject<int> p(newDog, 2);

    NamedObject<int> s(oldDog, 36);

    // p = s;  //现在p的成员变量该发生什么事？

    return 0;
}