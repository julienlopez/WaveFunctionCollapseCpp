#pragma once

#include <vector>
#include <algorithm>

namespace LibWaveFunctionCollapseCpp::Ranges
{

template <class T> 
std::vector<T> iota(const T& from, const T& to)
{
    std::vector<T> res(to - from);
    std::iota(begin(res), end(res), from);
    return res;
}

} // namespace LibWaveFunctionCollapseCpp
