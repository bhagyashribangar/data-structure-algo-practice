// LRU cache implementation to inset key values
// Implementing using Doubly linked list and Hashmap(unordered map)

#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    std::unordered_map<int, Node*> cache;
    // most recently used
    Node* head;
    // least recently used
    Node* tail;
    int capacity;

    void moveToFront(Node* node) {
        if (node == head) {
            return;
        }

        if (node->prev) {
            node->prev->next = node->next;
        }
        if(node->next) {
            node->next->prev = node->prev;
        }

        node->prev = nullptr;
        node->next = head;

        if (head) {
            head->prev = node;
        }
        head = node;

        if (!tail) {
            tail = node;
        }
    }

    void removeTail() {
        if (tail) {
            cache.erase(tail->key);
            Node* temp = tail;
            if (tail->prev) {
                tail->prev->next = nullptr;
                tail = tail->prev;
            } else {
                head = tail = nullptr;
            }
            delete temp;
        }
    }

public:
    LRUCache(int c) : head(nullptr), tail(nullptr), capacity(c) {}

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            moveToFront(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            moveToFront(cache[key]);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            moveToFront(newNode);

            if (cache.size() > capacity) {
                removeTail();
            }
        }
    }

    void printCache() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "(" << current->key << ", " << current->value << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};

int main()
{
    LRUCache cache(3);
    cache.put(1, 2);
    cache.put(2, 3);
    cache.put(2, 6);
    std::cout << "Value at key 2 is: " << cache.get(2) << std::endl;

    //cache.put(4, 3);
    //cache.put(5, 4);
    std::cout << "Value at key 3 is: " << cache.get(3) << std::endl;
    cache.printCache();
    return 0;
}