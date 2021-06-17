#include <iostream>
using namespace std;

int gcd_fast(int a, int b) {
    if (b == 0) {
        return a;
    }
    int c = a % b;
    return gcd_fast(b, c);
}

long long lcm_fast(int a, int b) {
    long long gcd = gcd_fast(a, b);
    long long product = (long long)a * b;
    long long lcm = product/ gcd;
    return lcm;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << std::endl;
  return 0;
}
