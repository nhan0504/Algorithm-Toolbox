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
    int m1 = s + rand() % vector_size;
    int x = a[m1];
    cout << "x = " << x << endl;
    int m2 = m1;
    int p = s;
    cout << "p = " << p << endl;
    cout << "m1 = " << m1 << endl;
    while (p < m1) {
        if (a[p] == x) {
            swap(a[p], a[m1 - 1]);
            p++;
            for (int i = 0; i < e; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        else if (a[p] > x) {
            swap(a[p], a[m2 + 1]);
            p++;
            for (int i = 0; i < e; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        else if (a[p] < x) {
            p++;
            for (int i = 0; i < e; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
    int q = e;
    cout << "m2 = " << m2 << endl;
    cout << "q = " << q << endl;
    while (q > m2) {
        if (a[q] == x) {
            swap(a[q], a[m2 + 1]);
            q--;
            for (int i = 0; i < e; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        else if (a[q] < x) {
            swap(a[q], a[m1 - 1]);
            q--;
            for (int i = 0; i < e; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        else if (a[q] > x) {
            q--;
            for (int i = 0; i < e; i++) {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
    randomized_quick_sort(a, s, m1 - 1);
    randomized_quick_sort(a, m2 + 1, e);
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