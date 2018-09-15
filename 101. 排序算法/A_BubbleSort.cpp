#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;
void swap(vector<int> &a, int i , int j);

//冒泡排序
void BubbleSort(vector<int> &a) {
    int length = a.size();
    for (int i = length - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1])
                swap(a, j , j + 1);
        }
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

        BubbleSort(a);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    /*vector<int> a;
    int i = 0;
    do{
        cin >> i;
        a.push_back(i);
    }while(getchar() !='\n');
    BubbleSort(a);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));*/
    return 0;
}
