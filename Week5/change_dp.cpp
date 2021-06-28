#include <iostream>
#include <vector>
using namespace std;

int get_change(int m) {
	vector<int> MinNumCoin(m + 1,0);
	for (int i = 1; i <= m; i++) {
		int min = MinNumCoin[i - 1] + 1;
		if (i >= 3) {
			int NumCoin3 = MinNumCoin[i - 3] + 1;
			if (NumCoin3 < min) {
				min = NumCoin3;
			}
		}
		if (i >= 4) {
			int NumCoin4 = MinNumCoin[i - 4] + 1;
			if (NumCoin4 < min) {
				min = NumCoin4;
			}
		}	
		MinNumCoin[i] = min;
	}	
	return MinNumCoin[m];
}

int main() {
	int m;
	cin >> m;
	cout << get_change(m) << '\n';
}
