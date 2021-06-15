#include <iostream>
using namespace std;

int gcd_fast(int a, int b) {
    if (b == 0) {
        return a;
    }
    int c = a % b;
    return gcd_fast(b,c);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd_fast(a,b) << std::endl;
    return 0;
}
