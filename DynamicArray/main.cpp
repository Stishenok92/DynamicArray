#include "array.h"
#include "stack.h"



int main()
{
    Stack s1(20);
    
    
    
//    Stack stack(15);
//    Array* ptr = &array;
    
    std::ifstream fin("Text.txt");
    
    if (!fin)
    {
        std::cout << "File not found\n";
    }
    
    fin >> s1;
//    ptr->print();
    s1.menu();
    
    
    system("pause");
    return 0;
}
