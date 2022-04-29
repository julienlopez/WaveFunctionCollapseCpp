#include <catch2/catch.hpp>

#include "MultiDimensionalArray.hpp"

#include <ranges>
#include <algorithm>

TEST_CASE("MultiDimensionalArray 1D", "[MultiDimensionalArray]")
{

    SECTION("Testing construction with initialization")
    {
        using Mda = LibWaveFunctionCollapseCpp::MultiDimensionalArray<int, 1>;
        const std::size_t length = 5;
        const int init_value = 3;
        const Mda mda{{length}, init_value};
        REQUIRE(mda.size() == Mda::Index{length});
        REQUIRE_THAT(mda.flatBuffer(), Catch::Matchers::Equals(std::vector<int>{3, 3, 3, 3, 3}));
    }

    SECTION("Testing the setting operator")
    {
	    using Mda = LibWaveFunctionCollapseCpp::MultiDimensionalArray<int, 1>;
        const std::size_t length = 5;
        Mda mda{{length}};
        REQUIRE(mda.size() == Mda::Index{length});
        for(const auto i : std::views::iota((std::size_t)0, length))
        {
            mda({i}) = (int)i;
        }
        REQUIRE_THAT(mda.flatBuffer(), Catch::Matchers::Equals(std::vector<int>{0, 1, 2, 3, 4}));
    }

}
