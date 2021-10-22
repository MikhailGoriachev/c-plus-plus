#include "pch.h"
#include "Figures.h"

// ���������� �������� ������������
Figures &Figures::operator=(const Figures &figures)
{
    // delete[] triangles_;
    // triangles_ = new Triangle[figures.length_];
    // 
    // length_ = figures.length_;
    // for(int i = 0; i < figures.length_; ++i)
    //     triangles_[i] = figures.triangles_[i];
    setData(figures.triangles_, figures.length_);
    return *this;
} // Figures::operator=

// �������� ��������������
Triangle &Figures::operator[](int index) const
{
    if (index < 0 || index >= length_)
        throw exception("������ ������� �� ������� �������");

    return triangles_[index];
} // Figures::operator[]

//  ��������� 30.05.2019 - ������������� �������� [] - �������������� �� ����� ������������
// ���������� ������ ����������� � �������� ������ - ������� �������� ����������� ����
Triangle &Figures::operator[](char *name) const
{
    int index = -1;

    // ����� ������������ �� �����
    for (int i = 0; i < length_; i++) {
        if (strcmp(triangles_[i].getName(), name) == 0) {
            index = i;
            break;
        } // if
    } // for i

    // ������� �� �� ��������� �������
    if (index < 0) {
        char buf[1024];
        sprintf(buf, "�� ������ ������������ � ������ %s", name);
        throw exception(buf);
    } // if

    return triangles_[index];
} // Figures::operator[]

// ������� �������� triangle � ����� ������� ������������� triangles_
Figures &Figures::operator&(const Triangle &triangle)
{
    // ��������� ������
    Triangle *temp = new Triangle[length_ + 1];

    // �������� ��� �������� �� ��������� ������� �� ���������
    // � ��������� ����� ������� � ����� ���������� �������
    for (int i = 0; i < length_; i++)
        temp[i] = triangles_[i];
    temp[length_] = triangle;

    // ���������� ������, ������� ������ ��������, ��������� 
    // ��������� ������ ������ Figures ��������� �� ����� ������
    delete[] triangles_;
    triangles_ = temp;
    length_++;

    return *this;
} // Figures::operator&

// �������� �������� �� ������� �� �������
Figures &Figures::operator|(int index)
{
    // ������ �� ��������������� ������� ���������� �������� �������
    if (index < 0 || index > length_-1)
        throw exception("������������ ������ �������� ������� ��� �������� ��������");
    
    Triangle *temp = new Triangle[length_-1];

    for (int i = 0, k = 0; i < length_; i++) {
        // �� ���������� �� ��������������� ������ ��������� �������
        if (index == i) continue;

        // �������� ��������� �������� �� ��������������� ������
        temp[k++] = triangles_[i];
    } // for i

    delete[] triangles_;
    triangles_ = temp;
    --length_;
    return *this;
} // Figures::operator|

// �������� �������� �� ������� �� ����� ������������
Figures &Figures::operator|(char *name)
{
    // ����� ����������� � �������� ������ � �������, �������
    // ������ ������������
    // ���� ��� ������ ������������ - ����������� ����������
    int index = -1;
    for (int i = 0; i < length_; i++) {
        if (strcmp(triangles_[i].getName(), name) == 0) {
            index = i;
            break;
        } // if
    } // for i

    // ������� �� ���������� ������������ � �������� ������ - ������
    // ����������
    if (index == -1) {
        ostringstream oss;
        oss << "�� ������ ����������� � ������ \"" << name << "\""; 
        throw exception(oss.str().c_str());
    } // if

    // ����������� ������ - �������� �������� �������� �� �������
    *this | index;

    return *this;
} // Figures::operator|


Figures &Figures::operator()(int index, const Triangle &triangle)
{
    // ��������� ������
    Triangle *temp = new Triangle[length_ + 1];

    // �������� ��� �������� �� ��������� ������� �� ���������
    // � ��������� ����� ������� � �������� ������� ���������� 
    // �������
    for (int i = 0, k = 0; i < length_; i++) {
        // ������� �������� � �������� �������
        if (i == index) temp[k++] = triangle;

        // ����������� ��������� ��������� �������
        temp[k++] = triangles_[i];
    } // for i

    // ���������� ������, ������� ������ ��������, ��������� 
    // ��������� ������ ������ Figures ��������� �� ����� ������
    delete[] triangles_;
    triangles_ = temp;
    length_++;

    return *this;
} // Figures::operator()

