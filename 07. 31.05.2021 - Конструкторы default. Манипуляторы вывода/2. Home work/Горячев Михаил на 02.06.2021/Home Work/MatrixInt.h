#pragma once

class MatrixInt
{
    // ���������� �����
    int rows_;

    // ���������� ��������
    int cols_;

    // ��������� �� ��������� ������(�������)
    int** matrix_;

public:

#pragma region ������������ � ����������
    // ����������� �� ���������
    MatrixInt() :rows_(5), cols_(8), matrix_(create(rows_, cols_)) {  }

    // ����������� ����������� rows � cols
    MatrixInt(int rows, int cols)
    {
        setRows(rows);
        setCols(cols);

        matrix_ = create(rows_, cols_);
    }

    // ����������
    ~MatrixInt()
    {
        for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
        delete[] matrix_;
    }
	
#pragma endregion
	
#pragma region ������� � �������

    // ������ rows
    void setRows(int rows)
    {
        if (rows <= 0)
        {
            throw exception("���������� ����� ������ ���� ������ ����!");
        }

        rows_ = rows;
    }

    // ������ rows
    int getRows() const { return rows_; }

    // ������ cols
    void setCols(int cols)
    {
        if (cols <= 0)
        {
            throw exception("���������� �������� ������ ���� ������ ����!");
        }

        cols_ = cols;
    }

    // ������ cols
    int getCols() const { return cols_; }

#pragma endregion

#pragma region ������
    // �������� ���������� �������
    int** create(int rows, int cols)
    {
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++) matrix[i] = new int[cols];
        return matrix;
    }

    // ������ � �������� �������
    int& operator()(int row, int col)
    {
        return matrix_[row][col];
    }

    int rows() const { return rows_; }
    int cols() const { return cols_; }

#pragma endregion 
};

