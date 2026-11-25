#include <src/matrix.h>
#include <iostream>

using namespace std;

int main()
{
    math::Matrix m1(3, 3);

    m1(0, 0) = 10;
    m1(1, 1) = 12;
    m1(2, 2) = 15;

    // m1.print();
    
    math::Matrix m2(3, 3);

    m2(0, 0) = 15;
    m2(1, 1) = 5;
    m2(2, 2) = 25;

    // Пример перегрузки оператора +=
    m2 = m2 += m1;
    cout << "m2 += m1: " << endl;
    m2.print();

    // Пример перегрузки оператора -=
    m2 = m2 -= m1;
    cout << "m2 -= m1: " << endl;
    m2.print();

    // Пример перегрузки оператора -=
    m2 = m2 *= 2;
    cout << "m2 *= 2: " << endl;
    m2.print();

    math::Matrix fillMatr(2, 2);
    // Пример перегрузки оператора ввода >>
    cout << "Enter numbers at matrix: " << std::endl;
    std::cin >> fillMatr;
    
    // Пример перегрузки оператора вывода <<
    cout << fillMatr << endl;
    return 0;
}