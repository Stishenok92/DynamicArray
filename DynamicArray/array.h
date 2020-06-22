#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

class Array
{
protected:
    size_t size;
    int* arr;
public:
    Array(): size(0), arr(nullptr) {}
    Array(size_t temp_size): size(temp_size), arr(new int[size]) {}
    Array(const Array &temp_arr);
    Array& operator=(const Array&);
    friend std::istream& operator>> (std::istream&, Array&);
    friend std::ostream& operator<< (std::ostream&, const Array&);
    virtual void print() const;
    ~Array() { delete[]arr; }
    
};

Array:: Array(const Array &temp)
{
    size = temp.size;
    delete[]arr;
    arr = new int[size];
    memcpy(arr, temp.arr, sizeof(arr)*size);
}

Array& Array:: operator=(const Array& temp)
{
    size = temp.size;
    delete[]arr;
    arr = new int[size];
    memcpy(arr, temp.arr, sizeof(arr)*size);
    return *this;
}

std::istream& operator>>(std::istream& in, Array& temp)
{
    size_t count = 0;
    
    while (!in.eof())
    {
        in >> temp.arr[count++];
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Array& temp)
{
    for (size_t i = 0; i < temp.size; i++)
    {
        out << temp.arr[i] << " ";
    }
    
    return out;
}

void Array:: print() const
{
    std::cout << arr;
}
