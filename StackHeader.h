//--------------------------------------------------
//! @file StackFunction.cpp
//! Implements a stack class
//!
//! @author Mamontova Tatyana, Feb. 2017
//--------------------------------------------------


#ifndef STACKHEADER_H_INCLUDED
#define STACKHEADER_H_INCLUDED

class MyStack
{
private:

    static const int reserve_ = 15;

    float Data[reserve_];
    unsigned int size_;


    void clr();

public:

    MyStack();
    MyStack(const unsigned int _size);
    float& operator[](const unsigned int _n);
    int getReserve(){return reserve_;}
    int getSize(){return size_;}
    float top(){return Data[size_ - 1];}

    void pop();
    bool push(float _value);
    bool empty();
    bool ok()const {return (size_ <= reserve_ && size_>=0);}
    void damp();
    void ASSERT_OK();
    ~MyStack();
};

#endif // STACKHEADER_H_INCLUDED
