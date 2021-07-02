#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int64_t eval(int64_t a, int64_t b, char op) {
	if (op == '*') {
		return a * b;
	} else if (op == '+') {
		return a + b;
	} else if (op == '-') {
		return a - b;
	} else {
		assert(0);
	}
}

vector<int64_t> MinAndMax(int i, int j, vector<vector<int64_t>> m, vector<vector<int64_t>> M, const string& exp) {
	vector<int64_t> MinAndMax;
	int64_t Max = numeric_limits<int64_t>::min();
	int64_t Min = numeric_limits<int64_t>::max();
	for (int k = 2 * i + 1; k < 2 * j; k += 2) {
		int64_t a = eval(M[i][(k - 1) / 2], M[(k + 1) / 2][j], exp[k]);
		int64_t b = eval(M[i][(k - 1) / 2], m[(k + 1) / 2][j], exp[k]);
		int64_t c = eval(m[i][(k - 1) / 2], M[(k + 1) / 2][j], exp[k]);
		int64_t d = eval(m[i][(k - 1) / 2], m[(k + 1) / 2][j], exp[k]);
		Min = min(Min, a);
		Min = min(Min, b);
		Min = min(Min, c);
		Min = min(Min, d);
		Max = max(Max, a);
		Max = max(Max, b);
		Max = max(Max, c);
		Max = max(Max, d);
	}
	MinAndMax.push_back(Min);
	MinAndMax.push_back(Max);
	return MinAndMax;
}

int64_t get_maximum_value(const string& exp) {
	//convert char to int
	vector<int64_t> numbers;
	for (int i = 0; i < exp.size(); i += 2) {
		int64_t num = (int64_t)exp[i] - 48;
		numbers.push_back(num);
	}

	//create 2 tables to store max and min values
	int table_size = exp.size() / 2 + 1;
	vector<int64_t> initialize(table_size, 0);
	vector<vector<int64_t>> m(table_size, initialize);
	vector<vector<int64_t>> M(table_size, initialize);

	//Fill first diagonal of both table
	for (int i = 0; i < table_size; i++) {
		m[i][i] = numbers[i];		
		M[i][i] = numbers[i];
	}
	
	//Fill the rest diagonals
	for (int s = 1; s < table_size; s++) {
		for (int i = 0; i < table_size - s; i++) {
			int j = i + s;
			vector<int64_t> MinMaxVal = MinAndMax(i, j, m, M, exp);
			m[i][j] = MinMaxVal[0];
			M[i][j] = MinMaxVal[1];
		}
	}
	return M[0][table_size - 1];
}

int main() {
	string s;
	cin >> s;
	cout << get_maximum_value(s) << '\n';
	return 0;
}
