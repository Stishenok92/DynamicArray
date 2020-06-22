#include "array.h"
#include "stack.h"



int main()
{
    
    
    Stack array(5);
        std::ifstream fin("Text.txt");
    
        if (!fin)
        {
            std::cout << "File not found\n";
        }
    
        fin >> array;
    
    array.menu();
    
//    Stack stack(5);
    
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
    
//    stack.pop();
//    stack.push(1);
//    stack.push(2);
//    stack.push(3);
//    stack.push(4);
//    stack.push(5);
//    stack.push(6);
//    stack.print();
//    std::cout << stack.pop() << "\n";
//    std::cout << stack.pop() << "\n";
//    std::cout << stack.pop() << "\n";
//    std::cout << stack.pop() << "\n";
//    std::cout << stack.pop() << "\n";
//    std::cout << stack.pop() << "\n";
    
    
    system("pause");
    return 0;
}
