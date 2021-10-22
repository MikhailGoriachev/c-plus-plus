#include "pch.h"
#include "Utils.h"
#include "App.h"

// -------------------------------------------------------------------------

// ��������� ������� ��� ������ ��������� ���������
void App::demoVector()
{
	showNavBarMessage(hintColor, "  ��������� ������� ��� ������ ��������� ���������");

    // ������������ ������ �� ��������� ������������ �����, ��������
    // ��������� ������� � ����������. 
	vector<double> v1(getRand(8, 12));

	// ���� ��������� �������� � ����������
	double lo, hi;
	setCursorVisible(true);
	showInputLine("\n\n\n\n    �������� �������� �������: ", 20, hintColor);
	cin >> lo >> hi;
	setCursorVisible(false);
	setColor(mainColor);

	// �������� ������������ �����
	if (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		throw exception("������� �� �����");
	} // if

	if (lo >= hi)
		throw exception("������ ����� ��������� �������� �������");

	// ��������� ������� � ����� ������� � �������
	generate(v1.begin(), v1.end(), [lo, hi]() { return getRand(lo, hi); });
	showVectorPositive("\n\n    ������ ��� ���������:\n", v1);

	// ��������� ������ � ��������������� ������ ������ ��� ������
	// ���������� ���������
	string fileName = "dbl_vector.txt";
	saveVector(fileName, v1);
	cout << "\n\n    ���� " << fileName << " �������\n";

	v1.clear();

	// ��������� ������ �� ���������������� ������ ����� ��� ������
    // ���������� ���������.
	loadVector(fileName, v1);
    
    // �������� ��� �������� ������� �� 2.
	transform(v1.begin(), v1.end(), v1.begin(), [](double x) { return x + x; });
	showVectorPositive("\n\n    ������ ����� �������� ���������:\n", v1);

	// ��������� ������ � ��������������� ������ ������ ��� ������
	// ���������� ���������
	saveVector(fileName, v1);
	cout << "\n    ������ � ���������� ���������� ������� � ���� " << fileName << "\n";
	v1.clear();
	
	// ��������� ������ �� ���������������� ������ ����� ��� ������
    // ���������� ���������.
	loadVector(fileName, v1);

	// ����������� ������ �� ������� � ������������� � ������ �������.
	sort(v1.begin(), v1.end(), [](double x, double y) { return x >= 0 && y < 0; });
	
	// ������� ������ � �������� ���������� ������������� ���������
	showVectorPositive("\n\n    ������ ���������� �� ������� \"������������� � ������ �������\"\n", v1);

	// ��������� ������ �� ���������������� ������ ����� ��� ������ ����������
    // ���������.
	loadVector(fileName, v1);
	
	// ����������� ������ �� ��������.
	sort(v1.begin(), v1.end(), greater<double>());
	
	// ������� ������ � �������� ���������� ������������� ���������
	showVectorNegative("\n\n    ������ ���������� �� ��������\n", v1);
} // App::demoVector


// ----------------------------------------------------------------------------

// ����� ������� � ���������� ������ ������������� ���������
void App::showVectorPositive(const string& title, const vector<double>& v)
{
	cout << title << fixed << setprecision(2) << "    ";
	int w;  // ������ ���� ������
	int c;  // ������� ���������� ���������
	int m;  // ������� ������ ����� ������ ��������� ���������� ���������
	
	auto outPositive = [w, c, m](double value) mutable
	{
		cout << color(value >= 0 ? hintColor : mainColor) << setw(w) << value << "  "
			<< color(mainColor) << " ";
		if (++c % m == 0) cout << "\n    ";
	};

	for_each(v.begin(), v.end(), outPositive);
} // App::showVectorPositive

// ����� ������� � ���������� ������ ������������� ���������
void App::showVectorNegative(const string& title, const vector<double>& v)
{
	cout << title << fixed << setprecision(2) << "    ";

	int w;  // ������ ���� ������
	int c;  // ������� ���������� ���������
	int m;  // ������� ������ ����� ������ ��������� ���������� ���������

	auto outNegative = [w, c, m](double value) mutable
	{
		cout << color(value < 0 ? hintColor : mainColor) << setw(w) << value << "  "
			<< color(mainColor) << " ";
		if (++c % m == 0) cout << "\n    ";
	};

	for_each(v.begin(), v.end(), outNegative);
} // App::showVectorNegative


