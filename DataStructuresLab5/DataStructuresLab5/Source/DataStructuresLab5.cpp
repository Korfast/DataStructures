#include <iostream>
#include "../Header/BinaryTree.h"
#include "../Header/Treap.h"
#include "../Header/IOBinaryTree.h"
#include "../Header/IOTreap.h"

using namespace std;

//! \brief Вывод главного меню.
void ShowMenu()
{
    cout << "\n========== ЛАБОРАТОРНАЯ РАБОТА 5 (ДЕРЕВЬЯ) ==========" << endl;
    cout << "1. Бинарное дерево поиска (BST)" << endl;
    cout << "2. Декартово дерево (Treap)" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите структуру: ";
}

//! \brief Подменю для работы с БДП.
void BinaryTreeMenu()
{
    BinaryTree tree;
    int choice, value;
    while (true)
    {
        cout << "\n--- Бинарное дерево поиска ---" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Найти элемент" << endl;
        cout << "4. Найти Минимум и Максимум" << endl;
        cout << "5. Вывести дерево" << endl;
        cout << "0. Назад" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) break;
        switch (choice)
        {
        case 1:
            cout << "Введите значение: "; cin >> value;
            tree.AddElement(value);
            break;
        case 2:
            cout << "Введите значение для удаления: "; cin >> value;
            tree.RemoveElement(value);
            break;
        case 3:
            cout << "Введите значение для поиска: "; cin >> value;
            if (tree.FindElement(value)) cout << "Элемент найден!" << endl;
            else cout << "Элемент НЕ найден." << endl;
            break;
        case 4:
        {
            BinaryTreeNode* minN = tree.GetMinNode();
            BinaryTreeNode* maxN = tree.GetMaxNode();
            if (minN) cout << "Мин: " << minN->GetValue() << ", Макс: " << maxN->GetValue() << endl;
            else cout << "Дерево пусто." << endl;
            break;
        }
        case 5:
            IOBinaryTree::Print(tree.GetRoot());
            break;
        }
    }
}

//! \brief Подменю для работы с Декартовым деревом.
void TreapMenu()
{
    Treap tree;
    int choice, k, p;
    while (true)
    {
        cout << "\n--- Декартово дерево (Treap) ---" << endl;
        cout << "1. Добавить (Неоптимизированно - Split/Merge)" << endl;
        cout << "2. Добавить (Оптимизированно - 1 проход)" << endl;
        cout << "3. Удалить (Неоптимизированно)" << endl;
        cout << "4. Удалить (Оптимизированно)" << endl;
        cout << "5. Найти элемент" << endl;
        cout << "6. Вывести дерево {Ключ;Приоритет}" << endl;
        cout << "0. Назад" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) break;
        switch (choice)
        {
        case 1:
        case 2:
            cout << "Введите ключ и приоритет: "; cin >> k >> p;
            if (choice == 1) tree.AddUnoptimized(k, p);
            else tree.AddOptimized(k, p);
            break;
        case 3:
        case 4:
            cout << "Введите ключ для удаления: "; cin >> k;
            if (choice == 3) tree.RemoveUnoptimized(k);
            else tree.RemoveOptimized(k);
            break;
        case 5:
            cout << "Введите ключ для поиска: "; cin >> k;
            if (tree.Find(k)) cout << "Ключ найден!" << endl;
            else cout << "Ключ НЕ найден." << endl;
            break;
        case 6:
            IOTreap::Print(tree.GetRoot());
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int mainChoice;
    while (true)
    {
        ShowMenu();
        cin >> mainChoice;
        if (mainChoice == 0) break;
        if (mainChoice == 1) BinaryTreeMenu();
        else if (mainChoice == 2) TreapMenu();
    }
    return 0;
}