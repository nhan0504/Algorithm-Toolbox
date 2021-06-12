#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int64_t MaxPairwiseProduct(vector<int> list) {
    sort(list.begin(), list.end());
    int64_t product = *(list.end() - 1) * *(list.end() - 2);
    return product;
}

int main() {
    int n;
    cout << "Enter list size: ";
    cin >> n;
    vector<int> numbers(n);
    cout << "Enter all the element for list:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    cout << "maximum product of two numbers = " << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}