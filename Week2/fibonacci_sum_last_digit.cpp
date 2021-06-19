#include <iostream>
#include<vector>
using namespace std;

vector<int> get_remainder(int64_t n) {
    vector<int> remainder;
    remainder.push_back(0);
    remainder.push_back(1);
    int a = 0;
    int b = 1;
    for (int i = 0; i < 58; i++) {
        int c = a;
        a = b;
        b = (c + b) % n;
        remainder.push_back(b);
    }
    return remainder;
}

int fibonacci_last_digit_fast(uint64_t n) {
    vector<int> remainder = get_remainder(10);
    if (n <= 1) {
        return n;
    }
    int end = n % 60;
    int sum = 0;
    for (int i = 0; i <= end; i++) {
        sum += remainder[i];
    }
    return sum % 10;
}

int main() {
    int64_t n;
    cin >> n;
    cout << fibonacci_last_digit_fast(n) << '\n';
}
