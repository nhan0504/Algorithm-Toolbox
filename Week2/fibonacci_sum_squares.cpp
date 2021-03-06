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

int fibonacci_sum_squares(int64_t n) {
	vector<int> remainder = get_remainder(10);
	int size = remainder.size();
    if (n <= 1) {
        return n;
    }
	int end = n % size;
    int sum = (int)remainder[end] * remainder[end + 1];
    return sum % 10;
}

int main() {
    int64_t n = 0;
    cin >> n;
    cout << fibonacci_sum_squares(n);
}
