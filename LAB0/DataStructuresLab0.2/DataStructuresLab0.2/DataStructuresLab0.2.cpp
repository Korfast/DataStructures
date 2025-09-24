#include <iostream>

using namespace std;

void insertionSort(int array[], int arrayLength)
{
	for (int i = 1; i < arrayLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && array[j] > array[j + 1])
		{
			swap(array[j], array[j + 1]);
			j--;
		}
	}
}

/*
int main()
{
    setlocale(LC_ALL, "");
    int array[10];
    for (int i = 0; i < 10; i++) 
    {
        wcout << L"Введите целочисленный элемент массива № " << i << " : ";
        cin >> array[i];
    }

    wcout << L"Ваш массив: \n";

    for (int i = 0; i < 10; i++) 
    {
        cout << array[i] << " ";
    }

	insertionSort(array, 10);

    wcout << L"\nотсортированный массив: \n";

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
*/

/*
int main()
{
    setlocale(LC_ALL, "");

    double array[12];
    double searchingValue;
    int greaterElements = 0;

    for (int i = 0; i < 12; i++)
    {
        wcout << L"Введите элемент массива № " << i << " : ";
        cin >> array[i];
    }

    wcout << L"Ваш массив: \n";

    for (int i = 0; i < 12; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\nsearchingValue: ";
    cin >> searchingValue;

    for (int i = 0; i < 12; i++)
    {
        if (array[i] >= searchingValue)
        {
            greaterElements++;
        }
    }
 
    wcout << L"Количество чисел больше или равных " << searchingValue << " : " << greaterElements;

    
    return 0;
}
*/

int main()
{
    setlocale(LC_ALL, "");

    char array[8];
    string smallAlphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 8; i++)
    {
        wcout << L"Введите элемент массива № " << i << " : ";
        cin >> array[i];
    }

    wcout << L"Ваш массив: \n";

    for (int i = 0; i < 8; i++)
    {
        cout << array[i] << " ";
    }

    wcout << L"\nТолько маленькие буквы: \n";

   for (int i = 0; i < 8; i++)
    {
       if (smallAlphabet.find(array[i]) != string::npos)
       {
           cout << array[i] << " ";
       }
    }

    return 0;
}