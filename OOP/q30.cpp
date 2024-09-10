#include <iostream>
using namespace std;

class A
{
};

class B
{
};

class C
{
};

class D : public A, public virtual B
{
};

class E : public C, public virtual B
{
};

class F : public D, public E
{
};

int main()
{

    return 0;
}