#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
// Все что нужно для метода Amn
void swap1(int *a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool NextSet1(int *a, int n, int m)
{
	int j;
	do  // повторяем пока не будет найдено следующее размещение
	{
		j = n - 1;
		while (j != -1 && a[j] >= a[j + 1]) j--;
		if (j == -1)
			return false; // больше размещений нет
		int k = n - 1;
		while (a[j] >= a[k]) k--;
		swap1(a, j, k);
		int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
		while (l < r)
			swap1(a, l++, r--);
	} while (j > m - 1);
	return true;
}
void Print1(int *a, int n)  // вывод размещения
{
	static int num = 0; // номер размещения
	if (num % 4 == 0)
	{
		cout << endl;
	}
	cout << ++num << "-";
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << "  ";
}
// Все что нужно для метода Amn

// Все что нужно для метода Cmn
bool NextSet2(int *a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}
void Print2(int *a, int n)
{
	static int num = 0;
	if (num % 4 == 0)
	{
		cout << endl;
	}
	cout << ++num << "-";
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << "  ";

}
// Все что нужно для метода Cmn

// Все что нужно для главной функции
using namespace std;
int main()
{
	string s;
	int i, n, n1, m, *a, methot;
	cout << "Chose method 1-n! 2-Amn 3-Cmn: ";
	cin >> methot;
	switch (methot)
	{
	case 1:
	{
		cout << "N= ";
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			s += std::to_string(i);
		}
		n1 = n;
		for (i = 1; i < n1; i++)
		{
			n *= i;
		}
		cout << n << endl;
		i = 1;
		do
		{
			std::cout << i << "-" << s << "  ";
			if (i % 4 == 0)
			{
				cout << '\n';
			}
			i++;
		} while (std::next_permutation(s.begin(), s.end()));// Генерация перестановок элементов
		cout << '\n';
		cout << "n! = " << n;
		i = 0;
		break;
	}
	case 2:
	{
		cout << "N = ";
		cin >> n;
		cout << "M = ";
		cin >> m;
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = i + 1;
		Print1(a, m);
		while (NextSet1(a, n, m))
			Print1(a, m);
		break;
	}
	case 3:
	{
		cout << "N = ";
		cin >> n;
		cout << "M = ";
		cin >> m;
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = i + 1;
		Print2(a, m);
		if (n >= m)
		{
			while (NextSet2(a, n, m))
				Print2(a, m);
		}
	}
	default:
		return 0;
	}
}
// Все что нужно для главной функции
