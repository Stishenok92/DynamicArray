#pragma once
#include "array.h"

class Stack : public Array
{
private:
    size_t top;
    
    bool isEmpty() const;
    bool isFull() const;
public:
    Stack(): Array(def), top(0) {}
    Stack(size_t temp_size) : Array(temp_size), top(0) {}
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    ~Stack() {}
    void push(const int);
    int pop();
    friend std::istream& operator>> (std::istream&, Stack&);
    friend std::ostream& operator<< (std::ostream&, const Stack&);
    void print() const;
    void menu();
};

Stack:: Stack(const Stack &temp)
{
    size = temp.size;
    top = temp.top;
    arr = new int[size];
    memcpy(arr, temp.arr, sizeof(arr)*size);
}

Stack& Stack:: operator=(const Stack& temp)
{
    size = temp.size;
    top = temp.top;
    delete[]arr;
    arr = new int[size];
    memcpy(arr, temp.arr, sizeof(arr)*size);
    return *this;
}

bool Stack:: isEmpty() const
{
    return (top == 0) ? true : false;
}

bool Stack:: isFull() const
{
    return (top == size) ? true : false;
}

void Stack:: push(const int key)
{
    if (!isFull())
    {
        arr[top++] = key;
    }
    else
    {
        std::cout << "Stack is full!\n";
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
        std::cout << "Stack is empty!\n";
        return 0;
    }
}

std::istream& operator>> (std::istream& in, Stack& stack)
{
    int temp;
    
    while (!in.eof())
    {
        if (stack.isFull())
        {
            std::cout << "Stack is full!\n";
            return in;
        }
        
        in >> temp;
        stack.push(temp);
    }
    
    return in;
}

void Stack:: print() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty!\n";
        return;
    }
    
    for (size_t i = 0; i < top; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << "\n";
}

void Stack:: menu()
{
    while (true)
    {
        std::cout << "\nОperations:\n"
        << "1. Print\n"
        << "2. Push\n"
        << "3. Pop\n"
        << "0. Exit\n"
        << "\nEnter operation: ";
        size_t choise;
        std::cin >> choise;
        
        switch (choise)
        {
            case 0:
            {
                return;
            }
            case 1:
            {
                print();
                break;
            }
            case 2:
            {
                int num;
                std::cout << "Enter number: ";
                std::cin >> num;
                push(num);
                break;
            }
            case 3:
            {
                pop();
                break;
            }
            default:
            {
                std::cout << "No such operation\n";
            }
        }
    }
}
