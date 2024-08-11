#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, fac=1;
    
    for (int i = 1; i <= 6; i++)
    {
        fac *= i;
        cout << i << "! = " << fac << endl;
    }
    

    return 0;
}