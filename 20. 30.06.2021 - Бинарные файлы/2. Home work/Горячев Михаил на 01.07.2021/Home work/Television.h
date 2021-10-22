#pragma once

#include "pch.h"

/*	
	Класс Television, представляющий данные о телевизоре в ремонтной
	мастерской.Приватные поля класса :
		•	производитель телевизора – char*
		•	модель телевизора – char*
		•	диагональ экрана в дюймах – double
		•	строка с описанием дефекта – char*
		•	строка с фамилией и инициалами мастера – char*
		•	строка с фамилией и инициалами владельца – char*
		•	стоимость ремонта в рублях – int
	Для класса разработайте аксессоры(геттеры и сеттеры), конструкторы(в т.ч. explicit
	инициирующий конструктор), перегрузите операции присваивания, ввода и вывода.
	Конструктор по умолчанию формирует пустые поля – при разработке сеттеров считайте
	нулевые значения допустимыми.
*/

class Television
{
public:

#pragma region Константы 

	// максимальный размер поля производитель телевизора
	static const int MANUFACTURER_MAX_SIZE = 50;

	// минимальный размер поля производитель телевизора
	static const int MANUFACTURER_MIN_SIZE = 0;

	// максимальный размер поля модель телевизора
	static const int MODEL_MAX_SIZE = 40;

	// минимальный размер поля модель телевизора
	static const int MODEL_MIN_SIZE = 0;

	// максимальная диагональ в дюймах
	static const double DIAGONAL_MAX;

	// минимальная диагональ в дюймах
	static const double DIAGONAL_MIN;

	// максимальная длина поля с описанием дефекта
	static const int DEFECT_MAX_SIZE = 60;

	// минимальная длина поля с описанием дефекта
	static const int DEFECT_MIN_SIZE = 0;

	// максимальная длина поля ФИО мастера 
	static const int REPAIRER_MAX_SIZE = 60;

	// минимальная длина поля ФИО мастера
	static const int REPAIRER_MIN_SIZE = 0;

	// максимальная длина поля ФИО владельца
	static const int OWNER_MAX_SIZE = 60;

	// минимальная длина поля ФИО владельца
	static const int OWNER_MIN_SIZE = 0;

	// максимальная стоимость ремонта 
	static const int PRICE_MAX = 1'000'000;

	// минимальная стоимость ремонта
	static const int PRICE_MIN = 0;

#pragma endregion

private:

	// производитель телевизора – char*
	char* manufacturer_;

	// модель телевизора – char*
	char* model_;

	// диагональ экрана в дюймах – double
	double diagonal_;

	// строка с описанием дефекта – char*
	char* defect_;

	// строка с фамилией и инициалами мастера – char*
	char* repairer_;

	// строка с фамилией и инициалами владельца – char*
	char* owner_;

	// стоимость ремонта в рублях – int
	int price_;

public:

#pragma region Конструкторы, деструктор и операция присваивания

	// конструктор по умолчанию 
	Television() : Television("", "", 0, "", "", "", 0) {}
	

	// конструктор инициализирующий
	explicit Television(const char* manufacturer, const char* model, double diagonal, const char* defect,
		const char* repairer, const char* owner, int price) :
		manufacturer_(new char[MANUFACTURER_MAX_SIZE + 1]),
		model_(new char[MODEL_MAX_SIZE + 1]),
		defect_(new char[DEFECT_MAX_SIZE + 1]),
		repairer_(new char[REPAIRER_MAX_SIZE + 1]),
		owner_(new char[OWNER_MAX_SIZE + 1])
	{
		// защищенная установка значений
		setManufacturer(manufacturer);
		setModel(model);
		setDiagonal(diagonal);
		setDefect(defect);
		setRepairer(repairer);
		setOwner(owner);
		setPrice(price);
	}


	// конструктор копирующий
	Television(const Television& television) :
		manufacturer_(new char[MANUFACTURER_MAX_SIZE + 1]),
		model_(new char[MODEL_MAX_SIZE + 1]),
		defect_(new char[DEFECT_MAX_SIZE + 1]),
		repairer_(new char[REPAIRER_MAX_SIZE + 1]),
		owner_(new char[OWNER_MAX_SIZE + 1])
	{
		// копирование строковых полей
		memcpy(manufacturer_, television.manufacturer_, MANUFACTURER_MAX_SIZE);
		memcpy(model_, television.model_, MODEL_MAX_SIZE);
		memcpy(defect_, television.defect_, DEFECT_MAX_SIZE);
		memcpy(repairer_, television.repairer_, REPAIRER_MAX_SIZE);
		memcpy(owner_, television.owner_, OWNER_MAX_SIZE);

		// копирование значений
		diagonal_ = television.diagonal_;
		price_ = television.price_;
	}
	