// ���������� ������� � ��������������� ������ ������
void App::saveVector(const string &fileName, vector<double> &v)
{
	// ����� ������
	ofstream ofs(fileName);
	if (!ofs.is_open())
		throw exception(("�� ���� ������� ���� " + fileName + " ��� ������").c_str());

	// �������� ������
	ostream_iterator<double> ofs_stream(ofs, "\n");

	for (auto element : v) {
		*ofs_stream = element;   // ����� � �����
		++ofs_stream;            // ����������� �� ������

		// ;)
		// ofs << element << endl;
	} // for element
	
	ofs.close();
}

// �������� ������� �� ���������������� ������ �����
void App::loadVector(const string& fileName, vector<double> &v)
{
	ifstream ifs(fileName);
	if (!ifs.is_open())
		throw exception(("�� ���� ������� ���� " + fileName + " ��� ������").c_str());
	
	istream_iterator<double> itStream(ifs);

	// ������ ��� ��������� ������� ������,����� �� �����������
	// ���������� � ���
	v.clear();
	
	while (itStream != istream_iterator<double>()) {
		double value = *itStream;   // ����������� ������
		v.push_back(value);
		++itStream;
	} // while
	
	ifs.close();
} //App::loadVector

// ----------------------------------------------------------------

// ������ ������ �� ��������� � ��������� ���� (��������������� ����� ������)
void App::demoInitializeAndWrite()
{
	showNavBarMessage(hintColor, "  ������ ������ �� ��������� � ��������� ���� (��������������� ����� ������)");

	// ���� ��������� ��� ��� - ����������� ��
	if (buses_.empty())
		initialize();

	// �������� ��������� � ��������������� ����� ������
	saveToStream();

	// � ��� �������� ��������� ���������, ������� ��������� � �������
	loadFromStream();
	showBuses(buses_, "\n\n\n\n    ��������� ��������� ��� ��������� � ����������:\n");
} // App::demoInitialize



// ������ ������ �� ��������� �� ���������� ����� (���������������� ������ �����)
void App::demoReadAndShow()
{
	showNavBarMessage(hintColor, "  ������ ������ �� ��������� �� ���������� ����� "
		"(���������������� ������ �����)");

	// ���������� ������ �� ���������������� ������ �����
	loadFromStream();

	showBuses(buses_, "\n\n\n\n    ��������� ��������� ��� ��������� � ����������:\n");
} // App::demoReadAndShow


// ����� ������ �� ��������� ��� ������ ��������� for_each() � ���������� ��������
void App::demoShowBuses()
{
	showNavBarMessage(hintColor, "  ����� ������ �� ��������� ��� ������ ��������� "
		"for_each() � ���������� ��������");

	// ���� ��������� ��� �� ��������� - ��������� �� �����, ����
	// ��� � ����� ������ ��� - ��� ����� ������������� ����������
	if (buses_.empty())
		loadFromStream();
	
	showBuses(buses_, "\n\n\n\n    �������� ��� ��������� � ����������:\n");
} // App::demoShowBuses


// ����������� ��������� ��������� �� ��������������� �������, ������������ sort()
void App::demoOrderByRegNumber()
{
	showNavBarMessage(hintColor, "  ����������� ��������� ��������� �� ��������������� "
		"�������, ������������ sort() � ��������� �������");

	// ���� ��������� ��� �� ��������� - ��������� �� �����, ����
	// ��� � ����� ������ ��� - ��� ����� ������������� ����������
	if (buses_.empty())
		loadFromStream();

	// ������-��������� ��� ���������� ��������� �� ��������������� �������
	auto predicate = [](const Bus &bus1, const Bus &bus2)
	{
		return bus1.getRegNum() < bus2.getRegNum();
	};

	sort(buses_.begin(), buses_.end(), predicate);
	showBuses(buses_, "\n\n\n\n    ��������, ������������ �� ��������������� �������:\n");
} // App::demoOrderByRegNumber 

