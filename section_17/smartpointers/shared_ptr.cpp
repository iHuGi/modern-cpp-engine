#include <iostream>
#include <memory>

class Rectangle {
    int length;
    int breadth;
public:
    Rectangle(int l, int b) : length(l), breadth(b) {}

    int area() const {
        return length * breadth;
    }
};

int main() {
    // 1. Allocate object with shared ownership (Control Block initialized with use_count = 1)
    std::shared_ptr<Rectangle> ptr1 = std::make_shared<Rectangle>(25, 10);

    std::cout << "Initial Reference Count: " << ptr1.use_count() << std::endl;

    // 2. Inner scope to demonstrate reference count increment and decrement
    {
        // Copying increments the reference counter (use_count = 2)
        std::shared_ptr<Rectangle> ptr2 = ptr1;

        std::cout << "ptr1 Area: " << ptr1->area() << std::endl;
        std::cout << "ptr2 Area: " << ptr2->area() << std::endl;
        std::cout << "Reference Count inside scope: " << ptr1.use_count() << std::endl;

        // Debug check: verify both pointers reference the same heap address
        if (ptr1 == ptr2) {
            std::cout << "Debug: ptr1 and ptr2 point to the exact same object." << std::endl;
        }
    } // ptr2 goes out of scope here -> reference count automatically decrements to 1

    // 3. Verify reference count after inner scope destruction
    std::cout << "Reference Count outside scope: " << ptr1.use_count() << std::endl;

    // Memory is automatically released when ptr1 goes out of scope and use_count reaches 0.
    return 0;
}