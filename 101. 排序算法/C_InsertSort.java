import java.util.Scanner;

/**
 * 插入排序
 * @author ZC
 *
 */
public class C_InsertSort {

    //直接插入排序
    public static void InsertSort(int[] a) {
        int length = a.length;
        int temp = 0;
        for (int i = 1; i < length; i++) {
            temp = a[i];
            int j = i - 1;
            for (; j >= 0; j--) {
                if (temp > a[j])
                    break;
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
    
    //二分插入排序
    public static void binarySort(int[] a) {
        int length = a.length;
        int temp = 0;
        int k = 0;
        for (int i = 1; i < length; i++) {
            temp = a[i];
            if (temp < a[i - 1]) {
                k = binarySearch(a, 0, i - 1, temp);
                for (int j = i; j > k; j--)
                    a[j] = a[j - 1];
                a[k] = temp;
            }
        }
    }
    
    //二分查找
    public static int binarySearch(int[] a, int low, int high, int temp) {
        int mid = 0;
        while (low < high) {
            mid = (low + high) / 2;
            if (temp >= a[mid] && temp < a[mid + 1]) {
                return mid + 1;
            }
            else if (a[mid] > temp)
                high = mid;
            else
                low = mid;
        }
        return high;
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
            
            InsertSort(a);
            //binarySort(a);
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
