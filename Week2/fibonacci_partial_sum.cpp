#include <iostream>
#include <vector>
using namespace std;

int64_t get_fibonacci_partial_sum(int64_t from, int64_t to) {
    uint64_t f0 = 0;
    uint64_t f1 = 1;
    uint64_t f2 = 0;
	uint64_t sum = 0;
    uint64_t n = to - from + 1;
	if (from == 0) {
		n -= 2;
		sum = 1;
	}
	if (from == 0 && to == 0) {
		return 0;
	}
	if (from == 1) {
		n -= 1;
		sum = 1;
	}
	uint64_t n2 = n % 3;
    uint64_t n1 = n - n2;
    int i = 2;
    while (i < from) {
        f2 = (f0 + f1) % 10;
        f0 = f1;
        f1 = f2;
        i++;
    }
	
	for (uint64_t i = 0; i < n1; i += 3) {
		f2 = f1 + f0;
		sum = sum + f2;
		f0 = f1 + f2;
		sum = sum + f0;
		f1 = f2 + f0;
		sum = sum + f1;

		if (sum > 922337205) {
			sum = sum % 10;
			f0 %= 10;
			f1 %= 10;
			f2 %= 10;
		}
	}
	for (int i = 0; i < n2; i++) {
		f2 = (f0 + f1) % 10;
		sum = sum + f2;
		f0 = f1; f1 = f2;
	}
    return sum % 10;
}

int main() {
    int64_t from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum(from, to) << '\n';
}
