#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    int fac=1;
    for(int i=1;i<=n;i++) {
        fac=fac*i;
    }
    return fac;
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n);

    return 0;
}