#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    
    try {
        if (num2 == 0) {
            throw runtime_error("Division by zero error");
        }
        double result = static_cast<double>(num1) / num2;
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error &e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
