// Implementation of dynamic array
// Vector is a dynamic array in c++
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* array;
    size_t size;
    size_t capacity;
public:
    DynamicArray() : array(nullptr), size(0), capacity(0) {}

    // copy constructor
    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) {
        array = new int[capacity];
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }

    // move constructor
    DynamicArray(DynamicArray&& other) noexcept : array(other.array), size(other.size), capacity(other.capacity) {
        other.array = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] array;
            size = other.size;
            capacity = other.capacity;
            array = new int[capacity];
            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            } 
        }
        return *this;
    }

    // move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] array;
            array = other.array;
            size = other.size;
            capacity = other.capacity;
            other.array = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    void pushBack(int value) {
        if (size == capacity) {
            // If the array is full, double its capacity
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* newArray = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        array[size++] = value;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    int operator[](size_t index) const {
        if (index < size) {
            return array[index];
        } else {
            cout << "Index out of bound" << endl;
            return -1;
        }
    }

    ~DynamicArray() {
        delete[] array;
    }
};

int main()
{
    DynamicArray da;
    da.pushBack(2);
    da.pushBack(3);
    da.pushBack(4);
    da.pushBack(5);
    da.pushBack(6);

    /*for (int i = 0; i < 10; ++i) {
        da.pushBack(i * 2);
    }*/

    cout << "Size of array is: " << da.getSize() << endl;
    cout << "Capacity of array is: " << da.getCapacity() << endl;

    cout << "Dynamic Array Elements: ";
    for(size_t i = 0; i < da.getSize(); ++i) {
        cout << da[i] << " ";
    }

    return 0;
}