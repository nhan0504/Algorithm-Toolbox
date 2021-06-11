#include<iostream>
#include<vector>
using namespace std;

int MaxPairwiseProduct(const vector<int>& numbers) {
	int max_product = 0;
	int n = numbers.size();
	for (int first = 0; first < n; first++) {
		for (int second = first + 1; second < n; second++) {
			max_product = max(max_product, numbers[first] * numbers[second]);
		}
	}
	return max_product;
}

int64_t MaxPairwiseProductFast(vector<int> numbers) {
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

void StressTest(int N, int M) {
	while (true) {
		int n = rand() % N + 2;
		vector<int> array(n);
		for (int i = 0; i != n; i++) {
			array[i] = rand() % M;
		}
		int64_t result1 = MaxPairwiseProduct(array);
		int64_t result2 = MaxPairwiseProductFast(array);
		if (result1 == result2) {
			cout << "Okay" << endl;
		}
		else {
			cout << "Wrong answer: " << "result1 = " << result1 << "result2 = " << result2;
			for (int i = 0; i != n; i++) {
				cout << array[i] << "\t";
			}
			return;
		}
	}
}

int main() {
	//Test with input data
	int n;
	cout << "Enter list size: ";
	cin >> n;
	vector<int> numbers(n);
	cout << "Enter all the element for list:" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}
	cout << "maximum product of two numbers = " << MaxPairwiseProductFast(numbers) << endl;

	//Test with large input
	vector<int> large(2 * pow(10,5));
	for (int i = 1; i <= 2 * pow(10,5); i++) {
		large[i - 1] = i;
	}
	cout << "maximum product of two numbers = " << MaxPairwiseProductFast(large);
	StressTest(1000, 10000);
	return 0;
}