#include <iostream>

using namespace std;

/*
void Breakpoints()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		// Переменная sum принимает следующие значения:
		// (0) 0 1.21 3.52 7.513 13.3694 21.42195 32.051316 45.6923357 62.84104618 84.062575399
		sum += add * i;
		add *= 1.1;
	}
	cout << "Total sum is " << sum << endl;
}

int main()
{
	Breakpoints();
}
*/

void Breakpoints()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		// Поставьте условную точку останова здесь
		// Переменная sum = 3.2624579394327844 при i = 777
		sum += add * i;
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}
	cout << "Total sum is " << sum << endl;
}

int main()
{
	Breakpoints();
}
