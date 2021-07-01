#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int>& w) {
    vector<int> initialize(w.size() + 1, 0);
    vector<vector<int>> value(W + 1, initialize);
    for (int j = 1; j <= w.size(); j++) {
        for (int i = 1; i <= W; i++) {
            value[i][j] = value[i][j - 1];
            if (w[j - 1] <= i) {
                int val = value[i - w[j - 1]][j - 1] + w[j - 1];
                value[i][j] = max(value[i][j], val);
            }
        }
    }
    return value[W][w.size()];
}

int main() {
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << optimal_weight(W, w) << '\n';
}