#pragma once

class MatrixDouble
{
    // количество строк
    int rows_;

    // количество столбцов
    int cols_;

    // указатель на двумерный массив(матрицу)
    double** matrix_;

public:
    // конструктор по умолчанию
    MatrixDouble() :rows_(5), cols_(8), matrix_(create(rows_, cols_)) {  }

    // конструктор принимающий rows и cols
	MatrixDouble(int rows, int cols)
    {
        setRows(rows);
        setCols(cols);

        matrix_ = create(rows_, cols_);
    }

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
	
    // создание двумерного массива
    double** create(int rows, int cols)
    {
        double** matrix = new double* [rows];
        for (int i = 0; i < rows; i++) matrix[i] = new double[cols];
        return matrix;
    }

    // деструктор
    ~MatrixDouble()
    {
        for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
        delete[] matrix_;
    }

    // доступ к элементу массива
    double& operator()(int row, int col)
    {
        return matrix_[row][col];
    }

    double rows() const { return rows_; }
    double cols() const { return cols_; }
};

