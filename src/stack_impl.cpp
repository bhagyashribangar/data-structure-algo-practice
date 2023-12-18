// Implementation of stack using array
// Last in first out

#include <iostream>
using namespace std;

class Stack {
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stsck overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Cannot pop as stack is empty" << endl;
            return;
        }
        --top;
    }

    int getTop() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        for (int i = 0; i <= top ; ++i) {
            cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << "Stack elements: ";
    stk.display();


    cout << "Top element of stack is: " << stk.getTop() << endl;

    stk.pop();
    cout << "Stack elements are after deleting: ";
    stk.display();

    return 0;
}