#include <iostream>
#include <vector>

using namespace std;

class Table {
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    Table(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

    friend istream& operator>>(istream& in, Table& t) {
        for (int i = 0; i < t.rows; i++) {
            for (int j = 0; j < t.cols; j++) {
                in >> t.data[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Table& t) {
        for (int i = 0; i < t.rows; i++) {
            for (int j = 0; j < t.cols; j++) {
                out << t.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    vector<int>& operator[](int index) {
        if (index < 0 || index >= rows) {
            cerr << "Index out of bounds" << endl;
            exit(1);  
        }
        return data[index];
    }

    Table& operator=(const Table& other) {
        if (this != &other) {  
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }
};

int main() {
    Table t(4, 5), t1(4, 5);
    cout << "Enter elements for 4x5 table:" << endl;
    cin >> t;

    t[0][0] = 5;  
    int x = t[2][3];  

    t1 = t;  

    cout << "Table t:\n" << t << "\n";
    cout << "Table t1:\n" << t1;

    return 0;
}
