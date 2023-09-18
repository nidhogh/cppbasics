// class Widget {
// public:
//     //...
//     Widget& operator=(const Widget& rhs)    //返回类型是个reference，指向当前对象。
//     {
//         //...
//         return *this;   //返回左侧对象
//     }
//     //...
// };

class Widget {
public:
    //...
    Widget& operator+=(const Widget& rhs)   //这个协议适用于+=，-=，*=等等。
    {
        //...
        return *this;
    }
    Widget& operator=(int rhs)  //此函数也适用，即使此一操作符的参数类型不符协定。
    {
        //...
        return *this;
    }
    //...
};

int main()
{
    int x, y, z;
    x = y = z = 15; //赋值连锁形式
    x = (y = (z = 15));
    return 0;
}