// k'th element from last is: (Number of nodes - k) + 1
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
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insert(int val);
    void printList();
    int kthElementFromLast(int k);
};

void LinkedList::insert(int val) {
    Node* node = new Node(val);
    if (head == nullptr) {
        head = node;
        return;
    } else {
        node->next = head;
        head = node;
    }
}

void LinkedList::printList() {
    Node* currNode = head;

    if (head == nullptr) {
        cout << "Empty linked list" << endl;
        return;
    }

    cout << "Traversed Linked list is: " << endl;
    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
}

int LinkedList::kthElementFromLast(int k) {
    Node* i = head;
    Node* j = head;

    for (int x = 0; x < k; ++x) {
        j = j->next;
    }

    while (j != nullptr) {
        i = i->next;
        j = j->next;
    }

    return i->data;
}

int main() {
    LinkedList list;

    list.insert(5);
    list.insert(6);
    list.insert(12);
    list.insert(20);
    list.insert(25);
    list.insert(30);

    list.printList();

    int k = 3;
    int kthElementFromLast = list.kthElementFromLast(k);

    cout << "\nk'th element from last of list is: " << kthElementFromLast;

    return 0;

}
