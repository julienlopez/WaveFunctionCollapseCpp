#include <catch2/catch.hpp>

#include "WaveFunctionCollapse.hpp"

TEST_CASE("Factorials are computed", "[factorial]")
{

	SECTION("Construction initialize possible states")
    {
        using Wfc = LibWaveFunctionCollapseCpp::WaveFunctionCollapse<int, 2>;
        std::vector<int> states{1, 2, 3};
        const Wfc wfc{states};
        CHECK(wfc.possibleStates() == states);
    }

}
