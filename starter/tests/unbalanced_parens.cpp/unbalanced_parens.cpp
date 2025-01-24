#include <iostream>

class UnbalancedClass {
public:
    UnbalancedClass() {
    }

    void UnbalancedMethod() {
        if 1 == 1) {
            std::cout << "Unbalanced Called" << std::endl;
        } else {
            std::cout << "This should not happen" << std::endl;
        }
    }

    int UnbalancedArray[5] = {1, 2, 3, 4, 5;
};

int main() {
    UnbalancedClass obj;
    obj.UnbalancedMethod();
    return 0;
}
