#pragma once

class Matrix
{
    // количество строк
    int rows_;

    // количество столбцов
    int cols_;

    // указатель на двумерный массив(матрицу)
    int** matrix_;

public:
    // конструктор по умолчанию
    Matrix() :rows_(5), cols_(8), matrix_(create(rows_, cols_)) {  }

    // создание двумерного массива
    int** create(int rows, int cols)
    {
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++) matrix[i] = new int[cols];
        return matrix;
    }

    // деструктор
    ~Matrix()
    {
        for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
        delete[] matrix_;
    }

    // доступ к элементу массива
    int& operator()(int row, int col)
    {
        return matrix_[row][col];
    }

    int rows() const { return rows_; }
    int cols() const { return cols_; }
};

