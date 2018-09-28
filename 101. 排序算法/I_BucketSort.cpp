#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
#include<cmath>
using namespace std;
int f(int x);

//桶排序
void BucketSort(vector<int> &a) {
    int min = INT_MAX;
    int max = INT_MIN;
    int length = a.size();
    for (int i = 0; i < length; i++) { //找出数组中最大最小值
        if (min > a[i])
            min = a[i];
        if (max < a[i])
            max = a[i];
    }

    //假定每个桶最多存10个数
    int num = 10;
    //桶的数量
    int bucketNums = ceil((max - min) / num );
    if (bucketNums == 0)
        bucketNums = 1;

    vector<vector<int> > b(bucketNums);
    for (int i = 0; i < length; i++) {
        b[f(a[i])].push_back(a[i]);
    }

    //遍历每个桶
    for (int i = 0; i < bucketNums; i++) {
        //对每个桶进行插入排序
        if (b[i].size() > 1) {
            for (int j = 1; j < b[i].size(); j++) {
                int temp = b[i][j];
                int k = j - 1;
                for (; k >= 0; k--) {
                    if (temp >= b[i][k])
                        break;
                    b[i][k + 1] = b[i][k];
                }
                b[i][k + 1] = temp;
            }
        }
    }

    //遍历每个桶，按顺序取出值赋给原数组
    int k = 0;
    for (int i = 0; i < bucketNums; i++) {
        if (b[i].size() != 0)
            for (int j = 0; j < b[i].size(); j++) {
                a[k++] = b[i][j];
            }
    }
}

//映射函数
int f(int x) {
    return x / 10;
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

        BucketSort(a);

        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
