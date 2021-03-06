#include "App.h"
#include "pch.h"
#include "Conoid.h"
#include "Utils.h"
#include "ArrayConoid.h"
#include "func.h"
#include "Matrix.h"

#pragma region ??????? 1

/*
*	?????? 1. ???????? ?????, ??????????? ????????? ?????Conoid (?????? ???????? ?????????, ??????
*	??????? ?????????, ?????? ? ??? ????? double). ?????????????????????? (?????? ???: ?? ????????? ?
*	???????????? ? ?.?. ???????? ??? ???? ??????), ??????? ? ??????? (??? ???????????? ?????????
*	??????????? ? ???????? ?????????? exception), ?????? ??? ?????????? ??????? ? ?????? ?????????? ??????.
*	??????????? ????????:
*	?	++ ?????????? ? ??????????? ?????????? ? ?????????? ?? 1 ?????? ? ???????? ?????????, ??????????
*	?????????????
*	?	-- ?????????? ? ??????????? ?????????? ? ?????????? ?? 1 ?????? ? ???????? ?????????, ??????????
*	????????????? ???????? ??????, ??????????? ?????????? ??? ??????? ??? ????????????? ??????????
*	?	<<???????? ??????, ???????? ??????? ? ??????, ??????? ??????????? ? ????? ? ???? ?????? ???????
*	???????? ?????ArrayConoid, ???????? ???????????? ?????? ?? ????????? ??????? ? ???????? ?????? Conoid
*	? ?????? ????? ???????. ?????? ????????? ? ?????????????, ????????? ?????? ??? ????????????: ?? ?????????,
*	????????? ?????? ?? 3 ?????????, ??????????? ? ?????????? ? ??????????? ??????????? ?????????). ?????
*	???????????? ?????????? ??? ???????????? ??????, ??????? ???????? ????????? ???????.
*	??????? ? ??????? ? ?????? ArrayConoid ?? ??????????????, ?????????? ?????? ??????????? ????? size(),
*	???????????? ?????? ???????.
*	? ?????? ArrayConoid??????????? ????????:
*	?	?????????????? [], ??? ?????? ??????? ?? ?????????? ??????? ???????????? ??????????
*	?	<<?????? ??????? ? ???? ??????? (???????? ??????? ????????????????????? ????????? ??????)
*	?????????? ?????? ?????? ArrayConoid:
*	?	????? ??????? ??????? ???????? ??????? ? ??????????? ???????
*	?	????? ??????? ???????? ??????? ? ???????????? ????????.
*	? ?????????????? ????????????? ???????? ?????? ArrayConoid[]?????????? ??????? (??????????? ? ???????
*	?????? ?????? ArrayConoid ?? ??????):
*	?	?????????? ?????????? ?????? ???????
*	?	?????????? ????????? ??????? ??????????? ???????
*	?	????? ??????? ? ??????? ? ?????????? ?????? ??????/??????? ? ???????????? ????????.
*	???????? ?????? (?????????) ?????? ArrayConoid, ????????????????? ????????????? ??????.
*
*/

#pragma region ?????? ??????? 1
// ?????????? ??????? ?????? ? ???????????? ???????? ??????
int maximumIndex(ArrayConoid& conoids)
{
	int max = 0;

	for (size_t i = 1; i < conoids.size(); i++)
	{
		if (conoids[max].MathS() < conoids[i].MathS())
		{
			max = i;
		}
	}

	return max;
}

