#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция сортировки вставками вещественного массива
void insertionSort(double array[], int arrayLength)
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

// Функция поиска индекса элемента в массиве
// Возвращает индекс первого найденного элемента, либо -1 если не найден
int findIndex(int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value)
        {
            return i;
        }
            
    }
    return -1;
}

// Функция выводящая все маленькие буквы из массива 
// Возвращает их количество
int countLetters(char* array, int arraySize)
{
    cout << endl << "Маленькие буквы из массива:\n";
    int numberLettersInArray = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] >= 'a' && array[i] <= 'z')
        {
            cout << array[i] << " ";
            numberLettersInArray++;
        }
    }
    return numberLettersInArray;
}

int* MakeRandomArray(int arraySize)
{
    int* array = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % 101;
    }

    return array;
}

void PrintArray(const int* array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}
/*
int main()
{
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите число элементов в вещественном массиве для выделения памяти:";
    cin >> n;
    // Выделяем память под массив
    double* array = new double[n];

    // Инициализируем массив значениями
    for (int i = 0; i < n; ++i) {
        array[i] = i * 2 ; 
    }

    // Выводим значения массива
    std::cout << "Массив: ";
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] array;

    return 0;
}
*/
/*
int main()
{
    setlocale(LC_ALL, "");
    int n = 6;
    
    // Выделяем память под массив
    bool* array = new bool[n];

    array[0] = true;
    array[1] = false;
    array[2] = true;
    array[3] = true;
    array[4] = false;
    array[5] = false;

    cout << "Массив bool: ";
    for (int i = 0; i < n; ++i) 
    {
        if (array[i] == 0)
        {
            cout << "false" << " ";
        }
        else
        {
            cout << "true" << " ";
        }
            
    }
    cout << endl;

    // Освобождаем память
    delete[] array;

    return 0;
}
*/
/*
int main()
{
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите целое положительное число n: ";
    cin >> n;

    // Выделяем память под массив символов
    char* array = new char[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Элемент символьного массива № " << i << ":";
        cin >> array[i];
        cout << endl;
    }

    cout << "Ваш массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    delete[] array;
    return 0;
}
*/
/*
int main()
{
    setlocale(LC_ALL, "");

    double* array = new double[10];
    array[0] = 1;
    array[1] = 15;
    array[2] = -8.2;
    array[3] = -3.5;
    array[4] = 12.6;
    array[5] = 38.4;
    array[6] = -0.5;
    array[7] = 4.5;
    array[8] = 16.7;
    array[9] = 4.5;

    cout << "Ваш вещественный массив:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }

    insertionSort(array, 10);

    cout << "\nОтсортерованный массив:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }

    delete[] array;
    return 0;
}
*/                                                   
/*
int main()
{
    setlocale(LC_ALL, "");

    int* array = new int[10];
    array[0] = 1;
    array[1] = 15;
    array[2] = -8;
    array[3] = -3;
    array[4] = 12;
    array[5] = 38;
    array[6] = 0;
    array[7] = 4;
    array[8] = 16;
    array[9] = 4;

    cout << "Ваш массив:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }

    int valueFromArray;
    cout << "\nЭлемент массива индекс которого хотите найти: ";
    cin >> valueFromArray;
    cout << "Индекс вашего элемента: ";
    cout << findIndex(array, 10, valueFromArray);

    delete[] array;
    return 0;
}
*/
/*
int main()
{
    setlocale(LC_ALL, "");

    char* array = new char[15];
    array[0] = 'a';
    array[1] = '5';
    array[2] = 'm';
    array[3] = 'i';
    array[4] = '%';
    array[5] = '!';
    array[6] = 's';
    array[7] = 'p';
    array[8] = '*';
    array[9] = '9';
    array[10] = 'f';
    array[11] = '^';
    array[12] = ';';
    array[13] = 'q';
    array[14] = 'k';

    cout << "Ваш массив:\n";
    for (int i = 0; i < 15; i++)
    {
        cout << array[i] << " ";
    }

    int numberLettersInArray = countLetters(array, 15);
    cout << "\nКоличество маленьких букв в массиве: " << numberLettersInArray;

    delete[] array;
    return 0;
}
*/
/*
int main()
{
    setlocale(LC_ALL, "");

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    int array1Size = 5;
    int array2Size = 8;
    int array3Size = 13;

    int* array1 = MakeRandomArray(array1Size);
    int* array2 = MakeRandomArray(array2Size);
    int* array3 = MakeRandomArray(array3Size);

    cout << "Массив размером " << array1Size << ": ";
    PrintArray(array1, array1Size);

    cout << "Массив размером " << array2Size << ": ";
    PrintArray(array2, array2Size);

    cout << "Массив размером " << array3Size << ": ";
    PrintArray(array3, array3Size);

    delete[] array1;
    delete[] array2;
    delete[] array3;

    return 0;
}
*/

int* ReadArray(int count)
{
    int* values = new int[count];
    for (int i = 0; i < count; i++)
    {
        cin >> values[i];
    }
    return values;
}

int CountPositiveValues(int* values, int count)
{
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        if (values[i] > 0)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    int count = 15;
    int* values = ReadArray(count);
    cout << "Count is: " << CountPositiveValues(values, count) << endl;
    // Исправление здесь:
    delete[] values;

    count = 20;
    values = ReadArray(count);
    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    delete[] values;
}