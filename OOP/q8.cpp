#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b;

    return 0;
}