// �������������� ������� �������������
Figures Figures::operator!() const
{
    Figures newFigures(*this);

    // ������ ���������� �������, ������ �������
    // 0 � length-1, ����� 1 � length-2,... �����
    // ��������� n ������ ������
    int n = length_ / 2;
    for (int i = 0, j = length_-1; i < n; ++i, --j) {
        newFigures.swap(i, j);
    } // for i

    return newFigures;
} // Figures::operator!

// ����� ������� i-�� � j-�� ��������� ������� ��������
void Figures::swap(int i, int j) const
{
    // Triangle temp(triangles_[i]); 
    Triangle temp = triangles_[i];
    triangles_[i] = triangles_[j];
    triangles_[j] = temp;
} // Figures::swap

// ���������� ������� ������������� �� ����������� ��������
// �� ��������� �������� ������-������� �� ��������  
Figures Figures::operator~() const
{
	// ������� ����� ������ - �� �������
    Figures newFigures(*this);
	
    newFigures.quickSort(0, newFigures.length_-1);  
    return newFigures;    
} // Figures::operator~


// start - ������ ������ ����� �������
// end   - ������ ����� ����� �������
void Figures::quickSort(int start, int end) {
   	// ������� ���������� ��������
    if (start >= end) return;

	// ��������� �������� ���������� �� ��������� ������
    int i = start, j = end;                      // ��� ������ ���������
    int baseElement = start + (end - start) / 2; // ������ ���������� ������� �������� �������

	// �������� �� �������������� ����� �������, ��������
	// ������� �������� �������� � ������ �������� ������� 
	// (�� �������� ��������), �������� ������� �������� 
	// �������� �� ������ �������� ������� (����� ��������)
    while (i < j) {
		// �������� - �������� �������� � �������� ���������
		// (������� �������)
        Triangle value = triangles_[baseElement];  
       
    	// �������� �� ������ � ��������, ���� �� ������ ������� => �������� 
    	// (������� ��������)
        // while (i < baseElement && (array[i] <= value)) i++;
        while (i < baseElement && (compareByArea(triangles_[i], value) <= 0)) i++;
        
    	// �������� �� ����� � ��������, ���� �� ������ ������� <= ��������
		// ������ ��������
        // while (j > baseElement && (array[j] >= value)) j--;
        while (j > baseElement && (compareByArea(triangles_[j], value) >= 0)) j--;

		// ���� ��� ��������, ����� ������� ��������� ��������
		// ������� --- ������� --- ������� ###>  ������� --- ������� --- �������
        if (i < j) { 
			// ������ ������� �������� � ���������� �������
            this->swap(i, j);  

            // ���� ����� ����� �� �������� - ��� ��������� ��� ������
            // ���������� �������� ������, ����� ���������� ��������
			// �� �������
            if (i == baseElement) baseElement = j;

            // ���� ������ ����� �� �������� - ��� ��������� ��� ������
            // ���������� �������� ����� ��� ����������� ��������
            else if (j == baseElement)  baseElement = i;
        } // if
    } // while

    // ����������� ����� � ����� �������� ������
    quickSort(start, baseElement);          // �� ������ ������� �� cur
    quickSort(baseElement + 1, end);      // �� cur+1 �� ����� �������
} // quickSort

// ���������� ��� ���������� �� �������
// -1
//  0
//  1
int Figures::compareByArea(const Triangle &tr1, const Triangle &tr2)
{
    int result = 0;

	// ��� ��������� ������� � 
	double area1 = tr1.area();
	double area2 = tr2.area();
	
    if (area1 > area2)
        result = 1;
    else if (area1 < area2)
        result = -1;

    return  result;
} // Figures::compareByArea


// �������� ������ ������� ������ Figures, ������ �����������
// ������� � ��������� ������
ostream &operator<<(ostream &os, const Figures &figures)
{
    for (int i = 0; i < figures.length_; i++)
        os << figures[i] << endl;

    return os;
} // operator<<
