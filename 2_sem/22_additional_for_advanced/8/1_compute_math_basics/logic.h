double f(double x);

double f_der(double x);

double f_der_der(double x);

double phi(double x);

double phi_der(double x);

double solve_method_1(double a, double b, double eps);

double solve_method_2(double a, double b, double eps);

double solve_method_3(double a, double b, double eps);

double solve_method_4(double a, double b, double eps);

// Комбинированный метод
double solve_method_5(double a, double b, double eps);

// Метод итераций
double solve_method_6(double a, double b, double eps);

//Отделение корней
bool define_root(double &a, double &b, double step);
