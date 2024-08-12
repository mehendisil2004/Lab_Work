#include<bits/stdc++.h>
using namespace std;

void Strcpy(char a[50], char b[50]) {
    int i=0;
    while ((a[i] = b[i]) != '\0') {
        i++;
    }
}

int main() {
    char a[] = "Hello World";
    char b[50];

    Strcpy(b, a);

    cout << a << endl;
    cout << b << endl;

    return 0;
}