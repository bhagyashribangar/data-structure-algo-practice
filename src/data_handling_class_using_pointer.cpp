// Implement a class which contains a pointer as its private member variable
#include <iostream>
using namespace std;

class Demo {
    int* data;
public:
    Demo() : data(nullptr) {}
    Demo(int val) {
        data = new int(val);
        cout << "Parameterized constructor" << endl;
    }

    Demo (const Demo& obj) : data(nullptr) {
        if (obj.data != nullptr) {
            data = new int(*(obj.data));
        }
        cout << "Copy constructor" << endl;
    }

    Demo (Demo&& obj) noexcept : data(obj.data) {
        obj.data = nullptr;
        cout << "Move constructor" << endl;
    }

    Demo& operator=(const Demo& obj) {
        if (obj.data != nullptr) {
            data = new int(*(obj.data));
        } else {
            data = nullptr;
        }
        cout << "Copy assignment operator" << endl;
        return *this;
    }

    Demo& operator=(Demo&& obj) noexcept {
        if (this != &obj) {
            delete data;
            data = obj.data;
            obj.data = nullptr;
        }
        cout << "Move assignment operator" << endl;
        return *this;
    }

    int getValue() {
        if (data != nullptr) {
            return *data;
        } else {
           return 0;
        }
    }

    void setData(int val) {
        if (data != nullptr) {
            delete data;
        }
        data = new int(val);
    }

    ~Demo() {
        delete data;
        data = nullptr;
    }
};

int main()
{
    // Test different types of constructors
    Demo obj1;      //Default constructor
    Demo obj2(20);   //Parameterized constructor
    cout << "Initial Value of obj1 is: " << obj1.getValue() << endl;
    cout << "Initial Value of obj2 is: " << obj2.getValue() << endl;
    Demo obj3 = obj2;   //Copy constructor
    cout << "Initial Value of obj2 after copying is: " << obj2.getValue() << endl;
    Demo obj4 = move(obj2);     //Move constructor

    cout << "Value of obj1 is: " << obj1.getValue() << endl;
    cout << "Value of obj2 is: " << obj2.getValue() << endl;
    cout << "Value of obj3 is: " << obj3.getValue() << endl;
    cout << "Value of obj4 is: " << obj4.getValue() << endl;

    // Test assignment operators
    Demo obj5;
    obj5 = obj3;   //Assignment operator
    Demo obj6;
    obj6 = move(obj4);  //Move assignment operator

    cout << "Value of obj5 is: " << obj5.getValue() << endl;
    cout << "Value of obj6 is: " << obj6.getValue() << endl;

    obj6.setData(30);
    cout << "Value of obj6 after setting new value is: " << obj6.getValue() << endl;

    return 0;
}
