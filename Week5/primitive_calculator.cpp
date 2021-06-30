#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimal_sequence(int n) {
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
    return NumSteps[n];
}

int main() {
    int n;
    cin >> n;
    //vector<int> sequence = optimal_sequence(n);
    //cout << sequence.size() - 1 << std::endl;
    /*for (size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
    }*/
    cout << optimal_sequence(n);
}
