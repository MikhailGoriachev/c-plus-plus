#include "DequeChar.h"

#pragma region ������������ � ���������� 

// ����������� ����������������
DequeChar::DequeChar(int size)
{
	// ���� ������������ size ������ ��� ����� ����
	if (size <= 0)
		throw exception("DequeChar: ����� ������� ������ ���� ������ ����!");

	// ��������� back_ � ������
	back_ = 0;

	// ���������� size
	size_ = size;

	// ��������� ������ ��� �������-���������� � ���������� ��� ������
	data_ = new char[size_] { 0 };
}

// ���������� �� ������ ������� 
DequeChar::DequeChar(char* arr, int size)
{
	// ���� ������������ size ������ ��� ����� ����
	if (size <= 0)
		throw exception("DequeChar: ����� ������������� ������� ������ ���� ������ ����!");

	// ���� ��������� �� ������ arr ����� �������� nullptr
	if (arr == nullptr)
		throw exception("DequeChar: ������������� ������� �� ����������!");

	// ��������� back_ � ������
	back_ = 0;

	// ���������� size
	size_ = size;

	// ��������� ������ ��� ������-��������� 
	data_ = new char[size_];

	// ����������� ������� 
	for (int i = 0; i < size_; i++)
	{
		data_[i] = arr[i];
	}
}

// ���������� �����������
DequeChar::DequeChar(const DequeChar& dequeChar)
{
	// ����������� back_
	back_ = dequeChar.back_;

	// ����������� size_
	size_ = dequeChar.size_;

	// ��������� ������ ��� ������-���������
	data_ = new char[size_];

	// ����������� ��������� 
	for (int i = 0; i < size_; i++)
	{
		data_[i] = dequeChar.data_[i];
	}
}

// ����������
DequeChar::~DequeChar()
{
	// �������� ������ �� �������-����������
	delete[] data_;
}

#pragma endregion

#pragma region ������

#pragma region �������� � ������� ����

// �������� � ������ ����
void DequeChar::shift(char value)
{
	// ���� ��� ����������
	if (isFull())
		throw exception("DequeChar: ��� ����������!");

	// ����� ���� ������
	for (int i = back_; i > 0; i--)
	{
		data_[i] = data_[i - 1];
	}

	// ��������� �������� � ������ ����
	data_[0] = value;

	// ���������� back_
	back_++;
}

// ���������� ������� � ������ ����
void DequeChar::shiftAll(char* arr, int size)
{
	// ���� ������������ size ������ ��� ����� ����
	if (size <= 0)
		throw exception("DequeChar: ����� ������������� ������� ������ ���� ������ ����!");

	// ���� ��������� �� ������ arr ����� �������� nullptr
	if (arr == nullptr)
		throw exception("DequeChar: ������������� ������� �� ����������!");

	// ���������� ��������� � ������ ���� 
	for (int i = 0; i < size && !isFull(); i++)
	{
		// ���������� �������� � ������ ����
		shift(arr[i]);
	}
}

// ���������� ��������� ������� ����
char DequeChar::front() const
{
	// ���� ��� ����
	if (isEmpty())
		throw exception("DequeChar: ��� ����!");

	// ����������� ���������� �������� ����
	return data_[0];
}

// ����� ������� � ������ ����
char DequeChar::unshift()
{
	// ���� ��� ����
	if (isEmpty())
		throw exception("DequeChar: ��� ����!");

	// ���������� �������� ��������
	char tmp = data_[0];

	// ���������� back_
	back_--;

	// ����������� ��������� �����
	for (int i = 0; i < back_ - 1; i++)
	{
		data_[i] = data_[i + 1];
	}

	// ����������� ����������� ��������
	return tmp;
}

#pragma endregion

// ------------------------------------------------------------------------------

#pragma region �������� � ������ ����

// �������� � ����� ����
void DequeChar::push(char value)
{
	// ���� ��� ����������
	if (isFull())
		throw exception("DequeChar: ��� ����������!");

	// ���������� �������� � ���������� back_
	data_[back_++] = value;
}

