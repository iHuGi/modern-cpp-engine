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
    // 1. Weak pointer initialized outside to outlive the shared pointer scope
    std::weak_ptr<Rectangle> weak_ref;

    {
        // Allocate a shared_ptr
        std::shared_ptr<Rectangle> shared_ptr = std::make_shared<Rectangle>(25, 10);
        
        // Assigning to weak_ptr DOES NOT increment the reference count!
        weak_ref = shared_ptr;

        std::cout << "Shared Count inside scope: " << shared_ptr.use_count() << std::endl;

        // To access data through a weak_ptr, convert it to a shared_ptr via lock()
        if (auto locked_ptr = weak_ref.lock()) {
            std::cout << "Locked Area: " << locked_ptr->area() << std::endl;
            std::cout << "Shared Count while locked: " << shared_ptr.use_count() << std::endl;
        }
    } // shared_ptr is destroyed here; heap memory is released!

    // 2. Check if the object still exists after shared_ptr destruction
    std::cout << "\nOutside scope check:" << std::endl;
    if (weak_ref.expired()) {
        std::cout << "Debug: Object has been destroyed! weak_ptr is expired." << std::endl;
    }

    // Attempting to lock an expired weak_ptr returns nullptr safely
    if (auto locked_ptr = weak_ref.lock()) {
        std::cout << "Area: " << locked_ptr->area() << std::endl;
    } else {
        std::cout << "Debug: Cannot lock weak_ptr because target object no longer exists." << std::endl;
    }

    return 0;
}