#include <iostream>
#include <memory>

class Singleton {
public:
    // Static member function to get the instance of the singleton
    static std::shared_ptr<Singleton> getInstance() {
        // Check if the instance already exists
        if (!instance) {
            // If not, create a new instance
            instance = std::shared_ptr<Singleton>(new Singleton());
        }
        // Return the instance
        return instance;
    }

    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }

private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Private copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static pointer to hold the instance of the singleton
    static std::shared_ptr<Singleton> instance;
};

// Initialize the static member instance
std::shared_ptr<Singleton> Singleton::instance = nullptr;

int main() {
    // Get the singleton instance
    std::shared_ptr<Singleton> singleton = Singleton::getInstance();

    // Use the singleton object
    singleton->showMessage();

    return 0;
}