// ���������� ������� � ����� ���� 
void DequeChar::pushAll(char* arr, int size)
{
	// ���� ����� ������� ������ ��� ����� ����
	if (size <= 0)
		throw exception("DequeChar: ����� ������������� ������� ������ ���� ������ ����!");

	// ���� ��������� �� ������ arr ����� �������� nullptr
	if (arr == nullptr)
		throw exception("DequeChar: ������������� ������� �� ����������!");

	// ���������� ��������� � ����� ����
	for (int i = 0; i < size && !isFull(); i++)
	{
		push(arr[i]);
	}
}

// ���������� ��������� ������� ���� 
char DequeChar::back() const
{
	// ���� ��� ���������
	if (isEmpty())
		throw exception("DequeChar: ��� ����!");

	// ����������� ���������� ��������
	return data_[back_ - 1];
}

// ����� ������� � ����� ���� 
char DequeChar::pop()
{
	// ���� ��� ����
	if (isEmpty())
		throw exception("DequeChar: ��� ����!");

	// ���������� back_ � ����������� ���������� ��������
	return data_[--back_];
}

#pragma endregion

// �������� ����
void DequeChar::clear()
{
	back_ = 0;
}

// ����������� ���� 
bool DequeChar::isEmpty() const
{
	return back_ == 0;
}

// ������������ ���� 
bool DequeChar::isFull() const
{
	return back_ == size_;
}

// ����� ���� 
int DequeChar::counter() const 
{
	return back_;
}

// ������ ����
int DequeChar::size() const 
{ 
	return size_; 
}

// ���������� �������� ������������
DequeChar& DequeChar::operator=(const DequeChar& dequeChar)
{
	// ������ �� ����������������
	if (this == &dequeChar) return *this;

	// ���������� size_
	size_ = dequeChar.size_;

	// ���������� back_
	back_ = dequeChar.back_;

	// �������� ������ �� �������-���������� 
	delete[] data_;

	// ��������� ������ ��� ������-���������
	data_ = new char[size_];

	// ����������� �������-���������� 
	for (int i = 0; i < size_; i++)
	{
		data_[i] = dequeChar.data_[i];
	}

	// ����������� ������ �� ��� ������
	return *this;
}

#pragma endregion

#pragma region ������������� ������� 

// ����� �����, n - ���������� ���������
ostream& showLine(ostream& os, int n)
{
	os << "\t+��������������������+";

	// ����� ����� ��� ���������� ���������
	for (size_t i = 0; i < n; i++)
	{
		os << "����+";
	}

	os << "\n";

	return os;
}

// ���������� �������� ������
ostream& operator<<(ostream& os, const DequeChar& dequeChar)
{
	// ����� �����
	os << "\t+��������������������+�������������������+\n"
		<< "\t|   ����. ������: " << setw(2) << dequeChar.size_ << " |   ���. ������: " << setw(2) << dequeChar.back_ << " |\n";

	// ����� �����
	showLine(os, dequeChar.back_ < 4 ? 4 : dequeChar.back_);

	// ���� ��� ����
	if (dequeChar.back_ == 0)
		os << "\t|                                        |\n"
			<< "\t|                 ��� ����               |\n"
			<< "\t|                                        |\n"
			<< "\t+��������������������+�������������������+\n";

	// ���� ���� ��������
	else
	{
		// ����� ������� ��������
		os << "\t|  ������ ��������:  |";
		for (int i = 0; i < dequeChar.back_; i++)
		{
			os << " " << setw(2) << i << " |";
		}

		os << "\n";

		// ����� �����
		showLine(os, dequeChar.back_);

		// ����� ���������
		os << "\t|      ��������:     |";
		for (int i = 0; i < dequeChar.back_; i++)
		{
			// ������
			char tmp = dequeChar.data_[i];

			short clOld = getColor();

			// ������� ����
			short cl = tmp >= 'a' && tmp <= 'z' ? BLUE_ON_BLACK : RED_ON_BLACK;

			// ���� ����� ��������� ��� �������;

			os << color(cl) << "  " << dequeChar.data_[i] << " " << color(clOld) << "|";
		}

		os << "\n";

		// ����� �����
		showLine(os, dequeChar.back_);

	}


	return os;
}

#pragma endregion
