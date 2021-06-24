#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& list1, vector<int>& list2, vector<int>& MergedList) {
    if (list1.size() == 0 || list2.size() == 0) {
        if (list1.size() < list2.size()) {
            for (int i = list1.size(); i != list2.size(); i++) {
                MergedList.push_back(list2[i]);
            }
        }
        else if (list1.size() > list2.size()) {
            for (int i = list2.size(); i != list1.size(); i++) {
                MergedList.push_back(list1[i]);
            }
        }
        return;
    }

    if (list1[0] <= list2[0]) {
        MergedList.push_back(list1[0]);
        list1.erase(list1.begin());
    }
    else {
        MergedList.push_back(list2[0]);
        list2.erase(list2.begin());
    }
    Merge(list1, list2, MergedList);
}

int main() {
    int n;
    cout << "Enter list1 size: ";
    cin >> n;
    vector<int> list1(n);
    cout << "Enter all the element for list1:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> list1[i];
    }
    int m;
    cout << "Enter list2 size: ";
    cin >> m;
    vector<int> list2(m);
    cout << "Enter all the element for list2:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> list2[i];
    }
    vector<int> MergedList;
    Merge(list1, list2, MergedList);
    for (int i = 0; i != MergedList.size(); i++) {
        cout << MergedList[i] << "\t";
    }
    return 0;
}