#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;

//#define INT_MAX 0x7fffffff
//#define INT_MIN 0x80000000

//计数排序
void CountSort(vector<int> &a) {
    int min = INT_MAX;
    int max = INT_MIN;
    int length = a.size();
    for (int i = 0; i < length; i++) { //找出数组中最大最小值
        if (min > a[i])
            min = a[i];
        if (max < a[i])
            max = a[i];
    }

    //最小到最大之间的整数个数
    int blength = max - min + 1;
    int b[blength] = {0};
    //对应数组索引的值加1（最小值对应0，依次增加，比如-1对应索引0，0对应索引1，1对应索引2）
    for (int i = 0; i < length; i++) {
        b[a[i] - min]++;
    }

    for (int i = 0; i < blength; i++) {
        for (int j = 0; j < b[i]; j++)
            cout << i + min << " ";
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

        CountSort(a);

        cout << endl;
    }

    return 0;
}
