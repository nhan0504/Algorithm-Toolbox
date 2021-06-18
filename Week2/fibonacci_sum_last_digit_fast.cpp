#include <iostream>
using namespace std;

int fibonacci_last_digit_fast(int n) {
	if (n <= 1) {
		return n;
	}
	uint64_t f0 = 0;
	uint64_t f1 = 1;
	uint64_t f2 = 0;
	uint64_t sum = 1;
	int n2 = (n + 1 - 2) % 3;
	int n1 = n + 1 - 2 - n2;
	for (int64_t i = 0; i < n1; i += 3) {
		f2 = f1 + f0;
		sum = sum + f2;
		f0 = f1 + f2;
		sum = sum + f0;
		f1 = f2 + f0 ;
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
	int n;
	cin >> n;
	cout << fibonacci_last_digit_fast(n) << '\n';
}
