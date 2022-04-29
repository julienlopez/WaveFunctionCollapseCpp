#pragma once

#include "Literals.hpp"
#include "Point.hpp"

#include <numeric>
#include <vector>

namespace LibWaveFunctionCollapseCpp
{

template <class T, std::size_t N> class MultiDimensionalArray
{
public:
    using Index = Point<std::size_t, N>;
    using Container = std::vector<T>;

    MultiDimensionalArray() = delete;

    explicit MultiDimensionalArray(Index size)
        : m_size{std::move(size)}
        , m_container(bufferSizeFromIndex(size))
    {
    }

    MultiDimensionalArray(Index size, const T& value)
        : m_size{std::move(size)}
        , m_container(bufferSizeFromIndex(size), value)
    {
    }

    const Index& size() const
    {
        return m_size;
    }

    const Container& flatBuffer() const
    {
        return m_container;
    }

    T& operator()(const Index& index)
    {
        return m_container[index[0]];
    }

private:
    const Index m_size;
    Container m_container;

    static std::size_t bufferSizeFromIndex(const Index& index)
    {
        return std::reduce(std::begin(index), std::end(index), 0_z);
    }
};

} // namespace LibWaveFunctionCollapseCpp
