#pragma once

#include <utility>

constexpr std::size_t operator"" _z(unsigned long long val)
{
    return val;
}