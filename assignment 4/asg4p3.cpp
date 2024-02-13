#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string expression) {
    stack<char> operators;
    string postfix;

    for (char c : expression) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard '('
        } else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' && ((c != '*' && c != '/') || (operators.top() == '+' || operators.top() == '-'))) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Pop remaining operators
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

string infixToPrefix(string expression) {
    string reversedExpression = string(expression.rbegin(), expression.rend());
    for (char &c : reversedExpression) {
        if (c == '(') {
            c = ')';
        } else if (c == ')') {
            c = '(';
        }
    }
    string postfix = infixToPostfix(reversedExpression);
    return string(postfix.rbegin(), postfix.rend());
}

int main() {
    string expression;
    
    cout << "Enter a fully parenthesized expression: ";
    getline(cin, expression);
