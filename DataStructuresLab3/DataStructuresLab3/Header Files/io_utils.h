// io_utils.h
#ifndef IO_UTILS_H
#define IO_UTILS_H
#include <iostream>
#include <limits>

// ќбъ€вление с inline, чтобы избежать ошибки линковки
inline void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
#endif