#pragma once

class MatrixDouble
{
    // ���������� �����
    int rows_;

    // ���������� ��������
    int cols_;

    // ��������� �� ��������� ������(�������)
    double** matrix_;

public:
    // ����������� �� ���������
    MatrixDouble() :rows_(5), cols_(8), matrix_(create(rows_, cols_)) {  }

    // ����������� ����������� rows � cols
	MatrixDouble(int rows, int cols)
    {
        setRows(rows);
        setCols(cols);

        matrix_ = create(rows_, cols_);
    }

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
	
    // �������� ���������� �������
    double** create(int rows, int cols)
    {
        double** matrix = new double* [rows];
        for (int i = 0; i < rows; i++) matrix[i] = new double[cols];
        return matrix;
    }

    // ����������
    ~MatrixDouble()
    {
        for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
        delete[] matrix_;
    }

    // ������ � �������� �������
    double& operator()(int row, int col)
    {
        return matrix_[row][col];
    }

    double rows() const { return rows_; }
    double cols() const { return cols_; }
};

