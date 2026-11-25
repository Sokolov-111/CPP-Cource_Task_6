#pragma once
#include <vector>
#include <iostream>

namespace math
{
    typedef double real;

    class Matrix
    {
        private:
            int cols_;
            int rows_;
            std::vector<real> mvec_;

        public:
            // Конструктор без параметров
            Matrix() {};
            // Конструктор с параметрами
            Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};

            // Оператор для обращения к значению под индексом
            real& operator()(int row, int col);

            // Сложение матриц с присваиванием
            friend Matrix operator+=(Matrix& m1, Matrix& m2);
            // Вычитание матриц с присваиванием
            friend Matrix operator-=(Matrix& m1, Matrix& m2);
            // Умножение матрицыа на число
            friend Matrix operator*=(Matrix& m1, int mult);

            // Перегрузка оператора >>
            friend std::istream& operator>>(std::istream &in, Matrix &m);
            // Перегрузка оператора <<
            friend std::ostream& operator<<(std::ostream &out, Matrix& m);
        
            // Вывод значений матрицы
            void print();
            // Получить значение переменной cols
            int getCols() const { return cols_; };
            // Получить значение переменной rows
            int getRows() const { return rows_; };
        };
} // namespace math