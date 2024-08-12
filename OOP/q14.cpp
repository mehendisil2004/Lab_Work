#include<bits/stdc++.h>
using namespace std;

void print(const int vector[], int size) {
    for (int i=0; i<size; ++i) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

void print(const int matrix[][3], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for(int j=0; j<col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }  
    cout << endl; 
}

int main() {
    int vector[]= {1, 3, 5, 7, 9};

    int matrix[2][3] = {{2, 5, 6}, {4, 9, 1}};

    cout << "Matrix:" << endl;
    print(matrix, 2, 3);
    cout << "Vector:" << endl;
    print(vector, 5);
}