#include <iostream>
using namespace std;

int fibonacci_last_digit_fast(int n) {
    if (n <= 1) {
        return n;
    }  
    int previous = 0;
    int current  = 1;
    int sum = 1;
    for (int i = 0; i < n - 1; i++) {
        int temp_previous = previous;
        previous = current;
        current = (temp_previous + current) % 10;
        sum = (sum + current) % 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci_last_digit_fast(n) << '\n';
    }