// ����������� ��������� ��������� �� ������� � ��������� ��������, ������������ sort()
void App::demoOrderByFullName()
{
	showNavBarMessage(hintColor, "  ����������� ��������� ��������� �� ������� � "
		"��������� ��������, ������������ sort() � ��������� �������");

	// ���� ��������� ��� �� ��������� - ��������� �� �����, ����
	// ��� � ����� ������ ��� - ��� ����� ������������� ����������
	if (buses_.empty())
		loadFromStream();

	// ������������� ������-��������� ��� ���������� ��������� �� ������� � ��������� ��������
	auto lambda = [](const Bus& bus1, const Bus& bus2)
	{
		return bus1.getFullName() < bus2.getFullName();
	};
	
	sort(buses_.begin(), buses_.end(), lambda);
	showBuses(buses_, "\n\n\n\n    ��������, ������������ �� ������� � ��������� ��������:\n");
} // App::demoOrderByFullName


// ----------------------------------------------------------------

#pragma region ��������������� ������ � �������� ��� ��������� ���������
void App::showBuses(const vector<Bus>& buses, const string& title)
{
	int row = 1;
	
	// ������� - ��������� ���
	auto outBus = [row](const Bus &bus) mutable 
	{
		cout << "   " << bus.toTableRow(row++) << endl;
	};
	
	cout << title << Bus::header;
	for_each(buses_.begin(), buses_.end(), outBus);
	cout << Bus::footer;
} // App::showBuses

// �������� ��������� ��������� �� ������
void App::loadFromStream()
{
	// ������ �� ����� ��� ������ ��������� ������ �����
	ifstream ifs(fileName_);
	if (!ifs.is_open())
		throw exception(("�� ���� ������� ���� " + fileName_ + " ��� ������").c_str());

	// �������� �������� ��� ����� �� ���������������� ������ 
	istream_iterator<Bus> stream_it(ifs);

	// ����� ������� ������ ������ ��������, �.�. �� ���������
	// ���������� � ������������� ������� ����������� �������,
	// ������ ������������ ������ ������ ������ � �������
	buses_.clear();
	while (stream_it != istream_iterator<Bus>()) {
		Bus bus = *stream_it;   // ����������� ������
		++stream_it;
		
		buses_.push_back(bus);
	}
	ifs.close();
} // App::loadFromStream

// ���������� ��������� ��������� � �����
void App::saveToStream()
{
	// ��������� �������� ������ ��� ������
	ofstream ofs(fileName_);
	if (!ofs.is_open())
		throw exception(("�� ���� ������� ���� " + fileName_ + " ��� ������").c_str());
	
	ostream_iterator<Bus> ofs_stream(ofs, "");
	for (auto bus : buses_) {
		*ofs_stream = bus;  // ����� � ����� ������
		++ofs_stream;       // ����������� �� ������
	} // for bus
	ofs.close();
} // App::saveToStream

// ��������� ������������ ��������� ���������
void App::initialize()
{
	// ��������� ������ ��� ���������� 
	buses_ = {
		Bus("��512�", "��������� �.�.",      "13",     "0"),
		Bus("��511�", "��������� �.�.",      "11",    "11"),
		Bus("��523�", "��������� �.�.",      "12",   "42�"),
		Bus("��506�", "�������� �.�.",       "42",    "42"),
		Bus("��514�", "����������� �.�.",   "85�",   "85�"),
		Bus("��503�", "����� �.�.",          "35",    "35"),
		Bus("��501�", "����� �.�.",         "76�",     "0"),
		Bus("��121�", "�������� �.�.",      "121�", "121�"),
		Bus("��012�", "������������� �.�.", "119�",    "0"),
		Bus("��001�", "������� �.�.",       "121�", "121�"),
		Bus()
	};
} // App::initialize

// �������� ������������� �����
bool App::fileExists(const string& fileName)
{
	// ��������� ���� ��� ������, ���� ������� - ������, ����
	// ���������� � ��������
	ifstream ifs(fileName);
	bool exists = ifs.is_open();
	ifs.close();

	return exists;
} // App::fileExists