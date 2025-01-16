#include <iostream>
#include <iomanip>

class Complex {
public:
    Complex(int r = 0.0, int i = 0.0) : r(r), i(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(r + other.r, i + other.i);
    }

    Complex operator-(const Complex& other) const {
        return Complex(r - other.r, i - other.i);
    }

    Complex operator*(const Complex& other) const {
        return Complex(r * other.r - i * other.i, r * other.i + i * other.r);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.r * other.r + other.i * other.i;
        return Complex((r * other.r + i * other.i) / denom, (i * other.r - r * other.i) / denom);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << std::fixed << std::setprecision(2);
        out << "(" << c.r << " + " << c.i << "i)";
        return out;
    }

private:
    int r; 
    int i;
};

int main() {
    Complex a(2.0, 3.0), b(1.0, -1.0);

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    return 0;
}
