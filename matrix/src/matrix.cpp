#include <src/matrix.h>

using namespace math;
using namespace std;

real& Matrix::operator()(int row, int col)
{
    // Проверка на выход за границы матрицы
    if(row >= this->rows_)
    {
        cerr << "Matrix row index out of bounds" << endl;

        return this->mvec_.at(0);
    }
    if(col >= this->cols_)
    {
        cerr << "Matrix col index out of bounds" << endl;

        return this->mvec_.at(0);
    }

    int pos(0);

    pos = cols_* row + col; 

    return this->mvec_.at(pos);
} // operator()

void Matrix::print()
{
    for (int i = 0; i < this->rows_; ++i)
    {
        for (int j = 0; j < this->cols_; ++j)
        {
            cout << this->mvec_.at(cols_ * i + j) << " ";
        }
        cout << endl;
    }

    cout << endl;
} // print

// Использовать пространство имен math
namespace math
{
    Matrix operator+=(Matrix& m1, Matrix& m2)
    {
        // Проверка - одинакового ли размера матрицы
        if((m1.cols_ != m2.cols_) || (m1.rows_ != m2.rows_))
        {
            std::cerr << "Matrices can't be mulipled.";
        }

        // Создание матрицы нужного размера
        math::Matrix mSum(m1.cols_, m1.rows_);

        for(int i = 0; i < m1.rows_; i++)
        {
            for(int j = 0; j < m1.cols_; j++)
            {
                // Сложением матриц и присваивание результата в матрицу mSum
                mSum(i, j) = m1(i, j) + m2(i, j);
            }
        }

        return mSum;
    } // operator+=

    Matrix operator-=(Matrix& m1, Matrix& m2)
    {
        // Проверка - одинакового ли размера матрицы
        if((m1.cols_ != m2.cols_) || (m1.rows_ != m2.rows_))
        {
            std::cerr << "Matrices can't be mulipled.";
        }
        
        // Создание матрицы нужного размера
        math::Matrix mSum(m1.cols_, m1.rows_);

        for(int i = 0; i < m1.rows_; i++)
        {
            for(int j = 0; j < m1.cols_; j++)
            {
                mSum(i, j) = m1(i, j) - m2(i, j);
            }
        }

        return mSum;
    } // operator-=

    Matrix operator*=(Matrix& matrix, int mult)
    {
        // Создание матрицы нужного размера
        math::Matrix mSum(matrix.cols_, matrix.rows_);

        for(int i = 0; i < matrix.rows_; i++)
        {
            for(int j = 0; j < matrix.cols_; j++)
            {
                // Умножение каждого числа в матрице и присваивание в матрицу суммы под индексом
                mSum(i, j) = matrix(i, j) * mult;
            }
        }

        return mSum;
    } // operator*=

    // Перегрузка оператора >>
    std::istream& operator>>(std::istream &in, Matrix& m)
    {   
        // Пройти по всем значениям матрицы
        for(int i = 0; i < m.getRows(); i++)
        {
            for(int j = 0; j < m.getCols(); j++)
            {
                // Присвоить введенное число под индекс матрицы
                in >> m(i, j);
            }
        }

        return in;
    } // operator>>

    // Перегрузка оператора <<
    std::ostream& operator<<(std::ostream &out, Matrix& m)
    {
        out << "Filled matrix: ";
        // Пройти по всем значениям матрицы
        for(int i = 0; i < m.rows_; i++)
        {
            // Обозначение конца столбца
            out << "\n";

            for(int j = 0; j < m.cols_; j++)
            {
                // Вывести зн-е матрицы под индексом в выходной поток 
                out << m.mvec_.at(m.cols_ * i + j) << " ";
            }
        }
        
        return out;
    } // operator<<
} // math
