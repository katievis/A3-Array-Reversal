#include "reverse.hpp"
#include <cstring>  // for std::strlen

int main() {
    // int[]
    int ai[]{1, 2, 3, 4};
    int ni = arr_size(ai);
    std::cout << "ai: ";
    print_array(ai, ni);
    reverse_array(ai, ni);
    std::cout << "ai: ";
    print_array(ai, ni);

    // double[]
    double ad[] = {1.5, 2.5, 3.5, 4.5};
    int nd = arr_size(ad);
    std::cout << "ad: ";
    print_array(ad, nd);
    reverse_array(ad, nd);
    std::cout << "ad: ";
    print_array(ad, nd);

    // char[] (not a C-string)
    char letters[] = {'E','C','E','3','5','1','4'};
    int nc = arr_size(letters);
    std::cout << "letters: ";
    print_array(letters, nc);
    reverse_array(letters, nc);
    std::cout << "letters: ";
    print_array(letters, nc);

    // C-string: reverse only the characters, not the '\0'
    char word[] = "hello";
    std::cout << "cstr: " << word << "\n";
    int nw = static_cast<int>(std::strlen(word));
    reverse_array(word, nw);
    std::cout << "cstr: " << word << "\n";

    return 0;
}


/*
 Expected Output
 ai: : [1, 2, 3, 4]
 ai: : [4, 3, 2, 1]
 ad: : [1.5, 2.5, 3.5, 4.5]
 ad: : [4.5, 3.5, 2.5, 1.5]
 letters: : [E, C, E, 3, 5, 1, 4]
 letters: : [4, 1, 5, 3, E, C, E]
 cstr: hello
 cstr: olleh
 */