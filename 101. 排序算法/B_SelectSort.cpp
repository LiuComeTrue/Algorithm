#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;
void swap(vector<int> &a, int i , int j);

//选择排序
void SelectSort(vector<int> &a) {
    int length = a.size();
    int temp = 0;
    for (int i = 0; i < length; i++) {
        temp = i;
        for (int j = i + 1; j < length; j++) {
            if (a[temp] > a[j])
                temp = j;
        }
        if (temp != i)
            swap(a, i, temp);
    }
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
        while(input >> i){
            a.push_back(i);
        }

        SelectSort(a);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
