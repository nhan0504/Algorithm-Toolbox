#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
void swap_3_numbers(vector<int>& a, int x, int y, int z) {
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
    int i = s;
    while (i <= e) {
        if (a[i] < x) {
            if (i > m2) {
                swap_3_numbers(a, m1, m2 + 1, i);
                i--;
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
            swap_3_numbers(a, i, m1 - 1, m2);
            i--;
            m1--;
            m2--;             
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
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}