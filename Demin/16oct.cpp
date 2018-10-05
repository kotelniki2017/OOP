/home/maks/OOP/Demin/hello.cpp#include <cmath>
//#include "pch.h"
#include <iostream>
using namespace std;
double dist(double v, double a, double g, double PI)
{
return v * v * sin(2 * a * PI / 180) / g;
}

int main()
{
	double l = 0, v, a, g = 9.807, max_a, max_l = 0;/home/maks/OOP/Demin/hello.cpp
	const double PI = 3.14159265358979323846;
	cout << "Speed, m/s: ";
	cin >> v;
	cout << "Angle: ";
	cin >> a;
	if (a == '-')
	{
		for (double a = 0; a < 90; a++)
		{
			l = dist(v, a, g, PI);
			if (max_l < l)
			{
				max_l = l;
				max_a = a;
			}
		}
		cout << "Max distance, m: " << max_l << endl;
		cout << "Max angle: " << max_a << endl;
	}
	else
	{
		l = dist(v, a, g, PI);
		cout << "Distance, m: " << l << endl;
	}
}