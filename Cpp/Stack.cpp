#include "../Header/Stack_class.h"

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if(isfull())
        return false;
    else
    {
        items[top++] = item;
        return true;
    }
}

bool Stack::pop(Item & item)
{
    if(isempty())
        return false;
    else
    {
        item = items[--top];
        return true;
    }
}

Stack Stack::operator+(const Stack & s) const
{
    
}
