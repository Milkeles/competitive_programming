#include <bits/stdc++.h>

using namespace std;

int ceil(int a, int b) {
    return (a / b) + (a ^ b && a % b);
}

int floor(int a, int b) {
    return (a / b) - (a ^ b && a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    auto ceil= [](int a, int b) {
        return (a / b) + (a ^ b && a % b);
    };

    auto floor = [](int a, int b) {
        return (a / b) - (a ^ b && a % b);
    };
    
}