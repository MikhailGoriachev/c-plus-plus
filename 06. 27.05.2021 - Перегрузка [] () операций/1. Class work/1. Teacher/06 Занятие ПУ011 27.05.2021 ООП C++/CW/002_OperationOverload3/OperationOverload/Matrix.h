#pragma once
class Matrix
{

    int rows_;
    int cols_;
    int **matrix_;

public:
    Matrix():rows_(3), cols_(4), matrix_(create(rows_, cols_)) {  }

    int **create(int rows, int cols)
    {
        int **matrix = new int*[rows];
        for (int i = 0; i < rows; i++) matrix[i] = new int[cols];
        return matrix;
    }

    ~Matrix()
    {
        for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
        delete[] matrix_;
    }

    int &operator()(int row, int col)
    {
        return matrix_[row][col];
    }

    int rows() const { return rows_; }
    int cols() const { return cols_; }
};

