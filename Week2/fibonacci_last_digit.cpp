#include <iostream>
#include<vector>
using namespace std;
int64_t fibonacci_fast(int n) {
    vector<int64_t> fibonacci(2, 1);
    if (n <= 2 && n > 0) {
        return 1;
    }
    else if (n <= 0) {
        return 0;
    }
    int i = 0;
    int64_t a = 0;
    while (i != n - 2) {
        a = (fibonacci[i] + fibonacci[i + 1]) % 10;
        fibonacci.push_back(a);
        i++;
    }
    return a;
}

int main() {
    int n = 0;
    cin >> n;
    cout << fibonacci_fast(n) << '\n';
    return 0;
}