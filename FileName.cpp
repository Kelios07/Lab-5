#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Complex {
private:
    double real;
    double imag; 

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    ~Complex() {}

    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator - () const {
        return Complex(-real, -imag);
    }

    Complex operator * (const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex operator * (double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    friend Complex operator * (double scalar, const Complex& c) {
        return Complex(c.real * scalar, c.imag * scalar);
    }

    bool operator == (const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    bool operator != (const Complex& other) const {
        return !(*this == other);
    }

    Complex conjugate() const {
        return Complex(real, -imag);
    }

    Complex& operator = (const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    void print() const {
        if (imag < 0)
            cout << real << " - " << abs(imag) << "i" << endl;
        else
            cout << real << " + " << imag << "i" << endl;
    }

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    static bool is_valid_input(double r, double i) {
        return true;
    }
};

int main() {
    Complex c1, c2, result;
    int choice;

    cout << "Enter first complex number:\n";
    c1.input();
    cout << "Enter second complex number:\n";
    c2.input();

    do {
        cout << "\nChoose operation:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication (complex)\n";
        cout << "4. Multiplication (by real number)\n";
        cout << "5. Conjugate of first number\n";
        cout << "6. Compare\n";
        cout << "7. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            result = c1 + c2;
            cout << "\nResult of addition: ";
            result.print();
            break;
        case 2:
            result = c1 - c2;
            cout << "\nResult of subtraction: ";
            result.print();
            break;
        case 3:
            result = c1 * c2;
            cout << "\nResult of multiplication: ";
            result.print();
            break;
        case 4:
            double scalar;
            cout << "\nEnter real number: ";
            cin >> scalar;
            result = c1 * scalar;
            cout << "\nResult of multiplication by scalar: ";
            result.print();
            break;
        case 5:
            cout << "\nConjugate of first number: ";
            c1.conjugate().print();
            break;
        case 6:
            if (c1 == c2)
                cout << "Both complex numbers are equal.\n";
            else
                cout << "The complex numbers are not equal.\n";
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
