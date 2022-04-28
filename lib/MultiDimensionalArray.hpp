#pragma once

#include "Point.hpp"

#include <vector>

namespace LibWaveFunctionCollapseCpp
{

template <class T, std::size_t N> class MultiDimensionalArray
{
public:
    using Index = Point<std::size_t, N>;
    using Container = std::vector<T>;

    MultiDimensionalArray() = delete;

    MultiDimensionalArray(Index size)
        : m_size{std::move(size)}
    {
    }
    const Index& size() const
    {
        return m_size;
    }

    // T& operator()(const Index& index)
    // {
    // }

private:
    const Index m_size;
    Container m_container;
};

} // namespace LibWaveFunctionCollapseCpp
