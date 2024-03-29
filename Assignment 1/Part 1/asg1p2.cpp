#include <iostream>

void demonstrateFirstPointerAntiPattern() {
    int* firstPointer = new int[100];

    for (int i = 0; i < 100; ++i) {
        firstPointer[i] = i;
    }

    int* secondPointer = firstPointer;

    delete[] firstPointer;

    for (int i = 0; i < 10; ++i) {
        std::cout << secondPointer[i] << " ";
    }
    std::cout << std::endl;
}

void demonstrateSecondPointerAntiPattern() {
    int* firstPointer = new int[100];

    int* secondPointer = firstPointer;

    delete[] firstPointer;

    std::cout << "Address of the second pointer: " << secondPointer << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << secondPointer[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "the first pointer anti-pattern:" << std::endl;
    demonstrateFirstPointerAntiPattern();

    std::cout << "\nthe second pointer anti-pattern:" << std::endl;
    demonstrateSecondPointerAntiPattern();

    return 0;
}
