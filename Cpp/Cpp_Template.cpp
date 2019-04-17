#include <iostream>
#include <vector>
#include <array>

int* test();

int main()
{
    using namespace std;
    int *b = test();
    cout<<b<<' '<<*b<<endl;
    delete b;
    cout<<b<<endl;
    return 0;
}

int* test()
{
    int* a = new int;
    *a = 1;
    std::cout<<a<<std::endl;
    return a;
}