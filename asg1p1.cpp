#include <iostream>

void demonstratePointerAntiPatterns() {
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

int main() {
    demonstratePointerAntiPatterns();

    return 0;
}