// ????? ??????
double App::summV(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

// ????? ???????
double App::summS(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}

// ????? ??????? ????????? ? ????????? ???????, ?????????????? ?????: ? Alt+0151
ostream& operator<<(ostream& os, ArrayConoid& arr)
{
	setColor(headerColor);

	os  << "\t    +?????+?????????????????+????????????????+????????????????+????????????????+????????????????+\n"
		<< "\t    |  N  |    ??????, R    |    ??????, r   |    ??????, H   |   ???????, S   |    ?????, V    |\n"
		<< "\t    +?????+?????????????????+????????????????+????????????????+????????????????+????????????????+\n";

	setColor(mainColor);

	size_t maxIndex = maximumIndex(arr);

	// ??????? ?????? ??????? ?????????, ? ?????????? ??????
	// ?????? ? ??????????? ???????, ????? ? ????? ???? ??????
	// ??????? ???????? "????????"
	for (size_t i = 0; i < arr.size_; ++i) {
		cout << "\t";
		setColor(arr[i].MathS() == arr[maxIndex].MathS() ? acctColor : mainColor);

		//setColor(headerColor);

		cout << "    " << "| " << setw(3) << i + 1;

		//setColor(mainColor);

		// ?????????? ??????
		cout << arr[i];

		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i

	setColor(headerColor);

	cout << "\t    +?????+?????????????????+????????????????+????????????????+????????????????+????????????????+\n";

	setColor(mainColor);

	return os;

} // showTable

// ????????????? ??????? ?????? Conoid. ?????????? ???????? ?????? << 
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

// ????????????? ??????? ?????? Conoid. ?????????? ???????? ????? >> 
/*istream& operator>>(istream& link, Conoid& con)
{
	link >> con.height_ >> con.radius1_ >> con.radius2_;

	// ???? ?????? ?????? ??? ????? ????
	if (con.height_ <= 0)
	{
		throw exception("????????? ?????? ?????? ???? ?????? ????!");
	}

	// ???? ?????? ????????? ?????? ??????? ???????
	if (con.radius1_ < con.radius2_)
	{
		throw exception("?????? ????????? ?????? ???? ?????? ??????? ???????!");
	}

	return link;
}*/

#pragma endregion

#pragma region ??????? 1 (????)
// ??????? 1
void App::task1()
{
	setColor(mainColor);

	cls();

	setColor(headerColor);

#pragma region ????? ???????
	cout << "\n\n\t\t\t\t??????? 1\n\n";

	cout << "\t\t???????? ?????, ??????????? ????????? ????? Conoid (?????? \n"
		<< "\t\t???????? ?????????, ?????? ??????? ?????????, ?????? ? ??? ????? double).  \n"
		<< "\t\t?????????? ???????????? (?????? ???: ?? ????????? ? ???????????? ? ?.?. \n"
		<< "\t\t???????? ??? ???? ??????), ??????? ? ??????? (??? ???????????? ????????? \n"
		<< "\t\t??????????? ? ???????? ?????????? exception), ?????? ??? ?????????? ??????? \n"
		<< "\t\t? ?????? ?????????? ??????.\n\n"
		<< "\t\t??????????? ????????:\n"
		<< "\t\t?????? ?????? ?????????? ?????? (??????? ? ??????, ??????? ???????????\n"
		<< "\t\t? ?????) ? ???? ?????? ???????. \n\n"
		<< "\t\t??????????? ???????? ???????? ??????:\n\n"
		<< "\t\t\t?	++ ?????????? ? ??????????? ?????????? ? ?????????? ?? 1 ?????? ? \n"
		<< "\t\t\t\t???????? ?????????, ?????????? ??????? ??????\n\n"
		<< "\t\t\t?	-- ?????????? ? ??????????? ?????????? ? ?????????? ?? 1 ?????? ? \n"
		<< "\t\t\t\t???????? ?????????, ?????????? ????????????? ???????? ??????, \n"
		<< "\t\t\t\t??????????? ?????????? ??? ??????? ??? ????????????? ??????????\n\n"
		<< "\t\t\t?	<< ???????? ??????, ???????? ??????? ? ??????, ??????? ??????????? ? \n"
		<< "\t\t\t\t????? ? ???? ?????? ??????? \n\n"
		<< "\t\t\t???????? ????? \n\n"
		<< "\t\t\tArrayConoid, ???????? ???????????? ?????? ?? ????????? ??????? ? ???????? \n"
		<< "\t\t\t?????? Conoid ? ?????? ????? ???????. ?????? ????????? ? ?????????????, \n"
		<< "\t\t\t????????? ?????? ??? ????????????: ?? ?????????, ????????? ?????? ?? 3 \n"
		<< "\t\t\t?????????, ??????????? ? ?????????? ? ??????????? ??????????? ?????????). \n"
		<< "\t\t\t????? ???????????? ?????????? ??? ???????????? ??????, ??????? ???????? \n"
		<< "\t\t\t????????? ???????.\n\n"
		<< "\t\t\t??????? ? ??????? ? ?????? ArrayConoid ?? ??????????????, ?????????? ?????? \n"
		<< "\t\t\t??????????? ????? size(), ???????????? ?????? ???????.\n\n"
		<< "\t\t\t? ?????? ArrayConoid??????????? ????????:\n\n"
		<< "\t\t\t?	?????????????? [], ??? ?????? ??????? ?? ?????????? ??????? \n"
		<< "\t\t\t\t???????????? ??????????\n\n"
		<< "\t\t\t?	<< ?????? ??????? ? ???? ??????? (???????? ??????? ???????? \n\n"
		<< "\t\t\t\t????????????? ????????? ??????)\n\n"
		<< "\t\t\t?????????? ?????? ?????? ArrayConoid:\n\n"
		<< "\t\t\t?	????? ??????? ??????? ???????? ??????? ? ??????????? ???????\n\n"
		<< "\t\t\t?	????? ??????? ???????? ??????? ? ???????????? ????????. \n\n"
		<< "\t\t\t? ?????????????? ????????????? ???????? ?????? ArrayConoid[] ?????????? \n"
		<< "\t\t\t??????? (??????????? ? ??????? ?????? ?????? ArrayConoid ?? ??????):\n\n"
		<< "\t\t\t?	?????????? ?????????? ?????? ???????\n\n"
		<< "\t\t\t?	?????????? ????????? ??????? ??????????? ???????\n\n"
		<< "\t\t\t?	????? ??????? ? ??????? ? ?????????? ?????? ??????/??????? ? \n"
		<< "\t\t\t\t???????????? ????????.\n\n"
		<< "\t\t\t???????? ?????? (?????????) ?????? ArrayConoid, ????????????????? \n"
		<< "\t\t\t????????????? ??????.\n\n";

	setColor(headerColor);

	getKey();

	cls();

#pragma endregion

	// ?????????? ?????????
	int size;

	setCursorVisible(true);

	// ???? ?????????? ??????????? ????????? ???????
	cout << "\n\n\t\t??????? ????????? ????????? ???????: ";

	cin >> size;

	if (size < 1)
	{
		// ????????? exception ?? ??? ??????, ???? ????? ??????? ???????????? ??????
		throw exception("?????????? ????????? ??????? ?????? ???? ?????? ????!");
	}

	// ???????? ??????
	cls();
	
	// ?????? ?????? ArrayConoid
	ArrayConoid arr = ArrayConoid(size);

	// ?????????? ??????? ?????????? ???????
	generConoid(arr);

	// ?????????? ???????
	setCursorVisible(false);

	// ?????? ??? ?????
	char n;

	// ?????????? ??? ???????? ? ??????????
	int a;

	size_t indexMin;
	size_t indexMax;
	size_t index;

	// ???????? ???????? ?????
	short cl;

	while (true)
	{
		cls();

		// ????? ???????
		cout << arr;

		setColor(headerColor);

		cout << setw(38) << " | " << setw(41) << right << "????????? ???????: " << allSummS(arr) << " |" << endl;

		cout << setw(38) << " | " << setw(41) << right << "????????? ?????: " << allSummV(arr) << " |" << endl;


		cout << "\n\n\n\n\t\t1. ?????????? ?????????? ? ???????????" << endl;
		cout << "\n\n\n\n\t\t2. ?????????? ?????????? ? ???????????" << endl;
		cout << "\n\n\n\n\t\t3. ????? ??????? ???????? ? ??????????? ???????" << endl;
		cout << "\n\n\n\n\t\t4. ????? ??????? ???????? ? ??????????? ????????" << endl;
		cout << "\n\n\n\n\n\n\t\tESC ?????" << endl;
		
		cout << "\n\n\n\t\t???????? ?????...";

		// ???????? ????? 
		while (true)
		{
			n = getKey("");

			// ???? ???????? n ?????? ? ???? ?? ???????
			if (n < '5' && n > '0')
			{
				// ????????? ???????
				setCursorVisible(true);

				cls();

				// ????? ???????
				cout << arr;

				setColor(headerColor);

				cout << setw(38) << " | " << setw(41) << right << "????????? ???????: " << allSummS(arr) << " |" << endl;

				cout << setw(38) << " | " << setw(41) << right << "????????? ?????: " << allSummV(arr) << " |" << endl;

				switch (n)
				{

					// 1. ?????????? ?????????? ? ???????????
				case '1':

					cout << "\n\n\t\t\t\t\t\t?????????? ?????????? ? ???????????\n\n" << endl;

					cout << "\t???????? ?????: ";
					cin >> a;

					index = a - 1;

					cout << "\n\n\t\t\t\t\t????? " << a << endl << endl;

					cout << "\t\t\t";

					cputs("????????? ??????????\n", resColor);

					cout << "\n\n\t\t\t\t\t???????????? ????????" << endl;
					cout << "\t\t" << ++arr[index];

					cout << endl << endl;

					cout << "\n\n\t\t\t\t\t?????????? ?????" << endl;
					cout << "\t\t" << arr[index];

					cout << endl << endl;

					cout << "\t\t\t";

					cputs ("????????? ???????????\n", resColor);

					cout << "\n\n\t\t\t\t\t???????????? ????????" << endl;
					cout << "\t\t" << arr[index]++;

					cout << endl << endl;

					cout << "\n\n\t\t\t\t\t?????????? ?????" << endl;
					cout << "\t\t" << arr[index];

					cout << endl << endl;

					getKey();

					break;

					// 2. ?????????? ?????????? ? ???????????
				case '2':
					cout << "\n\n\t\t\t\t\t\t?????????? ?????????? ? ???????????\n\n" << endl;

					cout << "\t???????? ?????: ";
					cin >> a;

					index = a - 1;

					cout << "\n\n\t\t\t\t\t????? " << a << endl << endl;

					cout << "\t\t\t";

					cputs("????????? ??????????\n", resColor);

					cout << "\n\n\t\t\t\t\t???????????? ????????" << endl;
					cout << "\t\t" << --arr[index];

					cout << endl << endl;

					cout << "\n\n\t\t\t\t\t?????????? ?????" << endl;
					cout << "\t\t" << arr[index];

					cout << endl << endl;

					cout << "\n\t\t\t";

					cputs("????????? ???????????\n", resColor);

					cout << "\n\n\t\t\t\t\t???????????? ????????" << endl;
					cout << "\t\t" << arr[index]--;

					cout << endl << endl;

					cout << "\n\n\t\t\t\t\t?????????? ?????" << endl;
					cout << "\t\t" << arr[index];

					cout << endl << endl;

					getKey();

					break;

					// 3. ????? ??????? ???????? ? ??????????? ???????
				case '3':

					cout << "\n\n\t\t\t\t\t\t????? ??????? ???????? ? ??????????? ???????\n\n" << endl;

					// ?????? ???????????? ????????
					indexMin = arr.MinimumV();

					cl = getColor();

					cout << "\t\t\t";

					setColor(resColor);

					cout << "??????? ? ??????????? ??????? - Conoid[ " << indexMin << " ]" << endl << endl;

					setColor(cl);

					cout << "\t\t" << arr[indexMin];

					cout << "\n\n\n";

					getKey();

					break;

				case '4':

					cout << "\n\n\t\t\t\t\t\t????? ??????? ???????? ? ??????????? ????????\n\n" << endl;

					// ?????? ???????????? ????????
					indexMax = arr.MaximumS();

					cout << "\t\t\t";

					cl = getColor();

					setColor(resColor);

					cout << "??????? ? ???????????? ???????? - Conoid[ " << indexMax << " ]\n\n";

					setColor(cl);

					cout << "\t\t" << arr[indexMax];

					cout << "\n\n\n";

					getKey();

					break;

				default:
					break;
				}
				break;
			}

			if (n == 27)
			{
				return;
			}
		}
	}
}

#pragma endregion

#pragma endregion

#pragma region ??????? 2 

/*
*
* ?????? 2. ? ??? ?? ?????????? ??????????, ? ?????????????? ?????? Matrix ?? ??????????,
* ?????????????? ? ???????? ??????, ?????? ??????. ???????????? ???????, ? ??????? ?? ??????
* ??????????? ?????? ?????? Matrix.
* ?	????????? ?????? ?????? Matrix?? 5 ????? ? 8 ???????? ?????????? ???????
* ?	??????? ????? ????????? ? ??? ????????, ??????? ?? ???????? ????????????? ?????????
* ?	??????? ?????????? ????????, ?????????? ???? ?? ???? ??????? ???????
*
*/

#pragma region ?????? ??????? 2

// ??????????? ??????? ?????????? ??????? (???? int)
void fillMatrix(Matrix& mtx)
{
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		for (size_t k = 0; k < mtx.cols(); k++)
		{
			mtx(i, k) = getRand(-2, +10);
		}
	}
}

// ????? ????????? ???????, ? ??????? ??? ????????????? ?????????
int sumElem(Matrix& mtx)
{
	// ????? ????????? 
	int sum = 0;

	// ????? ???????
	int sumTmp = 0;
	for (int i = 0; i < mtx.cols(); i++)
	{
		for (int k = 0; k < mtx.rows(); k++)
		{
			// ???? ????? ???????? ?????????????
			if (mtx(k, i) >= 0)
			{
				sumTmp += mtx(k, i);
			} 
			else
			{
				sumTmp = 0;
				break;
			}
		}

		sum += sumTmp;

		sumTmp = 0;
	}

	return sum;
}

// ????? ?????????? ????? ?????????? ??????? ?? ????????? 0
int countRowsNull(Matrix& mtx)
{
	// ?????????? ????? ? ??????? ?????? ??????? ?? ????????? 0
	int count = 0;

	for (size_t i = 0; i < mtx.rows(); i++)
	{
		for (size_t k = 0; k < mtx.cols(); k++)
		{
			if (mtx(i, k) == 0)
			{
				count++;

				break;
			}
		}
	}

	return count;
}

#pragma endregion

#pragma region ??????? 2 (????)

void App::task2() 
{

#pragma region ????? ???????
	setColor(mainColor);

	cls();

	setColor(headerColor);

	cout << "\n\n\t\t\t\t??????? 2\n\n";

	cout << "\t\t?????? 2. ? ??? ?? ?????????? ??????????, ? ?????????????? ??????\n"
		<< "\t\tMatrix ?? ??????????, ?????????????? ? ???????? ??????, ?????? ??????.\n"
		<< "\t\t???????????? ???????, ? ??????? ?? ?????? ??????????? ?????? ?????? Matrix.\n\n"
		<< "\t\t?	????????? ?????? ?????? Matrix?? 5 ????? ? 8 ???????? ?????????? ???????\n\n"
		<< "\t\t?	??????? ????? ????????? ? ??? ????????, ??????? ?? ???????? ????????????? ?????????\n\n"
		<< "\t\t?	??????? ?????????? ????????, ?????????? ???? ?? ???? ??????? ???????\n\n";

	setColor(headerColor);

	getKey();

	cls();

#pragma endregion

	// ???????
	Matrix* P_mtx = new Matrix();

	// ?????? ?? ???????
	Matrix& mtx = *P_mtx;

	fillMatrix(mtx);

	// ????? ???????
	cout << "\t\t\t\t\t\t\t???????\n\n" << endl;

	for (size_t i = 0; i < mtx.rows(); i++)
	{
		cout << "\t\t+";
		for (size_t i = 0; i < mtx.cols(); i++)
		{
			cout << "?????????+";
		}

		cout << "\n\t\t";

		for (size_t k = 0; k < mtx.cols(); k++)
		{
			cout << "| " << setw(8) << mtx(i, k);

			// ???? ??? ????????? ??????? ?? ????? ???????? ?????
			if (k == mtx.cols() - 1)
			{
				cout << "|" << endl;
			}


		}
	}

	cout << "\t\t+";
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		cout << "?????????+";
	}

	cout << "\n\n\n\n\t\t????? ????????? ? ??? ????????, ??????? ?? ???????? ????????????? ?????????: " << sumElem(mtx) << endl;
	cout << "\n\t\t?????????? ????????, ?????????? ???? ?? ???? ??????? ???????: " << countRowsNull(mtx) << "\n\n";

	getKey();

	return;
}

#pragma endregion

#pragma endregion
