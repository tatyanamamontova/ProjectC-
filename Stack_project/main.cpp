#include <iostream>
#include "StackHeader.h"
#include <assert.h>

//using namespace std;
#define ASSERT_EQ(condition) \
    if(!condition){          \
        std::cout << "-";    \
        assert(0);           \
    }                        \



#define TEST(Function)      \
    if(Function)            \
    {                       \
        std::cout << "+";   \
    }                       \

bool PushSingleNumber(float value)
{
    MyStack s;
    s.push(value);
    ASSERT_EQ(s.top() == value);
    s.pop();
    ASSERT_EQ(s.getSize() == 0);
    return true;
}

bool CannotPushMore()
{
    MyStack s;
    for (int i = 0; i< s.getReserve(); i++)
    {
        s.push(100+i);
    }
    ASSERT_EQ(s.push(1488) == false);
    return true;
}

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

    new_stack.push(100500);
    std::cout << "\n"<<new_stack.top()<<std::endl;
    new_stack.damp();

    TEST(PushSingleNumber(100));
    return 0;
}


