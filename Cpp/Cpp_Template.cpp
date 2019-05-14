#include <iostream>
#include <vector>
#include <array>

template <class Type>
class Stack
{
private:
    enum {MAX = 10;};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type & item);
    bool pop(Type & item);
};

template <class Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty()
{
    return top == MAX;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

int main()
{
    
}

