#include "StackHeader.h"
#include <assert.h>
#include <iostream>

#define ASSERT_OK()                         \
    if (!ok())                              \
    {                                       \
        damp();                             \
        assert(0);                          \
    }                                       \


MyStack::MyStack(const unsigned int _size): size_(_size)
{
    ASSERT_OK();
}

void MyStack::damp()
{
    std::cout << "maximum_size =" << reserve_ << std::endl;

    std::cout << "current_size =" << getSize()<< std::endl;
}


float& MyStack::operator[](const unsigned int _n)
{
    ASSERT_OK();

    return Data[_n];
}

void MyStack::clr()
{

    size_ = 0;
}

MyStack::~MyStack()
{
    clr();
}

void MyStack::push(float _value)
{
    ASSERT_OK();

    if (size_+1 > reserve_)
    {
        std::cout << "You can't push the new value" << std::endl;
        assert(0);
    }

    Data [size_++] = _value;
    ASSERT_OK();
}

bool MyStack::empty()
{
    ASSERT_OK();

    if (size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyStack::pop()
{
    ASSERT_OK();

    unsigned int new_size = size_ - 1;

    float *pNewData = new float[size_ - 1];

    for (unsigned int i=0; i < size_ - 1; i++)
    {
        pNewData[i] = Data[i];
    }

    clr();

    size_ = new_size;
    for (unsigned int i=0; i < size_; i++)
    {
       Data[i] = pNewData[i];
    }
}
