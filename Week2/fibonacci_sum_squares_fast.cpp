#include <iostream>
using namespace std;

uint64_t fibonacci_sum_squares(int64_t n) {
    if (n <= 1) {
        return n;
    }
    int64_t previous = 0;
    int64_t current = 1;
    for (int i = 0; i < n; i++) {
        int64_t temp_previous = previous;
        previous = current;
        current = temp_previous + current;
        if (current > 922337205) {
            current %= 10;
            previous %= 10;
        }
    }
    int64_t sum = (int64_t)current * previous;
    return sum % 10;
}

int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares(n);
}
