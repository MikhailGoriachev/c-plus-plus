#pragma once
#include "Utils.h"
#include "pch.h"
#include "Conoid.h"
#include "App.h"

class ArrayConoid
{
	// ����� �������
	size_t size_;
	
	// ��������� �� ������ ������� �������
	Conoid* point_;

public:

#pragma region ������������ � �����������
	// ����������� �� ���������. ������ �� ��������� ������ �� ��� ��������
	// ������ Conoid
	ArrayConoid(): size_(3)
	{
		point_ = new Conoid[size_];
	}

	// ����������� ����������� ���������� ��������� � ��������� ������ 
	ArrayConoid(size_t size)
	{
		// ���� ������ ������� ������ ����
		if (size <= 0)
		{
			throw exception("������ ������� ������ ���� ������ 0\n");
		}

		size_ = size;

		point_ = new Conoid[size_];
	}

	// ����������
	~ArrayConoid()
	{
		delete[] point_;
	}
#pragma endregion

#pragma region ������ ������

	// ������� ���������� ����� �������
	size_t size() const { return size_; };

	/// <summary>
	/// ���������� ��������������. ����������� exception ����
	/// ������ ������� �� ������� �������
	/// </summary>
	/// <param name="index">������</param>
	/// <returns>���������� ������ �� ������ ������� Conoid</returns>
	Conoid& operator[](size_t index)
	{
		if (index < 0)
			throw exception("������ ������ ���� ������ ��� ������ ����");
		if (index > size_)
			throw exception("������ ������� �� ������� �������");

		return point_[index];
	}

	/// <summary>
	/// ����� ������� ������� �������� ������� � ����������� �������
	/// </summary>
	/// <returns>������ ��������</returns>
	size_t MinimumV() const
	{
		// ������ ������������ ��������
		int minV = 0;

		for (size_t i = 1; i < size_; i++)
		{
			if (point_[i].MathV() < point_[minV].MathV())
			{
				minV = i;
			}
		}

		return minV;
	}

	/// <summary>
	/// ����� ������� �������� ������� � ������������ ��������. 
	/// </summary>
	/// <returns>������ ��������</returns>
	size_t MaximumS() const
	{
		// ������ ������������� ��������
		int maxS = 0;

		for (size_t i = 1; i < size_; i++)
		{
			if (point_[i].MathS() > point_[maxS].MathS())
			{
				maxS = i;
			}
		}

		return maxS;
	}

#pragma endregion

#pragma region ������������� �������

	// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
	friend ostream& operator<<(ostream& os, ArrayConoid& arr);

#pragma endregion

};

