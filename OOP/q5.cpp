#include <bits/stdc++.h>
using namespace std;

int main() {
    int fah;
    double cel;
    
    for (fah=0; fah<=100; fah++)
    {
        cel = (5.0/9.0)*(fah - 32);
        cout << fah << " = " << cel << endl;
    }
    

    return 0;
}