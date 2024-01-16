#include <iostream>
#include <string>

std::string* createStringOnStack() {
    std::string* strPointer = new std::string("abcdefghijkl");
    
    return strPointer;
}

void useReturnedString(std::string* strPointer) {
    std::string result = *strPointer;

    std::cout << "String from the helper function: " << result << std::endl;

    delete strPointer;
}

int main() {
    std::string* returnedString = createStringOnStack();
    useReturnedString(returnedString);

    return 0;
}
