// Implement linked list

#include <iostream>
using namespace std;

// Represent NOde of a linked list
class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBegin(int val);
    void insertAtMid(int val, int position);
    void insertAtEnd(int val);

    void deleteFromBegin();
    void deleteFromEnd();
    void deleteFromMid(int position);

    //Return position of searched element
    int searchElement(int val);
    void reverseList();

    void printList();
};

void LinkedList::insertAtBegin(int val) {
    Node* node = new Node(val);
    if (head == nullptr) {
        head = node;
        return;
    } else {
        node->next = head;
        head = node;
    }
}

void LinkedList::insertAtMid(int val, int position) {
    if (position < 1) {
        cout << "Invalid position: " << position << endl;
        return;
    }

    if(position == 1) {
        return insertAtBegin(val);
    }

    Node* node = new Node(val);
    Node* currNode = head;
    int currPosition = 1;
    while (currNode != nullptr && currPosition < position - 1) {
        currNode = currNode->next;
        currPosition++;
    }
    if (currNode == nullptr) {
        cout << "Invalid position: " << position << endl;
        delete node;
    } else {
        node->next = currNode->next;
        currNode->next = node;
    }
}

void LinkedList::insertAtEnd(int val) {
    Node* node = new Node(val);
    if (head == nullptr) {
        head = node;
    } else {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = node;
    }
}

void LinkedList::deleteFromBegin() {
    if (head == nullptr) {
        cout << "\nCannot delete as list is empty" << endl;
    } else {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

void LinkedList::deleteFromEnd() {
    if (head == nullptr) {
        cout << "\nCannot delete as list is empty" << endl;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* currNode = head;
        Node* previous = nullptr;
        while (currNode->next != nullptr) {
            previous = currNode;
            currNode = currNode->next;
        }

        delete currNode;
        previous->next = nullptr;
    }
}

void LinkedList::deleteFromMid(int position) {
    if (position < 1 || head == nullptr) {
        cout << "\nCannot delete as position is invalid or list is empty" << endl;
    } else if (position == 1) {
        return deleteFromBegin();
    } else {
        Node* currNode = head;
        Node* previous = nullptr;
        int currPosition = 1;
        while (currNode != nullptr && currPosition < position) {
            previous = currNode;
            currNode = currNode->next;
            currPosition++;
        }
        if (currNode == nullptr) {
            cout << "Invalid position: " << position << endl;
        } else {
            previous->next = currNode->next;
            delete currNode;
        }
    }
}

int LinkedList::searchElement(int val) {
    Node* currNode = head;
    int position = 1;
    while (currNode != nullptr) {
        if (currNode->data == val) {
            cout << "\nElement found at position: " << position << endl;
            return position;
        }
        currNode = currNode->next;
        position++;
    }
    return -1;
}

void LinkedList::reverseList() {
    Node* currNode = head;
    Node* previous = nullptr;
    Node* next = nullptr;
    while (currNode != nullptr) {
        next = currNode->next;
        currNode->next = previous;
        previous = currNode;
        currNode = next;
    }
    head = previous;
}

void LinkedList::printList() {
    Node* currNode = head;

    if (head == nullptr) {
        cout << "Empty linked list" << endl;
        return;
    }

    //cout << "Traversed Linked list is: " << endl;
    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
}

int main() {
    LinkedList list;

    list.insertAtBegin(6);
    list.insertAtBegin(4);
    list.insertAtBegin(8);
    list.insertAtMid(10,2);
    list.insertAtMid(30,4);
    list.insertAtEnd(20);
    list.insertAtEnd(40);

    cout << "Linked list after inserting data: ";
    list.printList();

    list.deleteFromBegin();
    //list.deleteFromBegin();
    list.deleteFromEnd();
    //list.deleteFromEnd();
    list.deleteFromMid(2);

    cout << "\nLinked list after deleting data: ";
    list.printList();

    list.reverseList();
    cout << "\nLinked list after reversal: ";
    list.printList();

    list.searchElement(6);
    list.searchElement(20);

    return 0;
}