#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a given character is a opening parenthesis
bool isOpeningParenthesis(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if a given character is a closing parenthesis
bool isClosingParenthesis(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// Function to check if two given parentheses are a matching pair
bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to check if an infix expression is balanced or not
bool isBalanced(string expression) {
    stack<char> s;
    for (int i = 0; i < expression.length(); i++) {
        if (isOpeningParenthesis(expression[i])) {
            s.push(expression[i]);
        } else if (isClosingParenthesis(expression[i])) {
            if (s.empty() || !isMatchingPair(s.top(), expression[i])) {
                return false;
            } else {
                s.pop();
            }
        }
    }
    return s.empty();
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return -1;
    }
}

// Function to convert an infix expression to a postfix expression
string infixToPostfix(string expression) {
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c >= '0' && c <= '9') {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && getPrecedence(c) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Main function to read an infix expression from the user, perform balanced parentheses check,
// and convert the infix expression to postfix expression if it is balanced.
int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    if (!isBalanced(expression)) {
        cout << "Error: Expression is not balanced\n";
        return 0;
    }
    string postfix = infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << "\n";
    return 0;
}
