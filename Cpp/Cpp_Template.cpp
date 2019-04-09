#include <iostream>
using namespace std;
int main()
{
    int *a = new int;
    *a = 0; 
    cout<<a<<endl;
    cout<<*a<<endl;
    delete a;
    *a = 0;
    cout<<a<<endl;
    cout<<*a<<endl;

    int *b;
    int c = 1;
    b = &c;
    cout<<b<<endl;
    cout<<*b<<endl;

    return 0;
}