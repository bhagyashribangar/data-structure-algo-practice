#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void createLoop(Node* head, int pos) {
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    Node* loopStart = head;
    for (int i = 0; i < pos; ++i) {
        loopStart = loopStart->next;
    }

    tail->next = loopStart;
}

void detectAndRemoveLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // loop is detected in linked list
            break;
        }
    }

    if (slow != fast) {
        cout << "No loop detected in the linked list.\n";
        return;
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    //head->next->next->next->next = head->next->next;

    createLoop(head, 2);

    detectAndRemoveLoop(head);
    cout << "Linked List after Loop Removal: ";
    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
