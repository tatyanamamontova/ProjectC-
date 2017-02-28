#include <iostream>
#include "StackHeader.h"
//#include "StackFunction.cpp"
#include <assert.h>

//using namespace std;
using std::cout;
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
    MyStack s;
    s.push(22); s.push(33); s.push(44);
    cout << "Added 3 values..\n";
    cout << "size=" << s.getSize();
    //cout << " <-- Why size=6? We've pushed only 3 values :(!\n";
    cout << "\nPushing 10 more..\n";
    s.push(22); s.push(33); s.push(44);
    s.push(22); s.push(33); s.push(44);
    s.push(22); s.push(33); s.push(44);
    s.push(22);
    cout << "\n  Alright, it's 13:)\n";
    cout << "\nLet's pop everything .\n";
    s.pop(); s.pop(); s.pop(); s.pop();
    s.pop(); s.pop(); s.pop(); s.pop();
    s.pop(); s.pop(); s.pop(); s.pop();
    s.pop();
    cout << s.getSize();
    s.pop();
    cout << "13 values popped.\n";
    TEST(PushSingleNumber(1000));
    TEST(CannotPushMore());

    return 0;
}


