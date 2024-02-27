#include <iostream>
#include <stack>
#include <string>

bool checkParentheses(const std::string& str) {
    std::stack<char> parenthesesStack;

    for (char ch : str) {
        if (ch == '(') {
            parenthesesStack.push(ch);
        } else if (ch == ')') {
            if (parenthesesStack.empty()) {
                return false; // More closing parentheses than opening ones
            } else {
                parenthesesStack.pop();
            }
        }
    }

    return parenthesesStack.empty(); // Check if there are any unclosed opening parentheses
}

int main() {
    std::string input;
    std::cout << "Enter a string containing parentheses: ";
    std::getline(std::cin, input);

    if (checkParentheses(input)) {
        std::cout << "The parentheses in the string are balanced." << std::endl;
    } else {
        std::cout << "The parentheses in the string are not balanced." << std::endl;
    }

    return 0;
}
