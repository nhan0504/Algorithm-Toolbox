#include <iostream>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;

bool cmp(pair<double,int>& i, pair<double,int>& j) {
	return i.first > j.first;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	map<double,int> compare;
	for (int i = 0; i != weights.size(); i++) {
		double a = values[i] / (double)weights[i];
		compare[a] = i;
	}
	vector<pair<double, int>> Sorted(compare.begin(),compare.end());
	sort(Sorted.begin(), Sorted.end(), cmp);
	for (vector<pair<double,int>>::iterator i = Sorted.begin(); i != Sorted.end(); i++) {
		int index = i->second;
		if (weights[index] <= capacity) {
			value += values[index];
			capacity -= weights[index];
		}
		else {
			value += (double)capacity * i->first;
			break;
		}
	}
	return value;
}

int main() {
	int n;
	int capacity;
	cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i] >> weights[i];
	}
	double optimal_value = get_optimal_value(capacity, weights, values);
	cout.precision(10);
	cout << optimal_value << endl;
	return 0;
}
