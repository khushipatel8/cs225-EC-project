#include <catch2/catch_test_macros.hpp>
#include "stringMatch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Edge Cases
TEST_CASE("DNA_dataset_5 start match", "[weight=5]")
{
    bool expected = true;
    std::string infile = "../../documents/DNA_dataset_5.txt";
    std::string search = "CAGTC";
    bool out = search(infile, search);
    REQUIRE(expected == out);
}

//Substring case
TEST_CASE("DNA_dataset_50 substring match", "[weight=5]")
{
    bool expected = true;
    std::string infile = "../../documents/DNA_dataset_50.txt";
    std::string search = "GTCTAA";
    bool out = search(infile, search);
    REQUIRE(expected == out);
}

// Another generic test, could eventually make it test number of occurrences found, etc
TEST_CASE("DNA_dataset_500 match", "[weight=5]")
{
    bool expected = true;
    std::string infile = "../../documents/DNA_dataset_500.txt";
    std::string search = "GCGCTCATGT";
    bool out = search(infile, search);
    REQUIRE(expected == out);
}
