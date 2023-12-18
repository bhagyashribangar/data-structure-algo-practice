// Insert integers in LRU Cache
// Implementing using Doubly linked list and Hashmap(unordered map)
#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    struct Integer {
        int number;
        Integer(int num) : number(num) {}
    };

    std::unordered_map<int, std::list<Integer>::iterator> integerMap;
    std::list<Integer> integerList;
    int capacity;

public:
    LRUCache(int cap) :  capacity(cap) {}

    // get number from integers
    Integer* getInteger(int number) {
        auto it = integerMap.find(number);
        if (it != integerMap.end()) {
            // Move the accessed number to the front of the list (most recently used)
            integerList.splice(integerList.begin(), integerList, it->second);
            // retunr pointer to Integer
            return &(*it->second);
        }
        return nullptr;
    }

    // Insert new interger in a cache
    void insertInterger(int number) {
        if (integerMap.find(number) != integerMap.end()) {
            // Number is already in the cache, move it to the front
            integerList.splice(integerList.begin(), integerList, integerMap[number]);
        } else {
            // Number is not in the cache, insert it at the front
            integerList.emplace_front(number);
            integerMap[number] = integerList.begin();

            // Remove the least recently used page if capacity is reached
            if (integerMap.size() > capacity) {
                int lastInteger = integerList.back().number;
                integerMap.erase(lastInteger);
                integerList.pop_back();
            }
        }
    }

    void printCache() {
        for (const auto& integer : integerList) {
            std::cout << integer.number << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    LRUCache cache(4);
    cache.insertInterger(3);
    cache.insertInterger(4);
    cache.insertInterger(5);
    cache.insertInterger(6);
    cache.insertInterger(5);

    cache.getInteger(2);

    cache.printCache();

    return 0;
}