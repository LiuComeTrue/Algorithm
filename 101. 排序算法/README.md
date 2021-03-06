## 排序算法
### 1. 冒泡排序
冒泡排序就是在依次比较相邻两个数，将较大的数换到后面。比如a[0]和a[1]比较，将大数交换到a[1],接着再比较a[1]和a[2],一趟下来最大的数就出现再最后面了。接着再在剩下的数中取最大的数，多趟下来就排好序了。
### 2. 选择排序
选择排序就是选出数组中最小的数赋值给a[0],再选出第二小的数赋给a[1],依次类推。方法与冒泡排序一样，都是比较相邻两值，只不过不进行交换，而是记录索引值，找到最小的值的索引，再与a[0]进行交换值。
### 3. 插入排序
插入排序就是将数组中的数一个一个往有序序列中插入的过程。通常将数组第一个数当成一个有序序列，然后依次遍历后面的数，将一个数字插入前面有序序列的前面中间或者后面。
### 4. 快速排序
* 快速排序第一种做法就是选择一个基准数，将比基准数小的数移到左边，比基准数大的移到右边，然后对左边和右边也进行同样处理，递归后得到有序序列。做法就是
 * 设置左右指针，左指针指向序列的头部（即索引），右指针指向序列的尾部
 * 右指针先向前移动，直到找到比基准值小的值停下，然后左指针向后移动，直到找到比基准值大的值停下
 * 交换左右指针的值
 * 重复上述步骤知道左右指针相遇
 * 将基准值与左右指针的值交换（此时基准值左边的值都比它小，右边的值都比它大）
 * 对基准值左边序列递归调用上述操作
 * 对基准值右边序列递归调用上述操作
 * 注意：必须右指针先移动，因为通常选区第一个数为基准值，最后要将基准值与指针指向的值交换，只有右指针先动才能确保最后指针指向的数比基准值小。
* 快速排序另一种写法是挖坑填数法
 * 选择一个基准值，取出基准值temp
 * 同样设置左右指针，此时坑位就是左指针指向的temp值
 * 右指针先向前移动，直到找到比基准值小的值停下，将此时右指针的值填入坑位（即赋值给左指针处的值），右指针处成为新的坑位
 * 然后左指针向后移动，直到找到比基准值大的值停下，将此时左指针的值填入坑位（即赋值给右指针处的值），左指针处成为新的坑位
 * 直到左右指针相遇，将基准值temp赋给左右指针指向的坑位
 * 对基准值左边序列递归调用上述操作
 * 对基准值右边序列递归调用上述操作

 快速排序不是稳定的，它的时间复杂度最好是O(nlogn),当待排序列基本有序时，它时间复杂度最坏是O(n^2)。
### 5. 堆排序
堆排序就是建立一个大顶堆或小顶堆，堆就是一棵完全二叉树，根结点大于（小于）等于左右结点，可以用数组实现。大顶堆根为最大数，小顶堆根为最小数。将根节点取出，在剩下的数中重新构建堆，再依次取根结点直到最后一个数，取出的数就是排序好的。
* 用数组模仿堆的树结构，树从左到右从上到下将值存入数组，i为根结点，2*i+1则为左子结点，2*i+2则为右子结点
* 开始构造大顶堆，将整棵树当成只有根、左、右结点的数，根节点与左右子结点比较，子结点大就上移（根结点和子结点交换值），这样这棵树就是一个大顶堆了，然后将这棵树当成另一棵树的一个子结点，重复上述操作
* 从底向上构造大顶堆，如果上层不交换值，则保持原样，如果交换了值，要一直向下比较到叶子结点
* 从数组长度/2位置处开始向前遍历结点构造大顶堆，因为此处开始拥有子结点
* 当大顶堆构造完成，将根节点与数组最后一值交换（此时最大值在数组最后），再对长度减一的数组重新构造大顶堆，重复操作直到长度减到0，原数组就变为递增的有序序列了

堆排序是不稳定的排序，它的时间复杂度是O(nlogn)。
### 6. 希尔排序
希尔排序是对直接插入排序的改进。在排序序列是正序的情况下，直接插入排序的时间复杂度是O(n)，希尔排序就是利用这个特性，先将原序列分成多个子序列进行插入排序，待原序列基本有序时，再对整个序列进行插入排序。
* 希尔排序分割子序列是以增量进行分割的，即当增量为2时，原序列中每隔2个数字的值就是属于同个子序列的
* 通常将原序列长度/2作为增量，当第一次对子序列拍好序后，再将增量/2进行排序，直到增量为1时，就是对整个原序列进行排序

