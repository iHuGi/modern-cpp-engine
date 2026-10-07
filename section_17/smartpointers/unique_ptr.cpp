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
    // 1. Allocate heap memory using std::make_unique (exclusive ownership)
    std::unique_ptr<Rectangle> ptr1 = std::make_unique<Rectangle>(25, 10);
    std::cout << "ptr1 Area: " << ptr1->area() << std::endl;

    // 2. Transfer ownership from ptr1 to ptr2 using std::move
    std::unique_ptr<Rectangle> ptr2 = std::move(ptr1);
    std::cout << "ptr2 Area: " << ptr2->area() << std::endl;

    // 3. Debug check: ptr1 is now nullptr after the move
    if (ptr1 == nullptr) {
        std::cout << "Debug: ptr1 is now null (ownership transferred)." << std::endl;
    }

    // Memory is automatically released when ptr2 goes out of scope here.
    return 0;
}