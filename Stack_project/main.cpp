#include <iostream>
#include "StackHeader.h"
#include "StackFunction.cpp"
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
    MyStack s(3);
    cout << "Empty stack created! :)\n\nusing top(): ";
    cout << s.top();
    cout << " <-- WTF? Stack is empty!\n";

    cout << "s[2]=" << s[2];
    cout << " <-- WTF? Stack is still empty!\n";

    cout << "s[11]=" << s[3];
    cout << " <-- OMG :(\n\n";

    s.push(22); s.push(33); s.push(44);
    cout << "Added 3 values..\n";
    cout << "size=" << s.getSize();
    cout << " <-- Why size=6? We've pushed only 3 values :(!\n";

    cout << "\nPushing 10 more..\n";
    s.push(22); s.push(33); s.push(44);
    s.push(22); s.push(33); s.push(44);
    s.push(22); s.push(33); s.push(44);
    s.push(22);
    cout << "\Alright, it's full:)\n";
    cout << "\nLet's pop everything .\n";
    s.pop(); s.pop(); s.pop(); s.pop();
    s.pop(); s.pop(); s.pop(); s.pop();
    s.pop(); s.pop(); s.pop(); s.pop();
    s.pop(); s.pop(); s.pop();
    cout << "15 values popped.\n";
    cout << "The next pop will crash the program :(((( ....\n";
    s.pop(); // -________________________-

    return 0;
}


