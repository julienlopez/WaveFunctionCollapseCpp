#pragma once

#include "Literals.hpp"
#include "Point.hpp"
#include "Ranges.hpp"

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

namespace LibWaveFunctionCollapseCpp
{

template <class T, std::size_t N> class MultiDimensionalArray
{
public:
    using Index = Point<std::size_t, N>;
    using Container = std::vector<T>;

    static_assert(N > 0, "The number of dimensions cannot be zero");

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
        const auto flat_index = flatIndex(index);
        return m_container[flat_index];
    }

private:
    const Index m_size;
    Container m_container;

    static std::size_t bufferSizeFromIndex(const Index& index)
    {
        return std::reduce(std::begin(index), std::end(index), 1_z, std::multiplies<std::size_t>{});
    }

    /**
     * @brief turns [a, b, c, d] into [1, a, b, c]
     */
    static Index shiftRight(Index index)
    {
        std::shift_right(begin(index), end(index), 1);
        index[0] = 1;
        return index;
    }

    std::size_t flatIndex(const Index& index) const
    {
        const auto factors = compoundRight(shiftRight(m_size));
        return std::inner_product(begin(index), end(index), begin(factors), 0_z);
    }

    /**
     * @brief turns [a, b, c, d] into [a, a*b, a*b*c, a*b*c*d]
     */
    Index compoundRight(Index index) const
    {
        for(auto it = begin(index); it != end(index); ++it)
        {
            const auto next = it + 1;
            std::transform(next, end(index), next, std::bind_front(std::multiplies<std::size_t>{}, *it));
        }
        return index;
    }
};

} // namespace LibWaveFunctionCollapseCpp
