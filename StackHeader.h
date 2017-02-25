#ifndef STACKHEADER_H_INCLUDED
#define STACKHEADER_H_INCLUDED

class MyStack
{
private:

    static const int reserve_ = 100;

    float Data[reserve_];
    unsigned int size_;

    MyStack(){};

    void clr();

public:

    MyStack(const unsigned int _size);
    float& operator[](const unsigned int _n);
    int getSize(){return size_;}
    float top(){return Data[size_ - 1];}

    void pop();
    void push(float _value);
    bool empty();
    bool ok(){return (size_ <= reserve_);}
    void damp();
    ~MyStack();
};

#endif // STACKHEADER_H_INCLUDED
