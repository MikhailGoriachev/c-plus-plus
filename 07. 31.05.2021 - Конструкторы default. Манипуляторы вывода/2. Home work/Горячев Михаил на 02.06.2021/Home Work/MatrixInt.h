#pragma once

class MatrixInt
{
    // количество строк
    int rows_;

    // количество столбцов
    int cols_;

    // указатель на двумерный массив(матрицу)
    int** matrix_;

public:

#pragma region Конструкторы и деструктор
    // конструктор по умолчанию
    MatrixInt() :rows_(5), cols_(8), matrix_(create(rows_, cols_)) {  }

    // конструктор принимающий rows и cols
    MatrixInt(int rows, int cols)
    {
        setRows(rows);
        setCols(cols);

        matrix_ = create(rows_, cols_);
    }

    // деструктор
    ~MatrixInt()
    {
        for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
        delete[] matrix_;
    }
	
#pragma endregion
	
#pragma region Сеттеры и Геттеры

    // сеттер rows
    void setRows(int rows)
    {
        if (rows <= 0)
        {
            throw exception("Количество строк должно быть больше нуля!");
        }

        rows_ = rows;
    }

    // геттер rows
    int getRows() const { return rows_; }

    // сеттер cols
    void setCols(int cols)
    {
        if (cols <= 0)
        {
            throw exception("Количество столбцов должно быть больше нуля!");
        }

        cols_ = cols;
    }

    // геттер cols
    int getCols() const { return cols_; }

#pragma endregion

#pragma region Методы
    // создание двумерного массива
    int** create(int rows, int cols)
    {
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++) matrix[i] = new int[cols];
        return matrix;
    }

    // доступ к элементу массива
    int& operator()(int row, int col)
    {
        return matrix_[row][col];
    }

    int rows() const { return rows_; }
    int cols() const { return cols_; }

#pragma endregion 
};

