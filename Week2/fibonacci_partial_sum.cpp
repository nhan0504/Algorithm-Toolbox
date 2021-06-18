#include <iostream>
#include <vector>
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

uint64_t get_fibonacci_partial_sum(int64_t from, int64_t to) {
	vector<int> remainder = get_remainder(10);
	for (int i = 0; i < 60; i++) {
		cout << remainder[i] << " ";
	}
	cout << endl;
    uint64_t f0 = 0;
    uint64_t f1 = 1;
    uint64_t f2 = 0;
	uint64_t sum = 0;
    uint64_t n = to - from + 1;
	if (from == 0 && to == 0) {
		return 0;
	}
	if (from == 0) {
		n -= 2;
		sum = 1;
		from = 2;
	}
	if (from == 1) {
		n -= 1;
		sum = 1;
		from = 2;
	}
	
	//Calculate last digit before Fm
	uint64_t s2 = (from - 2) % 3;	
	uint64_t s1 = from - 2 - s2;
	//cout << "s1 = " << s1 << endl;
	//cout << "s2 = " << s2 << endl;
	for (uint64_t i = 0; i < s1; i += 3) {
		f2 = f1 + f0;
		f0 = f1 + f2;
		f1 = f2 + f0;
		if (f2 > 922337205) {
			//f2 %= 10;
			f1 %= 10;
			f0 %= 10;
		}
	}
	for (int i = 0; i < s2; i++) {
		f2 = (f0 + f1) % 10;
		f0 = f1; f1 = f2;
	}
	//cout << "f0 = " << f0 % 10 << endl;
	//cout << "f1 = " << f1 % 10 << endl;

	//Calculate last digit of sum from Fm to Fn
	uint64_t n2 = n % 3;
	uint64_t n1 = n - n2;
	for (uint64_t i = 0; i < n1; i += 3) {
		f2 = f1 + f0;
		sum = sum + f2;
		f0 = f1 + f2;
		sum = sum + f0;
		f1 = f2 + f0;
		sum = sum + f1;

		if (sum > 922337205) {
			sum = sum % 10;
			//f2 %= 10;
			f1 %= 10;
			f0 %= 10;
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
