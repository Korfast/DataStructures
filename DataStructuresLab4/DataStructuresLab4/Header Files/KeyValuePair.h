#ifndef KEYVALUEPAIR_H
#define KEYVALUEPAIR_H

#include <string>

//! \brief Структура пары "ключ-значение".
struct KeyValuePair
{
private:
    //! \brief Ключ.
    std::string _key;
    //! \brief Значение.
    std::string _value;

public:
    //! \brief Создает пару "ключ-значение".
    //! \param key Ключ.
    //! \param value Значение.
    KeyValuePair(std::string key, std::string value);

    //! \brief Возвращает ключ.
    //! \return Ключ.
    std::string GetKey() const;

    //! \brief Возвращает значение.
    //! \return Значение.
    std::string GetValue() const;

    //! \brief Устанавливает значение.
    //! \param value Значение.
    void SetValue(std::string value);
};

#endif