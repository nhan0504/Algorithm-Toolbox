#include <iostream>
using namespace std;

uint64_t fibonacci_sum_squares(int64_t n) {
    if (n <= 1) {
        return n;
    }
    uint64_t f0 = 0;
    uint64_t f1 = 1;
	uint64_t f2 = 0;
    uint64_t sum = 1;
	uint64_t n2 = (n + 1 - 2) % 3;
	int n1 = n + 1 - 2 - n2;
	for (uint64_t i = 0; i < n1; i += 3) {
		f2 = f0 + f1;
		sum = sum + f2 * f2;
		f0 = f1 + f2;
		sum = sum + f0 * f0;
		f1 = f2 + f0;
		sum = sum + f1 * f1;
		
		if (sum > 9223372000) {
			sum = sum % 10;
			f0 %= 10;
			f1 %= 10;
			f2 %= 10;
		}
	}
	for (int i = 0; i < n2; i++) {
		f2 = (f0 + f1) % 10;
		sum = sum + f2 * f2;
		f0 = f1; f1 = f2;
	}
    return sum % 10;
}

int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares(n);
}
