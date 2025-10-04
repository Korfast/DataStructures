#include <iostream>
#include <string>

struct Person
{
    //! Имя человека.
    std::string FirstName;

    //! Фамилия человека.
    std::string LastName;

    //! Возраст человека.
    unsigned Age;
};

struct Product
{
    //! Название продукта.
    std::string Name;

    //! Стоимость продукта.
    unsigned Cost;

    //! Вес продукта.
    unsigned Weight;
};

//! \brief Выводит в консоль данные о человеке.
/**
 * \param person – данные о человеке.
 */
void WritePerson(const Person& person)
{
    std::cout << "First Name: " + person.FirstName
        + "; Last Name: " + person.LastName
        + "; Age: " + std::to_string(person.Age)
        << std::endl;
}

//! \brief Выводит в консоль данные о продукте.
/**
 * \param product – данные о продукте.
 */
void WriteProduct(const Product& product)
{
    std::cout << "Name: " + product.Name
        + "; Cost: " + std::to_string(product.Cost)
        + "; Weight: " + std::to_string(product.Weight)
        << std::endl;
}

//! \brief Количество людей в массиве.
const int PeopleCount = 5;

//! \brief Создает массив людей.
/**
 * \return Массив указателей на объекты структуры человека \see People.
 */
Person** CreatePeopleArray()
{
    Person** people = new Person * [PeopleCount];

    people[0] = new Person();
    people[0]->FirstName = "Casey";
    people[0]->LastName = "Aguilar";
    people[0]->Age = 30;

    people[1] = new Person();
    people[1]->FirstName = "Brock";
    people[1]->LastName = "Curtis";
    people[1]->Age = 19;

    people[2] = new Person();
    people[2]->FirstName = "Blake";
    people[2]->LastName = "Diaz";
    people[2]->Age = 21;

    people[3] = new Person();
    people[3]->FirstName = "Cristian";
    people[3]->LastName = "Evans";
    people[3]->Age = 55;

    people[4] = new Person();
    people[4]->FirstName = "Les";
    people[4]->LastName = "Foss";
    people[4]->Age = 4;

    return people;
}

//! \brief Очищает из памяти объект человека \see Person.
/**
 * \param person – объект человека \see Person.
 */
void ClearPerson(Person* person)
{
    delete person;
}

//! \brief Очищает массив указателей на объекты в динамической памяти людей 
//! \see
/**
 * \param people – массив объектов в динамической памяти людей.
 * \param itemsCount – количество элементов в массиве.
 */
void ClearPeople(Person** people, int itemsCount)
{
    for (int i = 0; i < itemsCount; i++)
    {
        ClearPerson(people[i]);
    }
    delete[] people;
}

// Функция поиска человека по фамилии, 
// возвращает индекс или -1, если не найдено
int FindPersonIndexByLastName(Person** people,
    int count, const std::string& lastName)
{
    for (int i = 0; i < count; i++)
    {
        if (people[i]->LastName == lastName)
        {
            return i;
        }
    }
    return -1;
}

// Задание 1. Поиск человека по фамилии.
void Task1_FindPersonByLastName()
{
    Person** people = CreatePeopleArray();
    std::cout << "Task 1 - Find Person by Last Name\n";
    for (int i = 0; i < PeopleCount; i++)
    {
        WritePerson(*people[i]);
    }

    std::string lastName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    // ВНИМАНИЕ: Здесь нужно реализовать логику поиска.
    // Вызов функции
    int foundIndex = FindPersonIndexByLastName(people, PeopleCount, lastName);


    if (foundIndex == -1)
    {
        std::cout << "Could not find a person by last name: " 
            << lastName << std::endl;
    }
    else
    {
        std::cout << "A person's last name " << lastName
            << " was found. Its index in the array is " 
            << foundIndex << std::endl;
    }

    ClearPeople(people, PeopleCount);
}

int main()
{
    Task1_FindPersonByLastName();
}