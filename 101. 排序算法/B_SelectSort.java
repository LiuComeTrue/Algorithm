import java.util.Scanner;

/**
 * 选择排序
 * @author ZC
 *
 */
public class B_SelectSort {

    public static void SelectSort(int[] a) {
        int length = a.length;
        int temp = 0;
        for (int i = 0; i < length; i++) {
            temp = i;
            for (int j = i + 1; j < length; j++) {
                if (a[temp] > a[j])
                    temp = j;
            }
            if (temp != i)
                swap(a, i, temp);
        }
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
            
            SelectSort(a);
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
