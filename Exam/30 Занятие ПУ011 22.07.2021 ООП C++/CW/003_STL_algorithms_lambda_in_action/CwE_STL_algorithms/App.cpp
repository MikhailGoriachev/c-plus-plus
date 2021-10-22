#include "pch.h"
#include "App.h"
#include <algorithm>
#include <numeric>

// ���������� ������������� ��������� �������
int App::variant16a()
{
	return (int)count_if(data_.begin(), data_.end(), [](double x) { return x < 0; });
} // App::variant16a

// ����� ������� ��������� ����� ������������ �� ������ ��������
double App::variant16b()
{
	// �������� �������� �� ����������� �� ������ �������
	auto it = min_element(data_.begin(), data_.end(), 
		[](double x, double y) {return abs(x) < abs(y); });
	++it; // �������� �� ��������� �������

	// ����� ������� ��������� ����� ������������ �� ������ ��������
	return accumulate(it, data_.end(), 0., 
		[](double predRes, double item) {return predRes + abs(item); });
} // App::variant16b


// �������� ��� ������������� �������� ������� ����������
// � ����������� ������ �� �����������
void App::variant16c()
{
	transform(data_.begin(), data_.end(), data_.begin(), 
		[](double x) { return x < 0 ? x * x : x; });
	sort(data_.begin(), data_.end());
} // App::variant16c

// ������������ ������������� ��������� �������
double App::variant19a()
{
	return accumulate(data_.begin(), data_.end(), 1.,
		[](double result, double item)
		{
			return result * (item < 0 ? item : 1.);
		});
} // App::variant19a

// ����� ������������� ��������� �� ������������� 
// �������� � �������
double App::variant19b()
{
	auto it = max_element(data_.begin(), data_.end());
	return accumulate(data_.begin(), it, 0.,
		[](double result, double item)
		{
			return result + (item > 0 ? item : 0.);
		});
} // App::variant19b

// �������� ������� ���������� ��������� �� ��������
void App::variant19c()
{
	reverse(data_.begin(), data_.end());
} // App::variant19c

#pragma region ��������������� ������

// ����� ���������� � ������� ��� ������ ��������� for_each
// !!! ������ ��� ������� !!!
void App::show(string title) const
{
	int w = 8;
	int m = 10;
	int i = 0;
	cout << title << "    " << fixed << setprecision(3);
	for_each(data_.begin(), data_.end(),
		[w, m, i](double item) mutable
		{
			cout<< color(item < 0 ? infoColor : mainColor)
				<< setw(w) << item << "  "
				<< color(mainColor) << " ";
			if (++i % m == 0) cout << "\n    ";
		});
	cout << endl;
} // App::show

// ������������ ������� ��� ���������
void App::make()
{
	int n = getRand(8, 15);
	data_.resize(n);

	// ���������� ������� ���������� �������
	double lo = -10., hi = 10.;
	generate(data_.begin(), data_.end(), [lo, hi]() { return getRand(lo, hi); });
} // App::make

#pragma endregion