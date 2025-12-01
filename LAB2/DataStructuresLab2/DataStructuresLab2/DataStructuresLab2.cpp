#include <iostream>
// Для замеров времени
#include <chrono> 
// Для удобства хранения результатов тестов
#include <vector> 
// Для красивого вывода таблицы
#include <iomanip> 

#include "Header Files/List.h"
#include "Header Files/Node.h"
#include "../../../LAB1/DataStructuresLab1/DataStructuresLab1/Header Files/DynamicArray.h"

using namespace std;
using namespace std::chrono;

//! \brief Функция для безопасного ввода целого числа.
//! \param message Сообщение, которое выводится пользователю перед вводом.
//! \return Введенное целое число.
int GetIntInput(const char* message)
{
    int value;
    while (true)
    {
        cout << message;
        if (cin >> value)
        {
            return value;
        }
        else
        {
            cout << "Некорректный ввод. Пожалуйста, введите число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

//! \brief Функция для заполнения списка N элементами.
//! \param list Ссылка на список.
//! \param count Количество элементов для вставки.
void FillList(List& list, int count) 
{
    list.Clean();
    for (int i = 0; i < count; i++) 
    {
        Node* node = new Node();
        node->SetData(i);
        // Вставка в конец
        list.AddNode(node, i); 
    }
}

//! \brief Функция для заполнения массива N элементами.
//! \param arr Ссылка на динамический массив.
//! \param count Количество элементов для вставки.
void FillArray(DynamicArray& arr, int count) 
{
    // Очистка. Удаляет "мусор" от предыдущих тестов
    arr.Init(); 
    // Наполнение. Добавляет ровно count элементов(0, 1, 2...)
    for (int i = 0; i < count; i++) 
    {
        arr.AddToEnd(i);
    }
}

//! \brief Шаблон функции для замера среднего времени выполнения операции.
//! \tparam Func Тип передаваемого действия (обычно лямбда-выражение или функтор).
//! \param action Сама функция или лямбда, которую нужно протестировать.
//! \param iterations Количество повторений для усреднения результата 
//! (чтобы исключить случайные выбросы).
//! \return Среднее время выполнения одной операции в микросекундах.
template <typename Func>
double MeasureTime(Func action, int iterations) 
{
    // Фиксируем текущее время перед началом теста 
    auto start = high_resolution_clock::now();
    // Выполняем тестируемую операцию заданное количество раз
    for (int i = 0; i < iterations; i++) 
    {
        action();
    }
    // Фиксируем время после окончания всех итераций
    auto end = high_resolution_clock::now();
    // Вычисляем разницу между концом и началом в микросекундах
    auto duration = duration_cast<microseconds>(end - start);
    // Делим общее время на количество итераций, 
    // чтобы получить среднее время одной операции
    return (double)duration.count() / iterations;
}

//! \brief Функция запуска исследования производительности.
void RunPerformanceTest() {
    // Размеры данных для теста 
    vector<int> sizes = { 100, 500, 1000, 5000, 10000, 20000, 50000 };
    // Количество прогонов для усреднения
    int iterations = 100; // Количество прогонов для усреднения

    cout << "\n--- ЗАПУСК ИССЛЕДОВАНИЯ ПРОИЗВОДИТЕЛЬНОСТИ ---\n";
    cout << "Размеры: 100, 500, 1000, 5000, 10000, 20000, 50000\n";
    cout << "Итераций усреднения: " << iterations << "\n\n";

    // Заголовки таблицы
    cout << left << setw(10) << "Size"
        << setw(15) << "Op"
        << setw(15) << "List(mks)"
        << setw(15) << "Array(mks)" << endl;
    cout << string(55, '-') << endl;

    for (int n : sizes) {
        // Подготовка структур (создаем полные копии перед тестами)
        // Чтобы замеры были честными, мы будем создавать структуру заново или 
        // компенсировать время, но для простоты вставим 1 элемент в структуру размера N.

        // 1. ВСТАВКА В НАЧАЛО
        {
            // Подготовка списка размера N
            List testList;
            FillList(testList, n);

            // Замер списка
            double tList = MeasureTime([&]() {
                Node* node = new Node();
                node->SetData(999);
                testList.AddNode(node, 0);
                // Сразу удаляем, чтобы размер оставался N 
                // для следующей итерации? 
                testList.RemoveNodeByIndex(0); 
                }, iterations);

            // Подготовка массива размера N
            DynamicArray testArray(8); 
            for (int k = 0; k < n; k++) testArray.AddToEnd(k);

            // Замер массива
            double tArr = MeasureTime([&]()
            {
                testArray.AddToStart(999);
                // Возвращаем состояние
                testArray.RemoveByIndex(0); 
            }, iterations);

            cout << left << setw(10) << n << setw(15) << "Add Start"
                << setw(15) << tList << setw(15) << tArr << endl;
        }

        // 2. ВСТАВКА В СЕРЕДИНУ
        {
            List testList; FillList(testList, n);
            // DynamicArray пересоздаем, т.к. очистка может быть не реализована полностью
            DynamicArray testArr(8); for (int k = 0; k < n; k++) testArr.AddToEnd(k);

            double tList = MeasureTime([&]() {
                Node* node = new Node();
                node->SetData(999);
                testList.AddNode(node, n / 2);
                testList.RemoveNodeByIndex(n / 2);
                }, iterations);

            double tArr = MeasureTime([&]() {
                testArr.InsertAt(n / 2, 999);
                testArr.RemoveByIndex(n / 2);
                }, iterations);

            cout << left << setw(10) << n << setw(15) << "Add Mid"
                << setw(15) << tList << setw(15) << tArr << endl;
        }

        // 3. ВСТАВКА В КОНЕЦ
        {
            List testList; FillList(testList, n);
            DynamicArray testArr(8); for (int k = 0; k < n; k++) testArr.AddToEnd(k);

            double tList = MeasureTime([&]() {
                Node* node = new Node();
                node->SetData(999);
                testList.AddNode(node, testList.GetSize());
                testList.RemoveNodeByIndex(testList.GetSize() - 1);
                }, iterations);

            double tArr = MeasureTime([&]() {
                testArr.AddToEnd(999);
                // Удаляем, чтобы не вызвать реаллокацию памяти раньше времени
                testArr.RemoveByIndex(testArr.GetSize() - 1);
                }, iterations);

            cout << left << setw(10) << n << setw(15) << "Add End"
                << setw(15) << tList << setw(15) << tArr << endl;
        }

        // 4. УДАЛЕНИЕ ИЗ НАЧАЛА
        {
            List testList; FillList(testList, n);
            DynamicArray testArr(8); for (int k = 0; k < n; k++) testArr.AddToEnd(k);

            // Тут сложнее: если мы удалим 100 раз, массив уменьшится.
            // Мы будем удалять и сразу добавлять обратно, чтобы измерить именно операцию удаления
            // (хотя добавление внесет погрешность, но она одинакова для обоих, либо можно пренебречь уменьшением на 100 эл при N=50000)

            double tList = MeasureTime([&]() {
                testList.RemoveNodeByIndex(0);
                // Восстанавливаем для следующего прогона, чтобы размер был примерно N
                Node* node = new Node(); node->SetData(0); testList.AddNode(node, 0);
                }, iterations);

            double tArr = MeasureTime([&]() {
                testArr.RemoveByIndex(0);
                testArr.AddToStart(0); // Компенсация
                }, iterations);

            cout << left << setw(10) << n << setw(15) << "Del Start"
                << setw(15) << tList << setw(15) << tArr << endl;
        }

        // 5. УДАЛЕНИЕ ИЗ СЕРЕДИНЫ
        {
            List testList; FillList(testList, n);
            DynamicArray testArr(8); for (int k = 0; k < n; k++) testArr.AddToEnd(k);

            double tList = MeasureTime([&]() {
                testList.RemoveNodeByIndex(n / 2);
                // Восстанавливаем
                Node* node = new Node(); node->SetData(0); testList.AddNode(node, n / 2);
                }, iterations);

            double tArr = MeasureTime([&]() {
                testArr.RemoveByIndex(n / 2);
                testArr.InsertAt(n / 2, 0);
                }, iterations);

            cout << left << setw(10) << n << setw(15) << "Del Mid"
                << setw(15) << tList << setw(15) << tArr << endl;
        }

        // 6. УДАЛЕНИЕ ИЗ КОНЦА 
        {
            List testList; FillList(testList, n);
            DynamicArray testArr(8); for (int k = 0; k < n; k++) testArr.AddToEnd(k);

            double tList = MeasureTime([&]() {
                testList.RemoveNodeByIndex(testList.GetSize() - 1);
                // Восстанавливаем
                Node* node = new Node(); node->SetData(0); testList.AddNode(node, testList.GetSize());
                }, iterations);

            double tArr = MeasureTime([&]() {
                testArr.RemoveByIndex(testArr.GetSize() - 1);
                testArr.AddToEnd(0);
                }, iterations);

            cout << left << setw(10) << n << setw(15) << "Del End"
                << setw(15) << tList << setw(15) << tArr << endl;
        }

        cout << string(55, '-') << endl;
    }
    cout << "Готово! Скопируйте данные в Excel для построения графиков.\n";
}

void PrintList(List& list)
{
    cout << "\nТекущий список: ";
    Node* current = list.GetHead();
    if (current == nullptr)
    {
        cout << "Пуст";
    }
    else
    {
        while (current != nullptr)
        {
            cout << current->GetData() << " ";
            current = current->GetNextNode();
        }
    }
    cout << endl;
}

void PrintMenu()
{
    cout << "\nМеню действий:\n";
    cout << "1. Добавить элемент в начало\n";
    cout << "2. Добавить элемент в конец\n";
    cout << "3. Удалить элемент по индексу\n";
    cout << "4. Удалить элемент по значению\n";
    cout << "5. Вставить элемент после определенного индекса\n";
    cout << "6. Вставить элемент перед определенным индексом\n";
    cout << "7. Сортировка списка (Пузырьком)\n";
    cout << "8. Линейный поиск элемента\n";
    cout << "9. Очистить список\n";
    cout << "10.Запустить исследование (для отчёта)\n";
    cout << "0. Выход\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List myList;
    int choice;

    do
    {
        PrintMenu();
        choice = GetIntInput("Ваш выбор: ");

        switch (choice)
        {
        case 1: // Вставка в начало
        {
            int val = GetIntInput("Введите значение: ");
            Node* newNode = new Node();
            newNode->SetData(val);
            myList.AddNode(newNode, 0);
            break;
        }
        case 2: // Вставка в конец
        {
            int val = GetIntInput("Введите значение: ");
            Node* newNode = new Node();
            newNode->SetData(val);
            myList.AddNode(newNode, myList.GetSize());
            break;
        }
        case 3: // Удаление по индексу
        {
            int index = GetIntInput("Введите индекс для удаления: ");
            if (!myList.RemoveNodeByIndex(index))
            {
                cout << "Ошибка: Индекс вне диапазона.\n";
            }
            break;
        }
        case 4: // Удаление по значению
        {
            int val = GetIntInput("Введите значение для удаления: ");
            myList.RemoveNodeByValue(val);
            break;
        }
        case 5: // Вставка после индекса
        {
            int index = GetIntInput("Введите индекс элемента, после которого вставить: ");
            int val = GetIntInput("Введите значение: ");

            Node* newNode = new Node();
            newNode->SetData(val);

            // ПРОВЕРКА: Если вставка не удалась, удаляем узел, чтобы не было утечки памяти
            if (!myList.AddNode(newNode, index + 1))
            {
                cout << "Ошибка: Некорректный индекс или список пуст.\n";
                delete newNode;
            }
            break;
        }
        case 6: // Вставка перед индексом
        {
            int index = GetIntInput("Введите индекс элемента, перед которым вставить: ");
            int val = GetIntInput("Введите значение: ");

            Node* newNode = new Node();
            newNode->SetData(val);

            // ПРОВЕРКА: Аналогично, удаляем узел при неудаче
            if (!myList.AddNode(newNode, index))
            {
                cout << "Ошибка: Некорректный индекс.\n";
                delete newNode;
            }
            break;
        }
        case 7: // Сортировка
        {
            myList.Sort();
            cout << "Список отсортирован.\n";
            break;
        }
        case 8: // Поиск
        {
            int val = GetIntInput("Введите значение для поиска: ");
            Node* found = myList.FindNodeByValue(val);
            if (found != nullptr)
            {
                cout << "Элемент найден: " << found->GetData() << endl;
                // Можно найти индекс для наглядности
                int index = 0;
                Node* curr = myList.GetHead();
                while (curr != found) { curr = curr->GetNextNode(); index++; }
                cout << "Индекс первого вхождения: " << index << endl;
            }
            else
            {
                cout << "Элемент не найден.\n";
            }
            break;
        }
        case 9: // Очистка
        {
            myList.Clean();
            cout << "Список очищен.\n";
            break;
        }
        case 10:
            RunPerformanceTest();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный пункт меню.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}