// Implementation of doubly linked list
// std::list is internally implemented as doubly linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node() {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }

    Node(int val) {
        this->data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtBegin(int data);
    void insertAtMid(int position, int data);
    void insertAtEnd(int data);
    void printList();
    void deleteFromBegin();
    void deleteFromEnd();
    void deleteNode(int data);
    bool searchElement(int value);
    int sizeofList();
    void reverseList();
};

void DoublyLinkedList::insertAtBegin(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::insertAtEnd(int data){
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void DoublyLinkedList::insertAtMid(int position, int data) {
    if (position < 1) {
        cout << "Invalid position: " << position << endl;
        return;
    }

    Node* newNode = new Node(data);
    if (position == 1) {
        insertAtBegin(data);
    } else {
        Node* currentNode = head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && currentNode != nullptr) {
                currentNode = currentNode->next;
                currentPosition++;
        }
        if (currentNode == nullptr) {
            cout << "Invalid position: " << position << endl;
            delete newNode;
            return;
        }
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        if (currentNode->next != nullptr) {
            currentNode->next->prev = newNode;
        }
        currentNode->next = newNode;
    }
}

void DoublyLinkedList::deleteFromBegin() {
    if (head == nullptr) {
        return;
    }

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
}

void DoublyLinkedList::deleteFromEnd() {
    if (head == nullptr) {
        return;
    } 

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
}

void DoublyLinkedList::deleteNode(int data) {
    Node* currentNode = head;
    while (currentNode != nullptr && currentNode->data != data) {
      currentNode = currentNode->next;
    }

    if (currentNode == nullptr) {
        return;
    }

    if (currentNode == head) {
        deleteFromBegin();
    } else if (currentNode == tail) {
        deleteFromEnd();
    } else {
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev; 
    }

    delete currentNode;
}

bool DoublyLinkedList::searchElement(int value) {
    Node* currNode = head;
    while (currNode != nullptr) {
        if (currNode->data == value) {
            return true;
        }
        currNode = currNode->next;
    }
    return false;
}

void DoublyLinkedList::reverseList() {
    Node* currNode = head;
    Node* temp = nullptr;

    while (currNode != nullptr) {
        temp = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = temp;

        currNode = currNode->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

void DoublyLinkedList::printList() {
    Node* currNode = head;

    if (currNode == nullptr) {
        cout << "Empty linked list" << endl;
        return;
    }

    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}

int DoublyLinkedList::sizeofList() {
    Node* currNode = head;
    int size = 0;
    while (currNode != nullptr) {
        size++;
        currNode = currNode->next;
    }
    return size;
}

int main()
{
    DoublyLinkedList dll;
    dll.insertAtBegin(2);
    dll.insertAtBegin(5);
    dll.insertAtBegin(4);
    //dll.deleteFromBegin();
    dll.insertAtEnd(10);
    dll.insertAtMid(2,20);
    //dll.deleteFromEnd();
    dll.deleteNode(20);
    dll.printList();
    cout << "Size of list is: " << dll.sizeofList() << endl;

    int searchValue = 5;
    cout << (dll.searchElement(searchValue) ? "Element found" : "Element not found") << endl;

    dll.reverseList();
    dll.printList();

    return 0;
}