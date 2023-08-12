#include <iostream>

/// @brief Windows下没触发；Linux下(Ubuntu)可以触发outOfMem
void outOfMem()
{
    std::cerr << "Unable to satisfy request for memory\n";
    std::abort();
}

int main()
{
    std::set_new_handler(outOfMem);
    long long size = 16LL * 1024 * 1024 * 1024; // 16GB的大小
    int *pBigDataArray = new int[size];
    return 0;
}