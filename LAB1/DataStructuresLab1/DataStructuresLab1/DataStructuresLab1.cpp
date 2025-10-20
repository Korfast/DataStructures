#include <iostream>
#include "DynamicArray.h"

using namespace std;

void PrintMenu() {
    cout << "\nМеню:\n";
    cout << "1. Создать новый массив\n";
    cout << "2. Добавить элемент в конец\n";
    cout << "3. Добавить элемент в начало\n";
    cout << "4. Вставить после элемента\n";
    cout << "5. Удалить по индексу\n";
    cout << "6. Удалить по значению\n";
    cout << "7. Вставить по индексу\n";
    cout << "8. Отсортировать массив\n";
    cout << "9. Линейный поиск\n";
    cout << "10. Бинарный поиск\n";
    cout << "11. Вывод массива\n";
    cout << "0. Выйти\n";
}

// Вспомогательная функция для безопасного чтения числа
bool SafeInputInt(int& var) {
    cin >> var;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    DynamicArray dynamicArray;
    bool initialized = false;
    int choice, value, index, sortVariant;

    do {
        PrintMenu();
        cout << "Выберите пункт: ";
        if (!SafeInputInt(choice)) {
            cout << "Некорректный ввод. Попробуйте еще раз.\n";
            continue;
        }

        switch (choice) {
        case 1:
            dynamicArray.~DynamicArray();
            dynamicArray = DynamicArray(); // создаем заново
            initialized = true;
            std::cout << "Массив создан.\n";
            break;
        case 2:
            if (!initialized) {
                cout << "Массив не инициализирован. Сначала создайте массив.\n";
                break;
            }
            cout << "Введите значение: ";
            if (!SafeInputInt(value)) {
                cout << "Некорректный ввод значения.\n";
                break;
            }
            dynamicArray.AddToEnd(value);
            break;
        case 3:
            if (!initialized) {
                cout << "Массив не инициализирован. Сначала создайте массив.\n";
                break;
            }
            cout << "Введите значение: ";
            if (!SafeInputInt(value)) {
                cout << "Некорректный ввод значения.\n";
                break;
            }
            dynamicArray.AddToStart(value);
            break;
        case 4:
            if (!initialized) {
                cout << "Массив не инициализирован. Сначала создайте массив.\n";
                break;
            }
            cout << "Введите индекс после которого вставить: ";
            if (!SafeInputInt(index)) {
                cout << "Некорректный ввод индекса.\n";
                break;
            }
            cout << "Введите значение: ";
            if (!SafeInputInt(value)) {
                cout << "Некорректный ввод значения.\n";
                break;
            }
            dynamicArray.InsertAfter(index, value);
            break;
        case 5:
            if (!initialized) {
                cout << "Массив не инициализирован.\n";
                break;
            }
            cout << "Введите индекс для удаления: ";
            if (!SafeInputInt(index)) {
                cout << "Некорректный ввод индекса.\n";
                break;
            }
            dynamicArray.RemoveByIndex(index);
            break;
        case 6:
            if (!initialized) {
                cout << "Массив не инициализирован.\n";
                break;
            }
            cout << "Введите значение для удаления: ";
            if (!SafeInputInt(value)) {
                cout << "Некорректный ввод значения.\n";
                break;
            }
            dynamicArray.RemoveByValue(value);
            break;
        case 7:
            if (!initialized) {
                cout << "Массив не инициализирован.\n";
                break;
            }
            cout << "Введите индекс для вставки: ";
            if (!SafeInputInt(index)) {
                cout << "Некорректный ввод индекса.\n";
                break;
            }
            cout << "Введите значение: ";
            if (!SafeInputInt(value)) {
                cout << "Некорректный ввод значения.\n";
                break;
            }
            dynamicArray.InsertAt(index, value);
            break;
        case 8:
            if (!initialized) {
                cout << "Массив не инициализирован.\n";
                break;
            }
            cout << "Выберите сортировку:\n1. Пузырьковая\n2. Выбором\n3. Вставками\n";
            if (!SafeInputInt(sortVariant)) {
                cout << "Некорректный ввод варианта сортировки.\n";
                break;
            }
            dynamicArray.Sort(sortVariant);
            break;
        case 9:
            if (!initialized) {
                cout << "Массив не инициализирован.\n";
                break;
            }
            cout << "Введите значение для линейного поиска: ";
            if (!SafeInputInt(value)) {
                cout << "Некорректный ввод значения.\n";
                break;
            }
            index = dynamicArray.LinearSearch(value);
            if (index != -1)
                cout << "Элемент найден на позиции: " << index << "\n";
            else
                cout << "Элемент не найден.\n";
            break;
        case 10:
            if (!initialized) {
                cout << "Массив не инициализирован.\n";
                break;
            }
            cout << "Введите значение для бинарного поиска: ";
            if (!SafeInputInt(value)) {
                cout << "Некорректный ввод значения.\n";
                break;
            }
            index = dynamicArray.BinarySearch(value);
            if (index != -1)
                cout << "Элемент найден на позиции: " << index << "\n";
            else
                cout << "Элемент не найден.\n";
            break;
        case 11:
            if (initialized) {
                std::cout << "Массив: ";
                for (int i = 0; i < dynamicArray.GetSize(); ++i)
                    std::cout << dynamicArray.GetArray()[i] << " ";
                std::cout << "\n";
            }
            else {
                std::cout << "Массив не инициализирован.\n";
            }
            break;
        case 0:
            cout << "Выход.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}