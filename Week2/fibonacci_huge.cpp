#include <iostream>
#include<vector>
using namespace std;

int64_t get_fibonacci_huge(int64_t n, int64_t m) {
    vector<int> remainder;
    remainder.push_back(0);
    remainder.push_back(1);
    int f0 = 0;
    int f1 = 1;
    int f2 = 0;
    for (int i = 2; i <= m * m; i++) {
        f2 = (f0 + f1) % m;
        remainder.push_back(f2);
        f0 = f1;
        f1 = f2;
        if (f0 == 0 && f1 == 1) {
            break;
        }
    }
    int period = remainder.size() - 2;
    return remainder[n % period]; 
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge(n, m) << '\n';
}
