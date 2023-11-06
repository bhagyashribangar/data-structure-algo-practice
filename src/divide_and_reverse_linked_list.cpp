#include <iostream>
using namespace std;

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

    void insertElements(int val);
    void printList();
    void divideandReverse(int val);
    Node* reverseSubGroup(Node* node, int subGroupSize, Node* &nextGroup);
};

void LinkedList::insertElements(int val) {
    Node* node = new Node(val);
    if (head == nullptr) {
        head = node;
        return;
    } else {
        node->next = head;
        head = node;
    }
}

Node* LinkedList::reverseSubGroup(Node* node, int subGroupSize, Node* &nextGroup) {
    Node* currNode = node;
    Node* previous = nullptr;
    Node* next = nullptr;
    int count = 0;
    while (currNode != nullptr && count < subGroupSize) {
        next = currNode->next;
        currNode->next = previous;
        previous = currNode;
        currNode = next;
        count++;
    }
    nextGroup = currNode;
    return previous;
}

void LinkedList::divideandReverse(int k) {
    Node* currNode = head;
    int count = 0;

    while (currNode != nullptr) {
        count++;
        currNode = currNode->next;
    }

    currNode = head;

    int subGroupSize = count/k;
    Node* next = nullptr;
    Node* newHead = nullptr;
    Node* prevTail = nullptr;
    while (currNode != nullptr) {
        Node* subGroupHead = reverseSubGroup(currNode, subGroupSize, next);
        if (newHead == nullptr) {
            newHead = subGroupHead;
            prevTail = currNode;
        } else {
            prevTail->next = subGroupHead;
        }

        currNode = next;
    }

    head = newHead;
}

void LinkedList::printList() {
    Node* currNode = head;

    if (head == nullptr) {
        cout << "Empty linked list" << endl;
        return;
    }

    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
}

int main()
{
    LinkedList list;
    list.insertElements(5);
    list.insertElements(6);
    list.insertElements(20);
    list.insertElements(4);
    list.insertElements(14);
    list.insertElements(70);

    list.printList();

    int k = 2;
    list.divideandReverse(k);
    cout << "\n";
    list.printList();

    return 0;
}