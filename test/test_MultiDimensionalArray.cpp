#include <catch2/catch.hpp>

#include "MultiDimensionalArray.hpp"
#include "Ranges.hpp"

using LibWaveFunctionCollapseCpp::Ranges::iota;

TEST_CASE("MultiDimensionalArray 1D", "[MultiDimensionalArray]")
{

    const auto length = 5_z;

    SECTION("Testing construction with initialization")
    {
        using Mda = LibWaveFunctionCollapseCpp::MultiDimensionalArray<int, 1>;
        const int init_value = 3;
        const Mda mda{{length}, init_value};
        REQUIRE(mda.size() == Mda::Index{length});
        REQUIRE_THAT(mda.flatBuffer(), Catch::Matchers::Equals(std::vector<int>{3, 3, 3, 3, 3}));
    }

    SECTION("Testing the setting operator")
    {
	    using Mda = LibWaveFunctionCollapseCpp::MultiDimensionalArray<int, 1>;
        Mda mda{{length}};
        REQUIRE(mda.size() == Mda::Index{length});
        for(const auto i : iota(0_z, length))
        {
            mda({i}) = (int)i;
        }
        REQUIRE_THAT(mda.flatBuffer(), Catch::Matchers::Equals(std::vector<int>{0, 1, 2, 3, 4}));
    }

}
