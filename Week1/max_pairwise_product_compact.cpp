#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int64_t MaxPairwiseProduct(vector<int> list) {
    sort(list.begin(), list.end());
    int64_t product = 0;
    for (int i = 0; i != list[list.size() - 1]; i++) {
        product += list[list.size() - 2];
    }
    return product;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    cout << MaxPairwiseProduct(numbers);
    return 0;
}