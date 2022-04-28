#include <catch2/catch.hpp>

#include "WaveFunctionCollapse.hpp"

TEST_CASE("Factorials are computed", "[factorial]")
{

	SECTION("Construction initialize possible states and the starting grid")
    {
        using Wfc = LibWaveFunctionCollapseCpp::WaveFunctionCollapse<int, 2>;
        std::vector<int> states{1, 2, 3};
        const Wfc wfc{states, {5, 4}};
        CHECK(wfc.possibleStates() == states);
    }

}
