#include<iostream>
#include<vector>
using namespace std;

int MaxPairwiseProductFast(vector<int64_t> numbers) {
	int index1 = 0;
	for (int i = 1; i != numbers.size(); i++) {
		if (numbers[i] > numbers[index1]) {
			index1 = i;
		}
	}
	int index2;
	if (index1 == 0) {
		index2 = 1;
	}
	else {
		index2 = 0;
	}
	for (int i = 0; i != numbers.size(); i++) {
		if (i != index1 && numbers[i] > numbers[index2]) {
			index2 = i;
		}
	}
	int64_t product = numbers[index1] * numbers[index2];
	return product;
}

int main() {
	int n;
	cout << "Enter list size: ";
	cin >> n;
	vector<int64_t> numbers(n);
	cout << "Enter all the element for list:" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	cout << "maximum product of two numbers = " << MaxPairwiseProductFast(numbers);
	return 0;
}