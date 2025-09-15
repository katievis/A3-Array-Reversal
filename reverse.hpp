#pragma once
#include <iostream>
#include <cstddef>

namespace util {

// reverse first n elements 
template <typename T>
void reverse_array(T* a, int n);

// Prints first n elements of array 
template <typename T>
void print_array(const T* a, int n);

// Helper 
template <typename T, std::size_t N>
constexpr int arr_size(const T (&)[N]) {
    return static_cast<int>(N);
}

} 

#include "reverse.ipp"
