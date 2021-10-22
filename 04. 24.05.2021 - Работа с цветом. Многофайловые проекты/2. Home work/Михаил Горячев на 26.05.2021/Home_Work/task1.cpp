#include "pch.h"
#include "Conoid.h"

// ��������� ������ ���������� ������
void generConoid(Conoid* conoid, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// ������
		conoid[i].setHeight(getRand(1., 50.));

		// ������ 1
		conoid[i].setRadius1(getRand(1., 50.));
		
		// ������ 2
		conoid[i].setRadius2(getRand(1., 50.));

		// ���� ������ 1 ������ ������� 2
		if (conoid[i].getRadius1() < conoid[i].getRadius2())
		{
			double tmp = conoid[i].getRadius1();
			conoid[i].setRadius1(conoid[i].getRadius2());
			conoid[i].setRadius2(tmp);
		}
	}

}

// ���������� ������� ������ � ������������ �������� ������
int maximumIndex(Conoid** conoid, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (conoid[max][0].MathS() < conoid[i + 1][0].MathS())
		{
			max = i + 1;
		}
	}

	return max;
}

// ����� ������
double summV(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

// ����� �������
double summS(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableConoids(const char* title, Conoid** conoids, int n, int maxIndex)
{
	setColor(headerColor);

	cout << title
		<< "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n"
		<< "\t    |  N  |    ������, R    |    ������, r   |    ������, H   |   �������, S   |    �����, V    |\n"
		<< "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n";

	setColor(mainColor);

	// ������� ������ ������� ���������, � ���������� ������
	// ������ � ����������� �������, ����� � ����� ���� ������
	// ������� �������� "��������"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(conoids[i][0].MathS() == conoids[maxIndex][0].MathS() ? acctColor : mainColor);

		setColor(headerColor);

		cout << "    " << "| " << setw(3) << i + 1;	

		setColor(mainColor);

		// ���������� ������
		cout << conoids[i][0];

		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i

	setColor(headerColor);

	cout << "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n";

	setColor(mainColor);
} // showTable

// ������������� ������� ������ Conoid. ���������� �������� ������ << 
ostream& operator<<(ostream& link, Conoid& con)
{
	link << " | " << setw(15) << con.radius1_
		<< " | " << setw(14) << con.radius2_
		<< " | " << setw(14) << con.height_
		<< " | " << setw(14) << con.MathS()
		<< " | " << setw(14) << con.MathV()
		<< " |";

	return link;
}

// ������������� ������� ������ Conoid. ���������� �������� ����� >> 
istream& operator>>(istream& link, Conoid& con)
{
	cout << "������� ������ ������: ";
	link >> con.height_;

	cout << endl;

	cout << "������� ������ 1: ";

	cout << endl;

	link >> con.radius1_;

	cout << endl;

	cout << "������� ������ 2: ";

	cout << endl;

	link >> con.radius2_;
	
	// ���� ������ 1 ������ ������� 2
	if (con.radius1_ < con.radius2_)
	{
		double tmp = con.radius1_;
		con.radius1_ = con.radius2_;
		con.radius2_ = tmp;
	}

	return link;

}

// ��������� �������
double allSummV(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathV();
	}

	return num;
}

// ����� �������
double allSummS(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathS();
	}

	return num;
}