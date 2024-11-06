#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    try {
        if (num2 == 0) {
            throw 0; 
        }
        if (num2 < 0) {
            throw string("Negative divisor error");  
        }

        double result = static_cast<double>(num1) / num2;
        cout << "Result: " << result << endl;
    }
    catch (int e) {
        cout << "Exception caught: Division by zero (error code " << e << ")" << endl;
    }
    catch (string &e) {
        cout << "Exception caught: " << e << endl;
    }

    return 0;
}
