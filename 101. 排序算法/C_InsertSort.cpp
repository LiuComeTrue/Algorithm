#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;
int binarySearch(vector<int> a, int low, int high, int temp);

//直接插入排序
void InsertSort(vector<int> &a) {
    int length = a.size();
    int temp = 0;
    for (int i = 1; i < length; i++) {
        temp = a[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (temp > a[j])
                break;
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

//二分插入排序
void binarySort(vector<int> &a) {
    int length = a.size();
    int temp = 0;
    int k = 0;
    for (int i = 1; i < length; i++) {
        temp = a[i];
        if (temp < a[i - 1]) {
            k = binarySearch(a, 0, i - 1, temp);
            for (int j = i; j > k; j--)
                a[j] = a[j - 1];
            a[k] = temp;
        }
    }
}
//二分查找
int binarySearch(vector<int> a, int low, int high, int temp) {
    int mid = 0;
    while (low < high) {
        mid = (low + high) / 2;
        if (temp >= a[mid] && temp < a[mid + 1]) {
            return mid + 1;
        }
        else if (a[mid] > temp)
            high = mid;
        else
            low = mid;
    }
    return high;
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

        InsertSort(a);
        //binarySort(a);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
