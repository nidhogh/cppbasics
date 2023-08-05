#include <cstring>

class String
{
public:
    // 默认构造函数
    String() : data(nullptr), length(0) {}

    // 构造函数
    String(const char *str)
    {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // 拷贝构造函数
    String(const String &other)
    {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // 移动构造函数
    String(String &&other) noexcept
    {
        length = other.length;
        data = other.data;
        other.length = 0;
        other.data = nullptr;
    }

    // 拷贝赋值运算符
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // 移动赋值运算符
    String &operator=(String &&other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = other.data;
            other.length = 0;
            other.data = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~String()
    {
        delete[] data;
    }

    // 获取字符串长度
    size_t size()
    {
        return length;
    }

    // 获取C风格字符串
    const char *c_str()
    {
        return data;
    }

private:
    char *data;
    size_t length;
};

int main()
{
    return 0;
}