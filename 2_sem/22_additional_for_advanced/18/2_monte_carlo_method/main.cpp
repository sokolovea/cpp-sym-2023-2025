#include <iostream>
#include <functional>
#include <random>
#include <algorithm>
#include <ctime>

class IntegratorMonteCarlo {
public:
    IntegratorMonteCarlo(std::function<double(double)> func, double a, double b)
        : f(func), a(a), b(b), generator(static_cast<unsigned int>(std::time(nullptr)))
    {
        minY = findMinFuncValue();
        maxY = findMaxFuncValue();
    }

    double integrate(int n) {
        std::uniform_real_distribution<double> distX(a, b);
        std::uniform_real_distribution<double> distY(std::min(0.0, minY), maxY);

        int green_counter = 0;
        for (int i = 0; i < n; i++) {
            double x = distX(generator);
            double y = distY(generator);
            if (y < f(x)) {
                green_counter++;
            }
        }
        double area = (b - a) * (maxY - std::min(0.0, minY));
        return area * static_cast<double>(green_counter) / n; //(double)
    }

private:
    double findMinFuncValue() {
        double minValue = f(a);
        for (double i = a; i <= b; i += 0.01) {
            minValue = std::min(minValue, f(i));
        }
        return minValue;
    }

    double findMaxFuncValue() {
        double maxValue = f(a);
        for (double i = a; i <= b; i += 0.01) {
            maxValue = std::max(maxValue, f(i));
        }
        return maxValue;
    }

    std::function<double(double)> f;
    double a;
    double b;
    double minY;
    double maxY;
    std::mt19937 generator;
};

double exampleFunction(double x) {
    return x * x + 1;
}

int main() {
    // Пределы интегрирования
    double a = -1;
    double b = 2;

    // Количество случайных точек
    int n = 100000000;

    // Создание объекта интегратора
    IntegratorMonteCarlo integrator(exampleFunction, a, b);

    // Вычисление интеграла
    double result = integrator.integrate(n);

    // Вывод результата
    std::cout << "Значение интеграла: " << result << std::endl;

    return 0;
}
