import java.util.Scanner;

/**
 * 堆排序
 * @author ZC
 *
 */
public class E_HeapSort {

    /*
     * start为根结点，2*start+1为左结点，2*start+2为右结点
     * i*=2为下一层的结点，在循环中判断下一个新start是否有子结点
     * 将a当成一棵树，有根节点、左结点和右结点（左右结点是一棵排好序的二叉树）
     * 将根与左右结点比较，交换后继续对子结点进行排序，不交换的子结点是已经排好序的
     */
    public static void HeapSort(int[] a, int start, int end) {
        
        int temp = a[start];
        for (int i = 2 * start + 1; i <= end; i *= 2) {
            if (i < end && a[i] < a[i + 1])
                i++;
            if (temp >= a[i]) //已经是大顶堆了，跳出循环
                break;
            a[start] = a[i]; //将子结点赋给上一根节点
            start = i; //将此结点更新为新的根节点
        }
        a[start] = temp;  //当子结点一个一个上移，最后剩下的就是最初根节点下移的位置
    }
    
    public static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            String str = in.nextLine();
            String[] s = str.split(" ");
            int length = s.length;
            
            int[] a = new int[length];
            for (int i = 0; i < length; i++) 
                a[i] = Integer.parseInt(s[i]);
            
            int alength = a.length;
            //构建大顶堆
            //从底向上构建，从length/2位置出开始向前，因为其具有子结点
            for (int i = alength / 2; i >= 0; i--) {
                HeapSort(a, i, alength - 1);
            }
            //将大顶堆根节点交换到数组尾，然后重新构建长度-1的大顶堆，
            //将第二大交换到倒数第二位置，类似于选择排序
            for (int i = alength - 1; i > 0; i--) {
                swap(a, 0, i);
                HeapSort(a, 0, i - 1);
            }
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
