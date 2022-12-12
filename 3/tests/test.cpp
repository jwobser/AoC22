#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE
#include "../catch.hpp"
#include "../main.hpp"

TEST_CASE("Check Lowercase Scoring", "[Scoring]"){
    REQUIRE(score_priority('a') == 1);
    REQUIRE(score_priority('z') == 26);
}

TEST_CASE("Check Uppercase Scoring", "[Scoring]"){
    REQUIRE(score_priority('A') == 27);
    REQUIRE(score_priority('Z') == 52);
}

TEST_CASE("Check String Length", "[Logic]"){
    REQUIRE_THROWS(check_len("abc"));
    REQUIRE(check_len("abcd"));
}

TEST_CASE("Check Duplicates", "[Logic]"){
    REQUIRE(find_duplicates("aa")[0] == 'a');
    REQUIRE(find_duplicates("abba")[0] == 'b');
    // Will never have 2nd item in return vector
    // REQUIRE(find_duplicates("abba")[1] == 'a');
}

