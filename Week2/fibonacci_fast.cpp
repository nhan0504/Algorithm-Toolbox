#include <iostream>
#include<vector>
using namespace std;
int fibonacci_fast(int n) {
    vector<int> fibonacci(2, 1);
    if (n <= 1) {
        return 1;
    }
    int i = 0;
    int a = 0;
    while (i != n - 2) {
        a = fibonacci[i] + fibonacci[i + 1];
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