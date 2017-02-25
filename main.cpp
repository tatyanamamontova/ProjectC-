#include <iostream>
#include "StackHeader.h"

//using namespace std;

int main()
{
    MyStack new_stack(10);
    for (int i = 0; i<10; i++)
    {
        new_stack[i] = i;
    }

    std::cout << new_stack.getSize()<<std::endl;
    for (int i = 0; i<10; i++)
    {
        std::cout << new_stack[i]<<" ";
    }
    std::cout << "\n"<<new_stack.top()<<std::endl;
    new_stack.pop();
    std::cout << "\n"<<new_stack.top()<<std::endl;
    new_stack.push(100500);
    std::cout << "\n"<<new_stack.top()<<std::endl;
    return 0;
}
