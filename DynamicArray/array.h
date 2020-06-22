#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

const size_t def = 10; //размер массива по умолчанию

class Array
{
protected:
    size_t size;
    int* arr;
public:
    Array(): size(def), arr(new int[size] {0}) {}
    Array(size_t temp_size): size(temp_size), arr(new int[size] {0}) {}
    Array(const Array&);
    Array& operator=(const Array&);
    friend std::istream& operator>> (std::istream&, Array&);
    friend std::ostream& operator<< (std::ostream&, const Array&);
    virtual void print() const;
    ~Array() { delete[]arr; }
};

Array:: Array(const Array &temp)
{
    size = temp.size;
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
        if (count > temp.size)
        {
            std::cout << "No free space\n";
            return in;
        }
        
        in >> temp.arr[count++];
    }

    return in;
}


std::ostream& operator<<(std::ostream& out, const int* temp)
{
//    for (size_t i = 0; i < temp.size; i++)
//    {
        out << temp;
//    }
    
    return out;
}

void Array:: print() const
{
    std::cout << *this;
}


