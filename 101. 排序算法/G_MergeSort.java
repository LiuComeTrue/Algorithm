import java.util.Scanner;

/**
 * 归并排序
 * @author ZC
 *
 */
public class G_MergeSort {

    //递归分治，将原序列分成两个序列排序，再将这两个有序序列合并一个有序序列
    public static void MergeSort(int[] a, int left, int right) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
    
    //合并两个有序序列
    public static void Merge(int[] a, int left, int mid, int right) {
        //暂存两个序列的数组
        int[] temp = new int[right - left + 1];
        int i = left, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            if (a[i] < a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
        while (i <= mid) 
            temp[k++] = a[i++];
        while (j <= right)
            temp[k++] = a[j++];
        
        //将合并后的有序序列赋给原数组
        int p = 0;
        while (p < k)
            a[left++] = temp[p++];       
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
            
            MergeSort(a, 0, a.length - 1);
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
