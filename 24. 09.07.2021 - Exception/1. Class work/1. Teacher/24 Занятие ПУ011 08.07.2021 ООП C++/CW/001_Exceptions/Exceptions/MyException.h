#pragma once

// ����� ����������, ����� ���� ������
class MyException
{
	// ����� ��������� �� ������
	const int LEN_MSG = 101;
	char *msg_;      

public:
	MyException(): msg_(new char[LEN_MSG])
	{
		strncpy(msg_, "��������� �� ���������", LEN_MSG-1);
	}

    MyException(const char *msg): msg_(new char[LEN_MSG]) 
	{
		strncpy(msg_, msg, LEN_MSG-1);
	}

    MyException(const MyException &myException): msg_(new char[LEN_MSG]) 
	{
		strcpy(msg_, myException.msg_);
	}

	~MyException() { delete[] msg_; }

	friend ostream &operator<<(ostream &os, const MyException &myException)
	{
		os << myException.msg_;
		return os;
	}
};

