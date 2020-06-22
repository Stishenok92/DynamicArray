#include "array.h"
#include "stack.h"

int main()
{
    Stack stack(5);
    
//    std::ifstream fin("Text.txt");
//
//    if (!fin)
//    {
//        std::cout << "File not found\n";
//    }
//
//    while (!fin.eof())
//    {
//        fin >> array;
//    }
//
//    std::cout << array;
    
    stack.pop();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    std::cout << stack.pop();
    std::cout << stack.pop();
    std::cout << stack.pop();
    std::cout << stack.pop();
    
    
    system("pause");
    return 0;
}
