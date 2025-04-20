#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <iomanip>

using namespace std;

double f(double x) {
    return -2 * pow(x, 3) - 20;
}

double simpson(double a, double b, int n) {
    if (n % 2 != 0) ++n;  
    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        result += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }

    return (h / 3) * result;
}

double analytical_integral(double a, double b) {
    auto F = [](double x) {
        return -0.5 * pow(x, 4) - 20 * x;
        };
    return F(b) - F(a);
}


void run_experiment(double a, double b, const vector<int>& N_values, double exact) {
    cout << "\n|   N   | Simpson | Error |\n";
    cout << "|--------|---------------|------------|\n";
    for (int n : N_values) {
        double area = simpson(a, b, n);
        double error = fabs(area - exact);
        cout << "| " << setw(6) << n
            << " | " << setw(13) << fixed << setprecision(8) << area
            << " | " << setw(10) << error << " |\n";
    }
}

void unit_tests(double a, double b, double exact) {
    const double epsilon = 1e-6;

    double area1 = simpson(a, b, 10);
    assert(fabs(area1 - exact) < 0.1);  

    double area2 = simpson(a, b, 100);
    assert(fabs(area2 - exact) < 0.01);  

    double area3 = simpson(a, b, 10000);
    assert(fabs(area3 - exact) < epsilon);  

    cout << "\n[✔] Unit-tests rabotaut yspeshno.\n";
}

int main() {
    double a = -5, b = 2;

    double exact = analytical_integral(a, b);
    cout << "Аналитическая площадь: " << exact << endl;

    vector<int> N_values = { 10, 50, 100, 1000, 10000 };
    run_experiment(a, b, N_values, exact);

    unit_tests(a, b, exact);

    return 0;
}