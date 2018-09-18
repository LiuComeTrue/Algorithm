#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;
void swap(vector<int> &a, int i , int j);

//希尔排序
void ShellSort(vector<int> &a) {
    int length = a.size();
    int d = length / 2;
    while (d >= 1) {
        for (int i = d; i < length; i++) {
            int temp = a[i];
            int j = i - d;
            for (; j >= 0 && temp<a[j]; j -= d) {
                a[j+d] = a[j];
            }
            a[j+d] = temp;
        }
        d /= 2;
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

        ShellSort(a);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
