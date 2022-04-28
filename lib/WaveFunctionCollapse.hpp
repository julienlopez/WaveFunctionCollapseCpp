#pragma once

#include "Point.hpp"

#include <vector>

namespace LibWaveFunctionCollapseCpp
{

template <class State, std::size_t N> class WaveFunctionCollapse
{
public:
	using Index = Point<std::size_t, N>;
	using StateContainer = std::vector<State>;

	WaveFunctionCollapse() = delete;

	WaveFunctionCollapse(StateContainer possible_states)
        : m_possible_states{std::move(possible_states)}
    {
    }

	const StateContainer& possibleStates() const
    {
        return m_possible_states;
    }

private:
    const StateContainer m_possible_states;
};

} // namespace LibWaveFunctionCollapseCpp
