// Author: H. Hristov
#include <iostream>

int main() {
    short n; std::cin >> n;
    if (n <= 2) { std::cout << 2; return 0; }
    std::cout << (1ULL << ((n-1) >> 1));
    return 0;
}