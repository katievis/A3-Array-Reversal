#pragma once

template <typename T>
void reverse_array(T* a, int n) {
    if (!a || n <= 1) return;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        T tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

template <typename T>
void print_array(const T* a, int n) {
    std::cout << "[";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i];
        if (i != n - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}
