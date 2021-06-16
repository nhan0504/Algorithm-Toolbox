#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.push_back(dist);
    stops.insert(stops.begin(), 0);
    int numRefills = 0;
    int LastRefill = 0;
    int CurrentRefill = 0;
    while (stops[CurrentRefill] <= dist) {
        LastRefill = CurrentRefill;
        while (stops[CurrentRefill] <= dist && stops[CurrentRefill + 1] - stops[LastRefill] <= tank) {
            cout << "last refill dist = " << stops[LastRefill] << endl;
            cout << "current refill + 1 dist = " << stops[CurrentRefill + 1] << endl;
            CurrentRefill++;  
            if (CurrentRefill == stops.size() - 1) {
                break;
            }
        }
        if (CurrentRefill == stops.size() - 1) {
            break;
        }
        if (stops[CurrentRefill] <= dist) {
            numRefills++;
            cout << "num refills = " << numRefills << endl;
        }
        cout << "current refill = " << CurrentRefill << endl;
    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> stops.at(i);
    }
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;
}