希尔排序是不稳定的排序，它的平均时间复杂度是O(nlogn)，当待排序列有序时最好是O(n^1.3),最坏是O(n^2)。
### 7. 归并排序
归并排序是采用分治法，将原序列分为两个有序序列，再将两个有序序列合并成一个有序序列的过程。采用递归的方式，划分两个序列到最后是两个单个值的序列，然后进行合并，实际的排序都是再合并中进行的。

合并两个有序序列是通过同时遍历两个序列，比较两个序列第一位的大小，将较小的值赋给第三个存储数组temp[],然后将这个值从原序列中删除，再次比较两个序列第一位的大小，直到其中一个序列清空，把另一个序列的值加到temp[]后。时间复杂度是O(n)。

归并排序是稳定的，它的时间复杂度是O(nlogn)。
### 8. 计数排序
计数排序的时间复杂度是O(n)，但前提条件是待排序序列是一定范围内的整数。做法就是把待排序序列的值当成数组的索引值，统计每个数字的次数，然后按顺序输出索引值（统计的次数多少就输出多少次）。当序列中有负数时也可以，只要把数字和索引值对应加上偏移量就行。比如-1对应索引值0，0对应索引值1，1对应索引值2...。

计数排序是稳定的，它的时间复杂度是O(n)。
### 9. 桶排序
桶排序是对计数排序的改进，它是将N个待排序数分成M个子序列（即桶），按某个映射函数将每个数放入对应的桶中，每个桶中的数都是排好序的，并且较小的桶的任意数都小于较大的桶的任意数，因此只要按顺序遍历桶，取出桶中的数就是一个有序序列。
* 将待排序序列分成M个桶，每个桶可用链表或数组表示
* 遍历待排序序列，按映射函数将值存入对应的桶中
* 对每个桶进行排序，可用任意排序算法
* 按顺序遍历桶取出桶中数据

按映射函数遍历待排序数组的时间复杂度是O(n)，对桶排序的时间复杂度是O(nlogn)，桶排序的时间复杂度是O(n)+O(nlogn)，当每个桶中只有一个数时，时间复杂度最好是O(n)。桶排序是稳定的。
### 10. 基数排序
基数排序是进行多关键字比较的排序，即将数字的个位、十位、百位……进行分组，对各个组进行排序的过程。先按个位排好序，再按十位排好序直到最高位。
* 首先找出待排序序列中最大数，算出它的位数，其它数高位补0
* 从个位开始，用10个数组代表10个桶，遍历待排序序列，个位数与桶索引一致则存入对应的桶中
* 按顺序遍历10个桶将个位拍好序的序列覆盖原数组
* 从十位重新开始，直到最高位
基数排序是稳定的，时间复杂度是O(d*n),d是最大的位数。
### 11. 总结
排序算法有冒泡排序、选择排序和插入排序三种简单排序，它们的时间复杂度都是O(n^2)，还有基于它们改进的快速排序、堆排序和希尔排序，它们的平均时间复杂度是O(nlogn)，前面都是比较排序，还有基于分支递归思想的归并排序和计数排序、桶排序和基数排序三种非比较算法，它们都是用空间换时间，减少比较次数来达到高效排序的效果。

| 排序算法 | 平均时间复杂度 | 最坏时间复杂度 | 空间复杂度 | 是否稳定 |
| :------: | :------: | :------: | :------: | :------: |
| 冒泡排序 | O(n^2) |  O(n^2) | O(1) | 是 |
| 选择排序 | O(n^2) |  O(n^2) | O(1) | 不是 |
| 直接插入排序 | O(n^2) |  O(n^2) | O(1) | 是 |
| 快速排序 | O(nlogn) |  O(n^2) | O(logn) | 不是 |
| 堆排序 | O(nlogn) |  O(nlogn) | O(1) | 不是 |
| 希尔排序 | O(nlogn) |  O(n^2) | O(1) | 不是 |
| 归并排序 | O(nlogn) |  O(nlogn) | O(n) | 是 |
| 基数排序 | O(n*d) |  O(n*d) | O(d) | 是 |

### 12. 参考
* [面试中的 10 大排序算法总结](http://www.codeceo.com/article/10-sort-algorithm-interview.html#0-tsina-1-10490-397232819ff9a47a7b7e80a40613cfe1)
* [排序算法时间复杂度、空间复杂度、稳定性比较](https://blog.csdn.net/yushiyi6453/article/details/76407640)
