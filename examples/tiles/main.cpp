#include <functional>
#include <iostream>

#include <docopt/docopt.h>
#include <spdlog/spdlog.h>

#include <internal_use_only/config.hpp>

#include "WaveFunctionCollapse.hpp"

struct Tile
{
};

std::vector<Tile> possibleTiles()
{
    return {};
}

static constexpr auto USAGE =
    R"(WaveFunctionCollapse tiles example.

    Usage:
          tiles --size=<sz>
          tiles (-h | --help)
          tiles --version
 Options:
          -h --help     Show this screen.
          --version     Show version.
          --speed=<kn>  Speed in knots [default: 10].
          --moored      Moored (anchored) mine.
          --drifting    Drifting mine.
)";

int main(int argc, const char** argv)
{
    try
    {
        std::map<std::string, docopt::value> args
            = docopt::docopt(USAGE, {std::next(argv), std::next(argv, argc)},
                             true, // show help if requested
                             fmt::format("{} {}", WaveFunctionCollapseCpp::cmake::project_name,
                                         WaveFunctionCollapseCpp::cmake::project_version));

        for(auto const& arg : args)
        {
            std::cout << arg.first << "=" << arg.second << '\n';
        }

        // Use the default logger (stdout, multi-threaded, colored)
        spdlog::info("Hello, {}!", "World");

        fmt::print("Hello, from {}\n", "{fmt}");

        using WaveFunctionCollapse = LibWaveFunctionCollapseCpp::WaveFunctionCollapse<Tile, 2>;
        WaveFunctionCollapse wfc{possibleTiles(), {5, 4}};
    }
    catch(const std::exception& e)
    {
        fmt::print("Unhandled exception in main: {}", e.what());
    }
}
