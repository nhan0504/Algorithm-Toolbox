#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if (n == 1) {
	  summands.push_back(1);
  }
  if (n == 2) {
	  summands.push_back(2);
  }

  return summands;
}

int main() {
	int n;
	cin >> n;
	vector<int> summands = optimal_summands(n);
	cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		cout << summands[i] << ' ';
	}
}
