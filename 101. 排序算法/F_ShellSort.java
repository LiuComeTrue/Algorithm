import java.util.Scanner;

public class F_ShellSort {

    public static void ShellSort(int[] a) {
        //将原数组每隔gap个数分为一个序列，总共分为gap个序列
        //分别对这多个序列进行直接插入排序（当gap为1时就是对整个数组进行直接插入排序）
        int gap = a.length / 2;
        while (gap > 0) {
            //从每个序列的第二位开始进行直接插入排序
            for (int i = gap; i < a.length; i++) {
                int temp = a[i]; //每个序列将要插入的值
                int j = i - gap;
                //记录temp值与前面的值比较，看是否需要将前面的值往后移然后让temp值插入
                while (j >= 0 && a[j] > temp) { 
                    a[j + gap] = a[j];
                    j -= gap;
                }
                a[j + gap] = temp; //跳出循环时多减了一次gap，这里加回去           
            }
            gap /= 2;
        }
    }

    public static void ShellSort2(int[] a) {
        
        int gap = a.length / 2;
        while (gap > 0) {
            for (int i = gap; i < a.length; i++) {
                for (int j = i - gap; j >= 0; j -= gap) {
                    if (a[j + gap] > a[j])
                        break;
                    swap(a, j, j + gap);
                }
            }
            gap /= 2;
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
            
            ShellSort(a);
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
