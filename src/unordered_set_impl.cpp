// Implementation of unordered_set
// Internal data structure used is Hash Tables

#include <iostream>
#include <list>

class UnorderedSet {
private:
    struct Node {
        int value;
        Node(int v) : value(v) {}
    };

    // Array of linked list
    std::list<Node> buckets[10];
    size_t size;

    // hash function to map elements to indices
    size_t hashFunction(int element) const {
        return std::hash<int>{}(element) % 10;
    }
public:
    UnorderedSet() : size(0) {}

    void insert(int element) {
        size_t index = hashFunction(element);
        for (const auto& node : buckets[index]) {
            if (node.value == element) {
                return;
            }
        }
        buckets[index].emplace_back(element);
        ++size;
    }

    bool contains(int element) const {
        size_t index = hashFunction(element);
        for (const auto& node : buckets[index]) {
            if (node.value == element) {
                return true;
            }
        }
        return false;
    }

    void remove(int element) {
        size_t index = hashFunction(element);
        buckets[index].remove_if([element, this](const Node& node) { 
            if (node.value == element) {
                --size;
                return true;
            }
            return false;
        });
    }

    size_t getSize() const {
        return size;
    }
};

int main()
{
    UnorderedSet set;
    set.insert(10);
    set.insert(20);
    set.insert(30);
    set.insert(40);

    std::cout << "Size of set is: " << set.getSize() << std::endl;
    std::cout << "Contains 20: " << std::boolalpha << set.contains(20) << std::endl;

    set.remove(20);
    std::cout << "Size of set is: " << set.getSize() << std::endl;

    return 0;
}