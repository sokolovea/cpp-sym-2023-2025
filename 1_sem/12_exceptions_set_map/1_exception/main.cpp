#include <iostream>
#include <string>
#include <stdexcept>

bool f3WithErrorCode(double a, double b, double& result) {
    if (b == 0.0) {
        return false;
    }
    result = a / b;
    return true;
}

double f3WithException(double a, double b) {
    if (b == 0.0) {
        throw std::runtime_error("Division by zero at level 3!");
    }
    return a / b;
}

bool f2WithErrorCode(double a, double b, double& result) {
    return f3WithErrorCode(a, b, result);
}

double f2WithException(double a, double b) {
    return f3WithException(a, b);
}

bool f1WithErrorCode(double a, double b, double& result) {
    return f2WithErrorCode(a, b, result);
}

double f1WithException(double a, double b) {
    return f2WithException(a, b);
}

int main() {
    double a, b;
    std::cout << "Input a, b" << std::endl;
    std::cin >> a >> b;

    // C-стиль
    double result1;
    if (f1WithErrorCode(a, b, result1)) {
        std::cout << "Result: " << result1 << std::endl;
    } else {
        std::cout << "Error: Division by zero at level 3!" << std::endl;
    }

   // Стиль C++
    try {
        double result2 = f1WithException(a, b);
        std::cout << "Result: " << result2 << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
