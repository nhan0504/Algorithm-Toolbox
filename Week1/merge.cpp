#include<iostream>
#include<vector>
using namespace std;

vector<int> Merge(vector<int> list1, vector<int> list2) {
    vector<int> MergeList;
    int n1 = list1.size();
    int n2 = list2.size();
    int limit;
    if (n1 <= n2) {
        limit = n1;
    }
    else {
        limit = n2;
    }
    for (int i = 0; i != limit; i++) {
        if (list1[i] < list2[i]) {
            MergeList.push_back(list1[i]);
            MergeList.push_back(list2[i]);
        }
        else {
            MergeList.push_back(list2[i]);
            MergeList.push_back(list1[i]);
        }
    }
    
    if (n1 < n2) {
        for (int j = n1; j != n2; j++) {
            MergeList.push_back(list2[j]);
        }
    }
    else if (n1 > n2) {
        for (int j = n2; j != n1; j++) {
            MergeList.push_back(list1[j]);
        }
    }   
    return MergeList;
}

int main() {
    int n;
    cout << "Enter list1 size: ";
    cin >> n;
    vector<int> list1(n);
    cout << "Enter all the element for list1:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> list1[i];
    }
    int m;
    cout << "Enter list2 size: ";
    cin >> m;
    vector<int> list2(m);
    cout << "Enter all the element for list2:" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> list2[i];
    }
    vector<int> MergedList = Merge(list1, list2);
    for (int i = 0; i != n + m; i++) {
        cout << MergedList[i] << "\t";
    }
}