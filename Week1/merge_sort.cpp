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

vector<int> MergeSort(vector<int>& list) {
    if (list.size() == 1) {
        return list;
    }
    int mid = list.size() / 2;
    vector<int> firsthalf (list.begin(),list.begin() + mid);
    vector<int> secondhalf(list.begin() + mid, list.end());
    vector<int> sortedfirsthalf = MergeSort(firsthalf);
    vector<int> sortedsecondhalf = MergeSort(secondhalf);
    vector<int> SortedList;
    Merge(sortedfirsthalf, sortedsecondhalf, SortedList);
    return SortedList;
}

int main() {
    int n;
    cout << "enter list size: ";
    cin >> n;
    cout << "enter all the element for list:" << endl;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    numbers = MergeSort(numbers);
    for (int i = 0; i != n; i++) {
        cout << "number[" << i << "] = " << numbers[i] << "\t";
    }
    return 0;
} 