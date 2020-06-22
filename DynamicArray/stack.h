#pragma once
#include "array.h"

class Stack : public Array
{
private:
    size_t top;
    
    bool isEmpty() const;
    bool isFull() const;
public:
    Stack() : Array(), top(0) {}
    Stack(size_t temp_size) : Array(temp_size), top(0) {}
    void push(const int);
    int pop();
    virtual void print() const;
};

bool Stack:: isEmpty() const
{
    return (top == 0) ? true : false;
}

bool Stack:: isFull() const
{
    return (top == size - 1) ? true : false;
}

void Stack:: push(const int key)
{
    if (!isFull())
    {
        arr[top++] = key;
    }
    else
    {
        std::cout << "Stack filled\n";
    }
}

int Stack:: pop()
{
    if (!isEmpty())
    {
        return arr[--top];
    }
    else
    {
        std::cout << "Stack empty\n";
        return 0;
    }
}

void Stack:: print() const
{
    if (isEmpty())
    {
        return;
    }
    
    for (size_t i = 0; i < top; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << "\n";
}
