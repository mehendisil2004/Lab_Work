#include <iostream>
using namespace std;

class MyClass {
public:
    class MyException {
    private:
        const char* description;
    public:
        MyException(const char* desc) : description(desc) {}
        const char* what() const { return description; }
    };

    void riskyFunction() throw(MyException) {
        throw MyException("An error occurred in riskyFunction!");
    }
};

int main() {
    MyClass obj;
    
    try {
        obj.riskyFunction();
    }
    catch (const MyClass::MyException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
