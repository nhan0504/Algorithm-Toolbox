#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void randomized_quick_sort(vector<int>& a, int s, int e) {
    if (s >= e) {
        return;
    }
    int ranIndex = s + rand() % (e - s + 1);
    int x = a[ranIndex];
    cout << "x = " << a[ranIndex] << endl;
    int m1 = s;
    while (a[m1] != x) {
        m1++;
    }
    cout << "m1 = " << m1 << endl;
    int m2 = m1;
    for (int i = 0; i < a.size(); i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
        if (a[i] < x) {
            if (i > m2 + 1) {
                swap(a[i], a[m2 + 1]);
                for (int j = 0; j < a.size(); j++) {
                    cout << a[j] << " ";
                }
                cout << endl;
                swap(a[m2 + 1], a[m1]);
                for (int j = 0; j < a.size(); j++) {
                    cout << a[j] << " ";
                }
                cout << endl;
                m1++;
                m2 = m1;
            }
            else if (i == m2 + 1) {
                swap(a[i], a[m1]);
                for (int j = 0; j < a.size(); j++) {
                    cout << a[j] << " ";
                }
                cout << endl;
                m1++;
                cout << "m1 = " << m1 << endl;
                m2++;
                cout << "m2 = " << m2 << endl;
            }

        }
        else if (m1 != i && a[i] == x) {
            m2++;
            if (i != m1 + 1) {
                swap(a[i], a[m2]);
            }
            for (int j = 0; j < a.size(); j++) {
                cout << a[j] << " ";
            }
            cout << endl;
        }
        else if (a[i] > x && i < m1) {
            swap(a[i], a[m2]);
            for (int j = 0; j < a.size(); j++) {
                cout << a[j] << " ";
            }
            cout << endl;
            m1--;
            cout << "m1 = " << m1 << endl;
            m2--;
            cout << "m2 = " << m2 << endl;
        }
    }
    if (m1 != 0){
        randomized_quick_sort(a, s, m1 - 1);
    }
    if (m2 != e) {
        randomized_quick_sort(a, m2 + 1, e);
    }
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
