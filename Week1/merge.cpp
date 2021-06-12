#include<iostream>
#include<vector>
using namespace std;

vector<int> Merge(vector<int>& list1, vector<int>& list2) {
    vector<int> MergedList;
    if (list1.size() == 0 || list2.size() == 0) {
        if (list1.size() < list2.size()) {
            for (int i = list1.size(); i != list2.size(); i++) {
                MergedList.push_back(list2[i]);
                cout << list2[i];
            }
        }
        else if (list1.size() > list2.size()) {
            for (int i = list2.size(); i != list1.size(); i++) {
                MergedList.push_back(list1[i]);
                cout << list1[i];
            }
        }
        return MergedList;
    }
    int index1 = 0;
    for (int i = 1; i != list1.size(); i++) {
        if (list1[i] < list1[index1]) {
            index1 = i;
        }
    }
    int index2 = 0;
    for (int i = 1; i != list2.size(); i++) {
        if (list2[i] < list2[index1]) {
            index2 = i;
        }
    }
    if (list1[index1] < list2[index2]) {
        MergedList.push_back(list1[index1]);
        list1.erase(list1.begin() + index1);
        MergedList.push_back(list2[index2]);
        list2.erase(list2.begin() + index2);
    }
    else {
        MergedList.push_back(list2[index2]);
        list2.erase(list2.begin() + index2);
        MergedList.push_back(list1[index1]);
        list1.erase(list1.begin() + index1);
    }
    for (int i = 0; i != MergedList.size(); i++) {
        cout << MergedList[i] << "\t";
    }
    MergedList = Merge(list1, list2);
    
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
    vector<int> MergedList = Merge(list1, list2);
    return 0;
}