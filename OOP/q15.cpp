#include<bits/stdc++.h>
using namespace std;

int Max(int a, int b, int c) {
    return max({a, b, c});
}

int Max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int Add(int a, int b=0, int c=0) {
    return a + b + c;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int arr[5]= {1, 5, 0, 8, 9};

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        }
        cout << Max(a, b, c) << endl;
        cout << Max(arr, 5) << endl;
        cout << Add(3) << endl;
}