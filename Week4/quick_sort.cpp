#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
void swap_xyz_to_zxy(vector<int>& a, int x, int y, int z) {
    int temp = a[z];
    a[z] = a[y];
    a[y] = a[x];
    a[x] = temp;
}

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
    int m2 = m1;
    int p = s;
    while (p < m1) {
        if (a[p] == x) {
            swap(a[p], a[m1 - 1]);
            m1--;
        }
        else if (a[p] > x) {
            swap_xyz_to_zxy(a, m2, m1 - 1, p);
            m1--;
            m2--;
        }
        else if (a[p] < x) {
            p++;
        }
    }

    int q = e;
    while (q > m2) {
        if (a[q] == x) {
            swap(a[q], a[m2 + 1]);
            m2++;
        }
        else if (a[q] < x) {
            swap_xyz_to_zxy(a, m1, m2 + 1, q);
            m1++;
            m2++;
        }
        else if (a[q] > x) {
            q--;
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