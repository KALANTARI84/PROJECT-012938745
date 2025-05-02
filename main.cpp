#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:

    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    float getReal() const { return real; }
    float getImag() const { return imag; }

    Complex operator+(const Complex& obj) const {
        return Complex(real + obj.real, imag + obj.imag);
    }

    Complex operator-(const Complex& obj) const {
        return Complex(real - obj.real, imag - obj.imag);
    }

    Complex operator*(const Complex& obj) const {
        return Complex(real * obj.real - imag * obj.imag,
                       real * obj.imag + imag * obj.real);
    }

    Complex operator/(const Complex& obj) const {
        float denom = obj.real * obj.real + obj.imag * obj.imag;
        return Complex((real * obj.real + imag * obj.imag) / denom,
                       (imag * obj.real - real * obj.imag) / denom);
    }

    Complex& operator+=(const Complex& obj) {
        real += obj.real;
        imag += obj.imag;
        return *this;
    }

    bool operator==(const Complex& obj) const {
        return (real == obj.real && imag == obj.imag);
    }

    bool operator!=(const Complex& obj) const {
        return !(*this == obj);
    }

    friend ostream& operator<<(ostream& out, const Complex& C) {
        if (C.imag >= 0)
            out << C.real << " + " << C.imag << "i";
        else
            out << C.real << " - " << -C.imag << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& C) {
        cout << "Enter real part: ";
        in >> C.real;
        cout << "Enter imaginary part: ";
        in >> C.imag;
        return in;
    }

    float magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;

    Complex c3;
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    return 0;
}
