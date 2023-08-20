// class HomeForSale
// {
// public:
// private:
//     HomeForSale(const HomeForSale &); // 只有声明
//     HomeForSale &operator=(const HomeForSale &);
// };

class Uncopyable
{
protected: // 允许derived对象构造和析构
    Uncopyable() {}
    ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable &); // 但阻止copying
    Uncopyable &operator=(const Uncopyable &);
};

class HomeForSale : private Uncopyable
{
};

int main()
{
    HomeForSale h1;
    HomeForSale h2;
    // HomeForSale h3(h1); // 企图拷贝h1—— 不该通过编译
    // h1 = h2;            // 企图拷贝h2—— 也不该通过编译
    return 0;
}