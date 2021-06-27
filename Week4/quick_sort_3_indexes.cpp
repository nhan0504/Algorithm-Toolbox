#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> partition3(vector<int>& a, int s, int e) {
    int ranIndex = rand() % (e - s + 1);
    swap(a[s], a[ranIndex]);
    int i = s + 1;
    int j = s + 1;
    int k = e;
    while (j <= k) {
        if (a[j] < a[s]) {
            swap(a[i], a[j]);
            i++;
            j++;
        }
        else if (a[j] == a[s]) {
            j++;
        }
        else {
            swap(a[j], a[k]);
            k--;
        }
    }
    swap(a[s], a[i - 1]);
    i--;
    vector<int> index;
    index.push_back(i);
    index.push_back(j);
    return index;
}

void randomized_quick_sort(vector<int>& a, int s, int e) {
    if (s >= e) {
        return;
    }
    vector<int> part = partition3(a, s, e);
    randomized_quick_sort(a, s, part[0] - 1);
    randomized_quick_sort(a, part[1] + 1, e);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}