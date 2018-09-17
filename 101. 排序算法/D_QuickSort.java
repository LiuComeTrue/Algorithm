import java.util.Scanner;

/**
 * 快速排序
 * @author ZC
 *
 */
public class D_QuickSort {

    //交换小数和大数
    public static void QuickSort(int[] a, int left, int right) {
        if (left >= right)
            return;
        int i = left, j = right;
        while (i < j) {
            while (a[j] >= a[left] && i < j)
                j--;
            while (a[i] <= a[left] && i < j)
                i++;
            swap(a, i, j);
        }
        swap(a, left, i);
        QuickSort(a, left, i - 1);
        QuickSort(a, i + 1, right);
    }
    
    //挖坑填数
    public static void QuickSort2(int[] a, int left, int right) {
        if (left >= right)
            return;
        int i = left, j = right;
        int temp = a[left];
        while (i < j) {
            while (a[j] >= temp && i < j)
                j--;
            a[i] = a[j];
            while (a[i] <= temp && i < j)
                i++;
            a[j] = a[i];
        }
        a[i] = temp;
        QuickSort2(a, left, i - 1);
        QuickSort2(a, i + 1, right);
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
            
            //QuickSort(a, 0, a.length - 1);
            QuickSort2(a, 0, a.length - 1);
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
