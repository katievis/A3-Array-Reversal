#include <catch2/catch_test_macros.hpp>
#include "reverse.hpp"
#include <cstring>

template <typename T>
static bool arrays_equal(const T* a, const T* b, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

TEST_CASE("reverse_array<int> reverses in place") {
    int a[] = {1,2,3,4,5};
    int n = arr_size(a);
    int expected[] = {5,4,3,2,1};

    reverse_array(a, n);
    REQUIRE(arrays_equal(a, expected, n));

    reverse_array(a, n); 
    int original[] = {1,2,3,4,5};
    REQUIRE(arrays_equal(a, original, n));
}

TEST_CASE("reverse_array<double> reverses in place") {
    double a[] = {1.5, 2.5, 3.5, 4.5};
    int n = arr_size(a);
    double expected[] = {4.5, 3.5, 2.5, 1.5};

    reverse_array(a, n);
    REQUIRE(arrays_equal(a, expected, n));
}

TEST_CASE("reverse_array<char> on raw char array") {
    char letters[] = {'E','C','E','3','5','1','4'};
    int n = arr_size(letters);
    char expected[] = {'4','1','5','3','E','C','E'};

    reverse_array(letters, n);
    REQUIRE(arrays_equal(letters, expected, n));
}

TEST_CASE("reverse_array<char> on C-string") {
    char word[] = "hello";
    int n = static_cast<int>(std::strlen(word));
    reverse_array(word, n);
    REQUIRE(std::strcmp(word, "olleh") == 0);
}

TEST_CASE("reverse_array handles edge cases") {
    int* null_ptr = nullptr;
    reverse_array(null_ptr, 10); 

    int single[] = {42};
    reverse_array(single, 1);
    REQUIRE(single[0] == 42);

    int empty_arr[1] = {7};
    reverse_array(empty_arr, 0);
    REQUIRE(empty_arr[0] == 7);
}
