#include <iostream>
#include <stack>
#include <string>

double evaluateRPN(const std::string& expression) {
    std::stack<int> stack;
    std::string number;

    for (char ch : expression) {
        if (ch >= '0' && ch <= '9') {
            number += ch;
        } else if (ch == ' ') {
            if (!number.empty()) {
                stack.push(std::stoi(number));
                number.clear();
            }
        } else {
            // ќбработка операторов
            if (!number.empty()) {
                stack.push(std::stoi(number));
                number.clear();
            }

            if (stack.size() < 2) {
                throw std::runtime_error("Incorrect expression!");
            }

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (ch == '+') stack.push(a + b);
            else if (ch == '-') stack.push(a - b);
            else if (ch == '*') stack.push(a * b);
            else if (ch == '/') {
                if (b == 0) throw std::runtime_error("Divide by zero");
                stack.push(a / b);
            } else {
                throw std::runtime_error(std::string("Unknown operator: ") + ch);
            }
        }
    }

    // ≈сли осталось накопленное число, помещаем его в стек
    if (!number.empty()) {
        stack.push(std::stoi(number));
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Inkorrect expression");
    }

    return stack.top();
}

int main() {
    std::string expression;
    std::cout << "Input expression in reverse polish notation: ";
    std::getline(std::cin, expression);

    try {
        int result = evaluateRPN(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
