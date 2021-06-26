#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void randomized_quick_sort(vector<int>& a, int s, int e) {
    if (s >= e) {
        return;
    }
    int vector_size = e - s + 1;
    if (vector_size == 2) {
        if (a[s] > a[e]) {
            swap(a[s], a[e]);
        }
        return;
    }
    int ranIndex = s + rand() % vector_size;
    int x = a[ranIndex];
    int m1 = ranIndex;
    int m2 = m1;
    int i = s;
    while (i <= e) {
        if (a[i] < x) {
            if (i > m2) {
                if (i != m2 + 1) {
                    swap(a[i], a[m2 + 1]);
                    i--;
                }
                swap(a[m2 + 1], a[m1]);
                m1++;
                m2++;
            }
            if (m1 == 0 || i == m1 - 1 || i == m1) {
                i = m2 + 1;
            }
            else {
                i++;
            }
        }
        else if (a[i] == x) {
            if (i >= m2) {
                swap(a[i], a[m2 + 1]);
                m2++;
            }
            else {
                swap(a[i], a[m1 - 1]);
                m1--;
                i--;
            }
            if (m1 == 0 || i == m1 - 1 || i == m1) {
                i = m2 + 1;
            }
            else {
                i++;
            }
        }
        else if (a[i] > x) {
            if (i < m1) {
                if (i != m1 - 1) {
                    swap(a[i], a[m1 - 1]);
                    i--;
                }
                swap(a[m1 - 1], a[m2]);
                m1--;
                m2--;
            }
            if (m1 == 0 || i == m1 - 1 || i == m1) {
                i = m2 + 1;
            }
            else {
                i++;
            }
        }
    }
    randomized_quick_sort(a, s, m1 - 1);
    randomized_quick_sort(a, m2 + 1, e);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
}