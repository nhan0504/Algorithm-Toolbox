#include <iostream>
#include<vector>
using namespace std;

int get_change(int m) {
	int n = 0;
	vector<int> coin;
	coin.push_back(10);
	coin.push_back(5);
	coin.push_back(1);
	for (int i = 0; i != coin.size(); i++) {
		if (m != 0) {
			n += m / coin[i];
			m = m % coin[i];
		}
		else {
			break;
		}
	}
	return n;
}

int main() {
		int m;
		cin >> m;
		cout << get_change(m) << '\n';
}
