// Queue implementation using linked list
// First in first out

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) :data(value), next(nullptr) {}
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Cannot dequeue as queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int getFront() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return front->data;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements are after enqueue: " << endl;
    q.display();

    cout << "Front element of queue is: " << q.getFront() << endl;

    q.dequeue();
    cout << "Queue elements are after dequeue: " << endl;
    q.display();

    return 0;
}