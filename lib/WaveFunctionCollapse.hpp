#pragma once

#include "MultiDimensionalArray.hpp"

#include <vector>

namespace LibWaveFunctionCollapseCpp
{

template <class State, std::size_t N> class WaveFunctionCollapse
{
public:
	using Index = Point<std::size_t, N>;
	using PossibleStateContainer = std::vector<State>;
	using CurrentStateContainer = MultiDimensionalArray<State, N>;

	WaveFunctionCollapse() = delete;

	WaveFunctionCollapse(PossibleStateContainer possible_states, Index size)
        : m_possible_states{std::move(possible_states)}
        , m_current_state{size}
    {
    }

	const PossibleStateContainer& possibleStates() const
    {
        return m_possible_states;
    }

    const CurrentStateContainer& currentState() const
    {
        return m_current_state;
    }

private:
    const PossibleStateContainer m_possible_states;
    CurrentStateContainer m_current_state;
};

} // namespace LibWaveFunctionCollapseCpp
