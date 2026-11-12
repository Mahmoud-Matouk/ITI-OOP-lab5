#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;

    public:
        Complex(int real = 0, int img = 0) {
            this->real = real;
            this->img = img;
        }

        int getReal() const {
            return this->real;
        }

        int getImg() const {
            return this->img;
        }

        void setComplex(int real, int img) {
            this->real=real;
            this->img=img;
        }

        void display() const {
            if (real == 0 && img == 0) {
                cout << 0 << "\n";
                return;
            }

            if (real != 0) cout << real;

            if (img > 0 && real != 0) {
                cout << "+";
            }

            if (img != 0) cout << img << "j";
            cout << "\n";
        }

        // (a + bj) + (c + dj) = (a + c) + (b + d)j
        Complex operator+ (const Complex& cx) const {
            return Complex(real + cx.real, img + cx.img);
        }

        // (a + bj) - (c + dj) = (a - c) + (b - d)j
        Complex operator- (const Complex& cx) const {
            return Complex(real - cx.real, img - cx.img);
        }

        // (a + bj) * (c + dj) = (ac - bd) + (ad + bc)j
        Complex operator* (const Complex& cx) const {
            return Complex(
                (real * cx.real) - (img * cx.img),
                (real * cx.img) + (img * cx.real)
            );
        }

        // (a + bj) / (c + dj) = [ (ac + bd) + (bc — ad)j ] / (c*c +d*d)
        Complex operator/ (const Complex& cx) const {
            int denom = (cx.real * cx.real) + (cx.img * cx.img);
            if (denom == 0) {
                cout << "Division by zero\n";
                return Complex(0, 0);
            }
            return Complex(
                ((real * cx.real) + (img * cx.img)) / denom,
                ((img * cx.real) - (real * cx.img)) / denom
            );
        }

    ~Complex() {}
};

// x + (a + bj) = (x + a) + bj
Complex operator+ (int x, const Complex& cx) {
    return Complex(x + cx.getReal(), cx.getImg());
}

// x - (c + dj) = (x - c) - dj
Complex operator- (int x, const Complex& cx) {
    return Complex(x - cx.getReal(), -cx.getImg());
}

// x * (c + dj) = (xc) + (xd)j
Complex operator* (int x, const Complex& cx) {
    return Complex(x * cx.getReal(), x * cx.getImg());
}

// x / (c + dj) = [ (xc) + (-xd)j ] / (c*c + d*d)
Complex operator/ (int x, const Complex& cx) {
    int denom = (cx.getReal() * cx.getReal()) + (cx.getImg() * cx.getImg());
    if (denom == 0) {
        cout << "Division by zero\n";
        return Complex(0, 0);
    }
    return Complex(
        (x * cx.getReal()) / denom,
        (-x * cx.getImg()) / denom
    );
}

#endif