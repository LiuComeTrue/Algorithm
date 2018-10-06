#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
#include<cmath>
using namespace std;
int getIndex(int num, int n);

//基数排序
void RadixSort(vector<int> &a) {
    int max = INT_MIN;
    int length = a.size();
    for (int i = 0; i < length; i++) { //找出数组中最大值
        if (max < a[i])
            max = a[i];
    }
    //最大的位数
    int n = 1;
    while (max / 10 != 0) {
        n++;
        max /= 10;
    }

    //每一个位值为0-9，定义10个桶
    vector<vector<int> > buckets(10);
    //按每一位的数填入对应的桶中
    int index = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < length; j++) {
            index = getIndex(a[j], i);
            buckets[index].push_back(a[j]);
        }
        //将一次排序的结果赋给原数组
        int p = 0;
        for (int j = 0; j < 10; j++) {
            if (buckets[j].size() != 0)
                for (int k = 0; k < buckets[j].size(); k++)
                    a[p++] = buckets[j][k];
        }
        for (int j = 0; j < 10; j++)
            buckets[j].clear();
    }
}

//返回数字某一位上的数字，如果没有高位返回0
int getIndex(int num, int n) {
    int index = 0;
    while (n--) {
        index = num % 10;
        num /= 10;
    }
    return index;
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

        RadixSort(a);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
