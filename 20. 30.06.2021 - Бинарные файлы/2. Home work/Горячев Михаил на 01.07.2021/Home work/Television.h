#pragma once

#include "pch.h"

/*	
	����� Television, �������������� ������ � ���������� � ���������
	����������.��������� ���� ������ :
		�	������������� ���������� � char*
		�	������ ���������� � char*
		�	��������� ������ � ������ � double
		�	������ � ��������� ������� � char*
		�	������ � �������� � ���������� ������� � char*
		�	������ � �������� � ���������� ��������� � char*
		�	��������� ������� � ������ � int
	��� ������ ������������ ���������(������� � �������), ������������(� �.�. explicit
	������������ �����������), ����������� �������� ������������, ����� � ������.
	����������� �� ��������� ��������� ������ ���� � ��� ���������� �������� ��������
	������� �������� �����������.
*/

class Television
{
public:

#pragma region ��������� 

	// ������������ ������ ���� ������������� ����������
	static const int MANUFACTURER_MAX_SIZE = 50;

	// ����������� ������ ���� ������������� ����������
	static const int MANUFACTURER_MIN_SIZE = 0;

	// ������������ ������ ���� ������ ����������
	static const int MODEL_MAX_SIZE = 40;

	// ����������� ������ ���� ������ ����������
	static const int MODEL_MIN_SIZE = 0;

	// ������������ ��������� � ������
	static const double DIAGONAL_MAX;

	// ����������� ��������� � ������
	static const double DIAGONAL_MIN;

	// ������������ ����� ���� � ��������� �������
	static const int DEFECT_MAX_SIZE = 60;

	// ����������� ����� ���� � ��������� �������
	static const int DEFECT_MIN_SIZE = 0;

	// ������������ ����� ���� ��� ������� 
	static const int REPAIRER_MAX_SIZE = 60;

	// ����������� ����� ���� ��� �������
	static const int REPAIRER_MIN_SIZE = 0;

	// ������������ ����� ���� ��� ���������
	static const int OWNER_MAX_SIZE = 60;

	// ����������� ����� ���� ��� ���������
	static const int OWNER_MIN_SIZE = 0;

	// ������������ ��������� ������� 
	static const int PRICE_MAX = 1'000'000;

	// ����������� ��������� �������
	static const int PRICE_MIN = 0;

#pragma endregion

private:

	// ������������� ���������� � char*
	char* manufacturer_;

	// ������ ���������� � char*
	char* model_;

	// ��������� ������ � ������ � double
	double diagonal_;

	// ������ � ��������� ������� � char*
	char* defect_;

	// ������ � �������� � ���������� ������� � char*
	char* repairer_;

	// ������ � �������� � ���������� ��������� � char*
	char* owner_;

	// ��������� ������� � ������ � int
	int price_;

public:

#pragma region ������������, ���������� � �������� ������������

	// ����������� �� ��������� 
	Television() : Television("", "", 0, "", "", "", 0) {}
	

	// ����������� ����������������
	explicit Television(const char* manufacturer, const char* model, double diagonal, const char* defect,
		const char* repairer, const char* owner, int price) :
		manufacturer_(new char[MANUFACTURER_MAX_SIZE + 1]),
		model_(new char[MODEL_MAX_SIZE + 1]),
		defect_(new char[DEFECT_MAX_SIZE + 1]),
		repairer_(new char[REPAIRER_MAX_SIZE + 1]),
		owner_(new char[OWNER_MAX_SIZE + 1])
	{
		// ���������� ��������� ��������
		setManufacturer(manufacturer);
		setModel(model);
		setDiagonal(diagonal);
		setDefect(defect);
		setRepairer(repairer);
		setOwner(owner);
		setPrice(price);
	}


	// ����������� ����������
	Television(const Television& television) :
		manufacturer_(new char[MANUFACTURER_MAX_SIZE + 1]),
		model_(new char[MODEL_MAX_SIZE + 1]),
		defect_(new char[DEFECT_MAX_SIZE + 1]),
		repairer_(new char[REPAIRER_MAX_SIZE + 1]),
		owner_(new char[OWNER_MAX_SIZE + 1])
	{
		// ����������� ��������� �����
		memcpy(manufacturer_, television.manufacturer_, MANUFACTURER_MAX_SIZE);
		memcpy(model_, television.model_, MODEL_MAX_SIZE);
		memcpy(defect_, television.defect_, DEFECT_MAX_SIZE);
		memcpy(repairer_, television.repairer_, REPAIRER_MAX_SIZE);
		memcpy(owner_, television.owner_, OWNER_MAX_SIZE);

		// ����������� ��������
		diagonal_ = television.diagonal_;
		price_ = television.price_;
	}
	

	// ����������
	~Television()
	{
		delete[]manufacturer_;
		delete[]model_;
		delete[]defect_;
		delete[]repairer_;
		delete[]owner_;
	}


