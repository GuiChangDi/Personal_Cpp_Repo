//Using Cpp class to define stack
#pragma once
typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;//index for stack position
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() return false if stack already full, true otherwise.
    bool push(const Item & item);
    // pop() return false if stack already empty, true otherwise.
    bool pop(Item & item);
    Stack operator+(const Stack & s) const;
};