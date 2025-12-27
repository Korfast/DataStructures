#include "../Header Files/KeyValuePair.h"

//! \brief Создает пару "ключ-значение".
KeyValuePair::KeyValuePair(std::string key, std::string value)
{
    _key = key;
    _value = value;
}

//! \brief Возвращает ключ.
std::string KeyValuePair::GetKey() const
{
    return _key;
}

//! \brief Возвращает значение.
std::string KeyValuePair::GetValue() const
{
    return _value;
}

//! \brief Устанавливает значение.
void KeyValuePair::SetValue(std::string value)
{
    _value = value;
}