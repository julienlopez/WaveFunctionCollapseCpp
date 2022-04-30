#include <catch2/catch.hpp>

#include "MultiDimensionalArray.hpp"
#include "Ranges.hpp"

#include <gsl/narrow>

using LibWaveFunctionCollapseCpp::Ranges::iota;

TEST_CASE("MultiDimensionalArray 1D", "[MultiDimensionalArray]")
{

    using Mda = LibWaveFunctionCollapseCpp::MultiDimensionalArray<int, 1>;
    const auto length = 5_z;

    SECTION("Testing construction with initialization")
    {
        const int init_value = 3;
        const Mda mda{{length}, init_value};
        REQUIRE(mda.size() == Mda::Index{length});
        REQUIRE(mda.flatBuffer().size() == length);
        CHECK_THAT(mda.flatBuffer(), Catch::Matchers::Equals(std::vector<int>{3, 3, 3, 3, 3}));
    }

    SECTION("Testing the setting operator")
    {
        Mda mda{{length}};
        REQUIRE(mda.size() == Mda::Index{length});
        REQUIRE(mda.flatBuffer().size() == length);
        for(const auto i : iota(0_z, length))
        {
            mda({i}) = gsl::narrow<int>(i);
        }
        CHECK_THAT(mda.flatBuffer(), Catch::Matchers::Equals(std::vector<int>{0, 1, 2, 3, 4}));
    }
}

TEST_CASE("MultiDimensionalArray 2D", "[MultiDimensionalArray]")
{
    using Mda = LibWaveFunctionCollapseCpp::MultiDimensionalArray<int, 2>;
    const Mda::Index size{3_z, 2_z};

    SECTION("Testing the setting operator")
    {
        Mda mda{size};
        REQUIRE(mda.size() == size);
        REQUIRE(mda.flatBuffer().size() == size[0] * size[1]);
        for(const auto x : iota(0_z, size[0]))
            for(const auto y : iota(0_z, size[1]))
            {
                mda({x, y}) = gsl::narrow<int>(x + size[0] * y);
            }
        CHECK_THAT(mda.flatBuffer(), Catch::Matchers::Equals(std::vector<int>{0, 1, 2, 3, 4, 5}));
    }
}

TEST_CASE("MultiDimensionalArray 3D", "[MultiDimensionalArray]")
{
    using Mda = LibWaveFunctionCollapseCpp::MultiDimensionalArray<int, 3>;
    const Mda::Index size{4_z, 3_z, 2_z};

    SECTION("Testing the setting operator")
    {
        Mda mda{size};
        REQUIRE(mda.size() == size);
        REQUIRE(mda.flatBuffer().size() == size[0] * size[1] * size[2]);
        for(const auto z : iota(0_z, size[2]))
            for(const auto y : iota(0_z, size[1]))
                for(const auto x : iota(0_z, size[0]))
                {
                    mda({x, y, z}) = gsl::narrow<int>(x + size[0] * y + size[0] * size[1] * z);
                }
        CHECK_THAT(mda.flatBuffer(), Catch::Matchers::Equals(iota<int>(0, 24)));
    }
}
