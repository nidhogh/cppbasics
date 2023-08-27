#include <string>

class C1
{
public:
    C1();
    virtual ~C1();
    virtual void f1();
    virtual int f2(char c) const;
    virtual void f3(const std::string &s);
    void f4() const;
};

class C2 : public C1 {
public:
    C2();                       // 非虚函数
    virtual ~C2();              // 重新定义的虚函数
    virtual void f1();          // 重新定义的虚函数
    virtual void f5(char *str); // 新的虚函数
};