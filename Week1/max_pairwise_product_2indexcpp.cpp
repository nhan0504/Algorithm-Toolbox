#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int64_t MaxPairwiseProduct(vector<int> list) {
    int i, j;
    if (list[0] > list[1]) {
        i = 0;
        j = 1;
    }
    else {
        i = 1;
        j = 0;
    }
    for (int k = 2; k != list.size(); k++) {
        if (list[k] > list[i] && list[k] > list[j]) {
            j = i;
            i = k;
        }
        else if (list[k] > list[i] && list[k] <= list[j]) {
            i = k;
        }
        else if (list[k] <= list[i] && list[k] > list[j]) {
            j = k;
        }
    }
    int64_t product = 0;
    for (int n = 0; n != list[i]; n++) {
        product += list[j];
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