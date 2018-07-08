#include<iostream>
using namespace std;
/*
题目：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转.
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
*/
/*
1.最简单的方法是直接遍历 searchInOrder
2.这里用二分查找的方法：
  1.非递减数组旋转后可以看成两个排序的数组，后面数组的第一个即为最小元素；
  2.取index1为前面数组的第一个下标，取index2为后面数组最后一个下标；
  3.取中间值indexMedium，若其值大于等于index1的值，则位于前面数组中，index1=indexMedium；
  4.若其值小于等于index2的值，则位于后面数组中，index2=indexMedium；
  5.循环，当index1位于前面数组最后一位，index2位于后面数组第一位，index2即为所求；
  6.例外：当index1=index2=indexMedium时，无法判断indexMedium的值位于前面还是后面，因此按顺序查找。
*/
int binarySearch(int a[], int len);
int searchInOrder(int a[], int index1, int index2);
int main() {
    int a[] = {3, 4, 5, 1, 2};
    //int a[] = {1, 0, 1, 1, 1};
    //int a[] = {1, 1, 1, 0, 1};
    //int a[] = {1, 1, 1, 1, 1};
    cout << a[binarySearch(a, 5)] << endl;
}

int binarySearch(int a[], int len) {
    if (len <= 0) {
        cout << "Invalid data";
        return -1;
    }
    int index1 = 0, index2 = len - 1;
    int indexMedium = index1;
    //a数组为原顺序递增
    if (a[index1] < a[index2])
        return index1;
    while (index1 <= index2) {
        if (index2 - index1 == 1) {
            indexMedium = index2;
            break;
        }
        indexMedium = (index1 + index2) / 2;
        //当前后中间三个位置数字相同，按顺序查找
        if (a[index1] == a[indexMedium] && a[index1] == a[index2]) {
            return searchInOrder(a, index1, index2);
        }

        if (a[indexMedium] >= a[index1]) {
            index1 = indexMedium;
        } else if (a[indexMedium] <= a[index2]) {
            index2 = indexMedium;
        }
    }
    return indexMedium;
}

int searchInOrder(int a[], int index1, int index2) {
    int minIndex = index1;
    for (int i = index1 + 1; i <= index2; i++) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
