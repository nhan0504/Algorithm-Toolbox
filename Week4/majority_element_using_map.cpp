#include <algorithm>
#include <iostream>
#include <vector>
#include<map>

using namespace std;

int get_majority_element(vector<int>& a, int min, int max) {
	if (min == max) {
		return -1;
	}
	if (min + 1 == max) {
		return a[min];
	}
	map<int, int> freq;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		freq[a[i]]++;
	}
	for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
		if (it->second > size / 2) {
			return it->first;
		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		cin >> a[i];
	}
	cout << (get_majority_element(a, 0, n) != -1) << '\n';
}
