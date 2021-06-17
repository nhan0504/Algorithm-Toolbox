#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<int>& a, int x) {
    int minIndex = 0;
    int maxIndex = a.size() - 1; 
    while (maxIndex >= minIndex) {
        int mid = (minIndex + maxIndex) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            minIndex = mid + 1;
        }
        else if (a[mid] > x) {
            maxIndex = mid - 1;
        }
    }
    return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
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
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
    cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cout << binary_search(a, b[i]) << ' ';
    }
}
