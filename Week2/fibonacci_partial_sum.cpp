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

int get_fibonacci_partial_sum(int64_t from, int64_t to) {
	vector<int> remainder = get_remainder(10);
	int size = remainder.size();
	int64_t start = from % size;
	cout << "start = " << start << endl;
	int64_t end = to % size;
	cout << "end = " << end << endl;
	int64_t sum = 0;
	for (int i = start; i <= end; i++) {
		sum += remainder[i];
	}
    return sum % 10;
}

int main() {
    int64_t from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum(from, to) << '\n';
}
