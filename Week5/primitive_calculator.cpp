#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
    vector<int> sequence;
    vector<int> NumSteps(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int min = NumSteps[i - 1] + 1;
        if (i % 2 == 0) {
            int a = NumSteps[i / 2] + 1;
            if (a < min) {
                min = a;
            }
        }
        if (i % 3 == 0) {
            int b = NumSteps[i / 3] + 1;
            if (b < min) {
                min = b;
            }
        }
        NumSteps[i] = min;
    }
    sequence.push_back(n);
    while (n != 1) {
        if (NumSteps[n - 1] + 1 == NumSteps[n]) {
            sequence.push_back(n - 1);
            n = n - 1;
        }
        else if (n % 2 == 0 && NumSteps[n / 2] + 1 == NumSteps[n]) {
            sequence.push_back(n / 2);
            n = n / 2;
        }
        else if (n % 3 == 0 && NumSteps[n / 3] + 1 == NumSteps[n]) {
            sequence.push_back(n / 3);
            n = n / 3;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence = optimal_sequence(n);
    cout << sequence.size() - 1 << endl;
    for (size_t i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
}
