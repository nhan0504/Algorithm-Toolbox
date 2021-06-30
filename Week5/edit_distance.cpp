#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
	int size1 = str1.size() + 1;
	int size2 = str2.size() + 1;
	vector<int> initialize(size2, 0);
	vector<vector<int>> D(size1, initialize);
	for (int i = 0; i < size1; i++) {
		D[i][0] = i;
	}
	for (int j = 0; j < size2; j++) {
		D[0][j] = j;
	}
	for (int j = 1; j < size2; j++) {
		for (int i = 1; i < size1; i++) {
			int insertion = D[i][j - 1] + 1;
			int deletion = D[i - 1][j] + 1;
			int match = D[i - 1][j - 1];
			int mismatch = D[i - 1][j - 1] + 1;
			if (str1[i - 1] == str2[j - 1]) {
				D[i][j] = min(insertion, deletion);
				D[i][j] = min(D[i][j], match);
			}
			else {
				D[i][j] = min(insertion, deletion);
				D[i][j] = min(D[i][j], mismatch);
			}
		}
	}
	return D[str1.size()][str2.size()];
}

int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	cout << edit_distance(str1, str2) << endl;
	return 0;
}
