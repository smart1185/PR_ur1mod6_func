#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>

using namespace std;

void fillArr(int *mas, int length);
void printArr(int * arr, int countEl);
int f(int h, int m, int s);
int happyHelp(int n);
void happy(int n);
void Pal(int *a);
int max(int *m1, int *m2);
int Max(int *a, int *b, int *c, int *d, int *e, int *f);
int IsLeapYear(int year);
int F(int *M, int *Y);
void PrevDate(int *D, int *M, int *Y);
void NextDate(int *D, int *M, int *Y);
int Nod(int *a, int *b);


void main()
{
	setlocale(LC_ALL, "Rus");

	int n = 0;
	cout << "Choose number of the task " << endl;
	cin >> n;

	do
	{
		if (n == 1)
		{
			int h = 0, m = 0, s = 0;
			cout << "Point the current time " << endl;
			cin >> h >> m >> s;

			cout << "It had been taken: " << f(h, m, s) << " seconds" << endl;
		}

		else if (n == 2)
		{
			happy(n);

		}

		else if (n == 3)
		{
			int y = 0, x = 0;
			cout << "Print the number " << endl;
			cin >> y;

			Pal(&y);

			cout << "Print the number " << endl;
			cin >> x;
			Pal(&x);
		}

		else if (n == 4)
		{
			int a, b, c, d, e, f;
			cout << "Print the number " << endl;
			cin >> a >> b >> c >> d >> e >> f;


			cout << "MAX=" << Max(&a, &b, &c, &d, &e, &f) << endl;
		}

		else if (n == 5)
		{
			int d = 0, m = 0, g = 0;

			cout << "Print the date " << endl;
			cin >> d >> m >> g;

			cout << "In month " << m << " - " << F(&m, &g) << " days" << endl;

			PrevDate(&d, &m, &g);
			NextDate(&d, &m, &g);
		}

		else if (n == 7)
		{
			int h;
			int v;
			int NOK;
			int x, y;


			cout << "Print the number " << endl;
			cin >> h;

			cout << "Print the number " << endl;
			cin >> v;

			NOK = Nod(&h, &v);

			cout << "NOK = " << NOK << endl;
		}


	} while (n == 0);
}

void fillArr(int *mas, int length)
{

	for (int i = 0; i < length; i++)
		mas[i] = 1 + rand() % 100;

}

void printArr(int * arr, int countEl)
{
	for (int i = 0; i < countEl; i++)
		cout << "arr[" << i << "]=" << arr[i] << endl;
}

int f(int h, int m, int s)
{

	return ((h >= 12 ? h - 12 : h) * 3600 + m * 60 + s);
}

int happyHelp(int n)
{
	int sum;
	sum = (n / 100 + n / 10 + n % 10);
	return sum;
}

void happy(int n)
{
	int count = 0;

	for (int i = 100000; i <= 999999; i++)
	{
		int n = i;
		int left = happyHelp(n / 1000);
		int right = happyHelp(n % 1000);

		if (left == right)
		{
			++count;
		}
	}

	cout << count << " - êîëè÷åñòâî ñ÷àñòëèâûõ øåñòèçíà÷íûõ ÷èñåë " << endl;
}

void Pal(int *a)
{
	if (*a > 99 && *a < 1000)
	{
		if (*a / 100 == *a % 10)
		{
			cout << *a << " ÿâëÿåòñÿ ÷èñëîì - ïàëèíäðîìîì" << endl;
		}
		else
		{
			cout << *a << " íå ÿâëÿåòñÿ ÷èñëîì - ïàëèíäðîìîì" << endl;
		}
	}
	else
	{
		cout << " Íåïðàâèëüíàÿ ðàçðÿäíîñòü ÷èñëà" << endl;
	}

}

int max(int *m1, int *m2)
{
	if (*m1 > *m2)
	{
		return *m1;
	}

	return *m2;
}

int Max(int *a, int *b, int *c, int *d, int *e, int *f)
{
	int m1 = max(a, b);
	int m2 = max(c, d);
	int m3 = max(e, f);
	int m4 = max(&m1, &m2);

	return max(&m3, &m4);
}


int IsLeapYear(int year)
{
	if ((year % 100 == 0 && year % 400 != 0) || year % 4 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int F(int *M, int *Y)
{
	switch (*M)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (IsLeapYear == 0)
		{
			return 28;
		}
		else
		{
			return 29;
		}
		break;
	}
}

void PrevDate(int *D, int *M, int *Y)
{
	if (*D == 1)
	{
		if (*M == 1)
		{
			*Y = *Y - 1;
			*M = *M - 1;
			*D == F(M, Y);
		}
		else
		{
			*M = *M - 1;
			*D == F(M, Y);
		}

	}
	else
	{
		*D = *D - 1;
	}

	cout << "Ïðåäûäóùèé äåíü = " << *D << "." << *M << "." << *Y << endl;
}

void NextDate(int *D, int *M, int *Y)
{
	if (*D == 31)
	{
		if (*M == 12)
		{
			*Y = *Y + 1;
			*M = 1;
			*D = 1;
		}
		else
		{
			*M = *M + 1;
			*D = 1;
		}

	}
	else
	{
		*D = *D + 1;
	}

	if (*D == 30)
	{
		*M = *M + 1;
		*D = 1;
	}

	else
	{
		*D = *D + 1;
	}

	cout << "Ñëåäóþùèé äåíü = " << *D << "." << *M << "." << *Y << endl;
}

int Nod(int *a, int *b)
{
	int m = (*a) * (*b);
	while (*a != 0 && *b != 0)
	{
		if (*a > *b)
		{
			*a %= *b;
		}
		else
		{
			*b %= *a;
		}
	}

	return m / (*a + *b);
}

