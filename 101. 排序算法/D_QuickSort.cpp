#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;
void swap(vector<int> &a, int i , int j);

//快速排序
void QuickSort(vector<int> &a, int left, int right) {
    if (left >= right)
        return;
    int i = left, j = right;
    while (i < j) {
        while (a[j] >= a[left] && i < j)
            j--;
        while (a[i] <= a[left] && i < j)
            i++;
        swap(a, i, j);
    }
    swap(a, left, i);
    QuickSort(a, left, i - 1);
    QuickSort(a, i + 1, right);
}
//快速排序另一种写法
void QuickSort2(vector<int> &a, int left, int right) {
    if (left >= right)
        return;
    int i = left, j = right;
    int temp = a[left];
    while (i < j) {
        while (a[j] >= temp && i < j)
            j--;
        a[i] = a[j];
        while (a[i] <= temp && i < j)
            i++;
        a[j] = a[i];
    }
    a[i] = temp;
    QuickSort2(a, left, i - 1);
    QuickSort2(a, i + 1, right);
}

void swap(vector<int> &a, int i , int j) {
    int temp = 0;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int main() {

    string str;
    while(getline(cin, str)) {
        int i = 0;
        vector<int> a;

        stringstream input(str);
        while(input >> i) {
            a.push_back(i);
        }

        //QuickSort(a, 0, a.size() - 1);
        QuickSort2(a, 0, a.size() - 1);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
