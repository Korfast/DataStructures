#include <iostream>
using namespace std;

double GetPower(double base, int exponent) 
{
    double result = 1;
   
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    if (exponent < 0)
    {
        for (int i = 0; i > exponent; i--)
        {
            result *= base;
        }
        result = 1 / result;
    }
    return result;
}

void DemoGetPower(double base, int exponent)
{
    double result = GetPower(base, exponent);
    cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

void RoundToTens(int& value)
{
    if (value % 10 < 5)
    {
        value = value / 10 * 10;
    }
    else
    {
        value = (value / 10 + 1) * 10;
    }
}

/*
int main()
{
    setlocale(LC_ALL, "");

    cout << "Вывод с помощью функции GetPower" << endl;
    cout << "2.0 ^ 5 = " << GetPower(2.0, 5) << endl;
    cout << "3.0 ^ 4 = " << GetPower(3.0, 4) << endl;
    cout << "-2.0 ^ 5 = " << GetPower(-2.0, 5) << endl;
    cout << "3.0 ^ 0 = " << GetPower(3.0, 0) << endl;
    cout << "2.5 ^ -5 = " << GetPower(2.5, -5) << endl;
    cout << endl;

    cout << "Вывод с помощью функции DemoGetPower" << endl;
    DemoGetPower(2.0, 5);
    DemoGetPower(3.0, 4);
    DemoGetPower(-2.0, 5);
    DemoGetPower(3.0, 0);
    DemoGetPower(2.5, -5);
}
*/

int main()
{
    setlocale(LC_ALL, "");

    cout << "Введите целое число которое будем округлять: ";
    int a;
    cin >> a;
    cout << a << " округленно до ";
    RoundToTens(a);
    cout << a << endl;
}