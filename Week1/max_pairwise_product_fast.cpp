#include<iostream>
#include<vector>
using namespace std;

int64_t MaxPairwiseProductFast(vector<int64_t> numbers) {
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
	cout << "product = " << product << endl;
	return product;
}

int main() {
	//Test with input data
	int n;
	cout << "Enter list size: ";
	cin >> n;
	vector<int64_t> numbers(n);
	cout << "Enter all the element for list:" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}
	cout << "maximum product of two numbers = " << MaxPairwiseProductFast(numbers) << endl;

	//Test with large input
	vector<int64_t> large(2 * pow(10,5));
	for (int64_t i = 1; i <= 2 * pow(10,5); i++) {
		large[i - 1] = i;
	}
	cout << "maximum product of two numbers = " << MaxPairwiseProductFast(large);
	return 0;
}