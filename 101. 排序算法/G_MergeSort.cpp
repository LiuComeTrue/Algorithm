#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;
void Merge(vector<int> &a, int left, int mid, int right);

//归并排序
void MergeSort(vector<int> &a, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

//合并两个有序序列
void Merge(vector<int> &a, int left, int mid, int right) {
    //暂存两个序列的数组
    int temp[right - left + 1];
    int i = left, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }
    //将合并后的有序序列赋给原数组
    for (int p = 0; p < k; p++) {
        a[left++] = temp[p];
    }
}

int main() {

    string str;
    while(getline(cin, str)) {
        int i = 0;
        vector<int> a;

        stringstream input(str);
        while(input >> i){
            a.push_back(i);
        }

        MergeSort(a, 0, a.size() - 1);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
