#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<sstream>
using namespace std;
void swap(vector<int> &a, int i , int j);

//堆排序
void HeapSort(vector<int> &a, int start, int end) {
    //start为根结点，2*start+1为左结点，2*start+2为右结点
    //i*=2为下一层的结点，在循环中判断下一个新start是否有子结点
    //将a当成一棵树，有根节点、左结点和右结点（左右结点是一棵排好序的二叉树）
    //将根与左右结点比较，交换后继续对子结点进行排序，不交换的子结点是已经排好序的
    int temp = a[start];
    for (int i = 2 * start + 1; i <= end; i *= 2) {
        if (i < end && a[i] < a[i + 1])
            i++;
        if (temp >= a[i]) //已经是大顶堆了，跳出循环
            break;
        a[start] = a[i]; //将子结点赋给上一根节点
        start = i; //将此结点更新为新的根节点
    }
    a[start] = temp; //当子结点一个一个上移，最后剩下的就是最初根节点下移的位置
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

        int length = a.size();
        //构建大顶堆
        //从底向上构建，从length/2位置出开始向前，因为其具有子结点
        for (int i = (length / 2); i >= 0; i--)
            HeapSort(a, i, length - 1);

        //将大顶堆根节点交换到数组尾，然后重新构建长度-1的大顶堆，
        //将第二大交换到倒数第二位置，类似于选择排序
        for (int i = length - 1; i > 0; i--) {
            swap(a, 0, i);
            HeapSort(a, 0, i - 1);
        }


        copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
