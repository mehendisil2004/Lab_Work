#include <bits/stdc++.h>
using namespace std;

void swap(char a[], char b[]) {
    char c[50];
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
}

int main() {
    char a[50], b[50];
    
    cin.getline (a, 50);
    cin.getline (b, 50);

    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b;

    return 0;
}