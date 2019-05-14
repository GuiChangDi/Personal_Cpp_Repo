/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
**/
#include <iostream>
#include <string.h>

bool isValid(char *s)
{
    int length = 0;
    while(*(s+length))  length++;
    char *a = (char*)malloc(sizeof(length/2+1));

    int top = -1;
    for(int i = 0;i<length;i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            a[top++] = s[i];
        else if(s[i] == ')')
        {
            if(a[top] == '(')
                a[--top] = '\0';
            else 
                return false;
        }

        else if(s[i] == ']')
        {
            if(a[top] == '[')
                a[--top] = '\0';
            else
                return false;
        }

        else if(s[i] == '{')
        {
            if(a[top] == '}')
                a[--top] = '\0';
            else
                return false;
        }
    }
    if(top == -1)
        return true;
    return false;
}