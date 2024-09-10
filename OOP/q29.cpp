#include <iostream>
using namespace std;

class Base1
{
};

class Base2
{
};

class Derived : public Base1, public Base2
{
};

int main()
{
    Derived obj;

    return 0;
}