	// деструктор
	~Television()
	{
		delete[]manufacturer_;
		delete[]model_;
		delete[]defect_;
		delete[]repairer_;
		delete[]owner_;
	}


	// операция присваивания
	Television& operator=(const Television& television)
	{
		// копирование строковых полей
		memcpy(manufacturer_, television.manufacturer_, MANUFACTURER_MAX_SIZE);
		memcpy(model_, television.model_, MODEL_MAX_SIZE);
		memcpy(defect_, television.defect_, DEFECT_MAX_SIZE);
		memcpy(repairer_, television.repairer_, REPAIRER_MAX_SIZE);
		memcpy(owner_, television.owner_, OWNER_MAX_SIZE);

		// копирование значений
		diagonal_ = television.diagonal_;
		price_ = television.price_;

		return *this;
	}

#pragma endregion

#pragma region Сеттеры и геттеры

	// сеттер manufacturer_
	void setManufacturer(const char* manufacturer)
	{
		// длина строки
		size_t len = strlen(manufacturer);

		// если строка слишком длинная или короткая
		if (len > MANUFACTURER_MAX_SIZE or len < MANUFACTURER_MIN_SIZE)
			throw exception("App: Некорректное значение");

		// копирование 
		strncpy(manufacturer_, manufacturer, MANUFACTURER_MAX_SIZE);
	}

	// геттер manufacturer_
	const char* const getManufactures() { return manufacturer_; }


	// сеттер model_
	void setModel(const char* model)
	{
		// длина строки
		size_t len = strlen(model);

		// если строка слишком длинная или короткая
		if (len > MODEL_MAX_SIZE or len < MODEL_MIN_SIZE)
			throw exception("App: Некорректное значение");

		// копирование 
		strncpy(model_, model, MODEL_MAX_SIZE);
	}

	// геттер model_
	const char* const getModel() { return model_; }

	
	// сеттер diagonal_
	void setDiagonal(double diagonal)
	{
		// если значение некорректно
		if (diagonal > DIAGONAL_MAX or diagonal < DIAGONAL_MIN)
			throw exception("App: Некорректное значение");

		// копирование 
		diagonal_ = diagonal;
	}

	// геттер diagonal_
	double getDiagonal() { return diagonal_; }


	// сеттер defect_
	void setDefect(const char* defect)
	{
		// длина строки
		size_t len = strlen(defect);

		// если строка слишком длинная или короткая
		if (len > DEFECT_MAX_SIZE or len < DEFECT_MIN_SIZE)
			throw exception("App: Некорректное значение");

		// копирование 
		strncpy(defect_, defect, DEFECT_MAX_SIZE);
	}

	// геттер defect_
	const char* const getDefect() { return defect_; }


	// сеттер repairer_
	void setRepairer(const char* repairer)
	{
		// длина строки
		size_t len = strlen(repairer);

		// если строка слишком длинная или короткая
		if (len > REPAIRER_MAX_SIZE or len < REPAIRER_MIN_SIZE)
			throw exception("App: Некорректное значение");

		// копирование 
		strncpy(repairer_, repairer, REPAIRER_MAX_SIZE);
	}

	// геттер repairer_
	const char* const getRepairer() { return repairer_; }


	// сеттер owner_
	void setOwner(const char* owner)
	{
		// длина строки
		size_t len = strlen(owner);

		// если строка слишком длинная или короткая
		if (len > OWNER_MAX_SIZE or len < OWNER_MIN_SIZE)
			throw exception("App: Некорректное значение");

		// копирование 
		strncpy(owner_, owner, OWNER_MAX_SIZE);
	}

	// геттер owner_
	const char* const getOwner() { return owner_; }


	// сеттер price_
	void setPrice(int price)
	{
		// если значение некорректно
		if (price > PRICE_MAX or price < PRICE_MIN)
			throw exception("App: Некорректное значение");

		// копирование 
		price_ = price;
	}

	// геттер price_
	int getPrice() { return price_; }

#pragma endregion

#pragma region Методы

	// запись в бинарный файл
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

	// чтение из бинарного файла
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

