#include "../include/complex.h"
#include <iostream>
using namespace std;

int main() {
    Complex c1;
    Complex c2(5);
    Complex c3(3, 4);
    Complex c4(2, -3);
    Complex c5(10, 5);
    Complex c6(5, 5);
    Complex result;

    Complex* ptr = new Complex(7, 2);

    cout << "=========== display objects ===========" << endl;
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    cout << "c3 = ";
    c3.display();
    cout << "c4 = ";
    c4.display();
    cout << "ptr = ";
    ptr->display();


    cout << endl << "=========== + - * / ===========" << endl;
    result = c3 + c4;
    cout << "c3 + c4 = ";
    result.display();

    result = c3 - c4;
    cout << "c3 - c4 = ";
    result.display();

    result = c3 * c4;
    cout << "c3 * c4 = ";
    result.display();

    result = c5 / c6;
    cout << "c5 / c6 = ";
    result.display();

    cout << endl << "========= complex with int =========" << endl;
    result = c3 + 5;
    cout << "c3 + 5 = ";
    result.display();

    result = c3 - 2;
    cout << "c3 - 2 = ";
    result.display();

    result = c3 * 3;
    cout << "c3 * 3 = ";
    result.display();


    cout << endl << "========= int with complex =========" << endl;
    result = 5 + c3;
    cout << "5 + c3 = ";
    result.display();

    result = 10 - c3;
    cout << "10 - c3 = ";
    result.display();

    result = 2 * c3;
    cout << "2 * c3 = ";
    result.display();

    result = 10 / c6;
    cout << "10 / c6 = ";
    result.display();

    cout << endl << "========= division by zero =========" << endl;
    Complex c7(0, 0);
    result = c3 / c7;

    ptr=nullptr;
    delete ptr;
    return 0;
}
