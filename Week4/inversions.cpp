#include <iostream>
#include <vector>

using namespace std;
int Merge(vector<int>& list1, vector<int>& list2, vector<int>& MergedList, int& inversion) {
    if (list1[0] <= list2[0]) {
        MergedList.push_back(list1[0]);
        list1.erase(list1.begin());
    }
    else if (list1[0] == list2[0]) {
        MergedList.push_back(list1[0]);
        list1.erase(list1.begin());
        MergedList.push_back(list2[0]);
        list2.erase(list2.begin());
    }
    else if (list1[0] > list2[0]) {
        inversion++;
        MergedList.push_back(list2[0]);
        list2.erase(list2.begin());
    }

    if (list1.size() == 0) {
        for (int i = list1.size(); i != list2.size(); i++) {
            MergedList.push_back(list2[i]);
        }
        return inversion;
    }
    if (list2.size() == 0) {
        for (int i = list2.size(); i != list1.size(); i++) {
            MergedList.push_back(list1[i]);
        }
        return inversion;
    }
    Merge(list1, list2, MergedList, inversion);
}

vector<int> MergeSort(vector<int>& list, int& inversion) {
    if (list.size() == 1) {
        return list;
    }

    int mid = list.size() / 2;
    vector<int> firsthalf(list.begin(), list.begin() + mid);
    vector<int> secondhalf(list.begin() + mid, list.end());

    vector<int> sortedfirsthalf = MergeSort(firsthalf, inversion);
    vector<int> sortedsecondhalf = MergeSort(secondhalf, inversion);

    vector<int> SortedList;
    Merge(sortedfirsthalf, sortedsecondhalf, SortedList, inversion);
    SortedList.push_back(inversion);
    return SortedList;
}

int get_number_of_inversions(vector<int>& list) {
    int inversion = 0;
    vector<int> sort;
    sort = MergeSort(list, inversion);
    return sort[sort.size() - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    } 
    cout << get_number_of_inversions(a);
}
