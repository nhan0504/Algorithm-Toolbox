#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MaxPairwiseProduct(const vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();
    for (int first = 0; first < n; first++) {
        for (int second = first + 1; second < n; second++) {
            max_product = max(max_product, numbers[first] * numbers[second]);
        }
    }
    return max_product;
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

    cout << "maximum product of two numbers = " <<  MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