	// �������� ������������
	Television& operator=(const Television& television)
	{
		// ����������� ��������� �����
		memcpy(manufacturer_, television.manufacturer_, MANUFACTURER_MAX_SIZE);
		memcpy(model_, television.model_, MODEL_MAX_SIZE);
		memcpy(defect_, television.defect_, DEFECT_MAX_SIZE);
		memcpy(repairer_, television.repairer_, REPAIRER_MAX_SIZE);
		memcpy(owner_, television.owner_, OWNER_MAX_SIZE);

		// ����������� ��������
		diagonal_ = television.diagonal_;
		price_ = television.price_;

		return *this;
	}

#pragma endregion

#pragma region ������� � �������

	// ������ manufacturer_
	void setManufacturer(const char* manufacturer)
	{
		// ����� ������
		size_t len = strlen(manufacturer);

		// ���� ������ ������� ������� ��� ��������
		if (len > MANUFACTURER_MAX_SIZE or len < MANUFACTURER_MIN_SIZE)
			throw exception("App: ������������ ��������");

		// ����������� 
		strncpy(manufacturer_, manufacturer, MANUFACTURER_MAX_SIZE);
	}

	// ������ manufacturer_
	const char* const getManufactures() { return manufacturer_; }


	// ������ model_
	void setModel(const char* model)
	{
		// ����� ������
		size_t len = strlen(model);

		// ���� ������ ������� ������� ��� ��������
		if (len > MODEL_MAX_SIZE or len < MODEL_MIN_SIZE)
			throw exception("App: ������������ ��������");

		// ����������� 
		strncpy(model_, model, MODEL_MAX_SIZE);
	}

	// ������ model_
	const char* const getModel() { return model_; }

	
	// ������ diagonal_
	void setDiagonal(double diagonal)
	{
		// ���� �������� �����������
		if (diagonal > DIAGONAL_MAX or diagonal < DIAGONAL_MIN)
			throw exception("App: ������������ ��������");

		// ����������� 
		diagonal_ = diagonal;
	}

	// ������ diagonal_
	double getDiagonal() { return diagonal_; }


	// ������ defect_
	void setDefect(const char* defect)
	{
		// ����� ������
		size_t len = strlen(defect);

		// ���� ������ ������� ������� ��� ��������
		if (len > DEFECT_MAX_SIZE or len < DEFECT_MIN_SIZE)
			throw exception("App: ������������ ��������");

		// ����������� 
		strncpy(defect_, defect, DEFECT_MAX_SIZE);
	}

	// ������ defect_
	const char* const getDefect() { return defect_; }


	// ������ repairer_
	void setRepairer(const char* repairer)
	{
		// ����� ������
		size_t len = strlen(repairer);

		// ���� ������ ������� ������� ��� ��������
		if (len > REPAIRER_MAX_SIZE or len < REPAIRER_MIN_SIZE)
			throw exception("App: ������������ ��������");

		// ����������� 
		strncpy(repairer_, repairer, REPAIRER_MAX_SIZE);
	}

	// ������ repairer_
	const char* const getRepairer() { return repairer_; }


	// ������ owner_
	void setOwner(const char* owner)
	{
		// ����� ������
		size_t len = strlen(owner);

		// ���� ������ ������� ������� ��� ��������
		if (len > OWNER_MAX_SIZE or len < OWNER_MIN_SIZE)
			throw exception("App: ������������ ��������");

		// ����������� 
		strncpy(owner_, owner, OWNER_MAX_SIZE);
	}

	// ������ owner_
	const char* const getOwner() { return owner_; }


	// ������ price_
	void setPrice(int price)
	{
		// ���� �������� �����������
		if (price > PRICE_MAX or price < PRICE_MIN)
			throw exception("App: ������������ ��������");

		// ����������� 
		price_ = price;
	}

	// ������ price_
	int getPrice() { return price_; }

#pragma endregion

#pragma region ������

	// ������ � �������� ����
	void write(FILE* file)
	{
		fwrite(manufacturer_, sizeof(char), MANUFACTURER_MAX_SIZE, file);
		fwrite(model_, sizeof(char), MODEL_MAX_SIZE, file);
		fwrite(&diagonal_, sizeof(diagonal_), 1, file);
		fwrite(defect_, sizeof(char), DEFECT_MAX_SIZE, file);
		fwrite(repairer_, sizeof(char), REPAIRER_MAX_SIZE, file);
		fwrite(owner_, sizeof(char), OWNER_MAX_SIZE, file);
		fwrite(&price_, sizeof(price_), 1, file);
	}

	// ������ �� ��������� �����
	void read(FILE* file)
	{
		fread(manufacturer_, sizeof(char), MANUFACTURER_MAX_SIZE, file);
		fread(model_, sizeof(char), MODEL_MAX_SIZE, file);
		fread(&diagonal_, sizeof(diagonal_), 1, file);
		fread(defect_, sizeof(char), DEFECT_MAX_SIZE, file);
		fread(repairer_, sizeof(char), REPAIRER_MAX_SIZE, file);
		fread(owner_, sizeof(char), OWNER_MAX_SIZE, file);
		fread(&price_, sizeof(price_), 1, file);
	}

#pragma endregion

};

