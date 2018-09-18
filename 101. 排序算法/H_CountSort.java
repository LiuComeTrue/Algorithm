import java.util.Scanner;

/**
 * 计数排序
 * @author ZC
 *
 */
public class H_CountSort {

    public static void CountSort(int[] a) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < a.length; i++) { //找出数组中最大最小值
            if (min > a[i])
                min = a[i];
            if (max < a[i])
                max = a[i];
        }
        //最小到最大之间的整数个数
        int length = max - min + 1;
        int[] b = new int[length];
        
        //对应数组索引的值加1（最小值对应0，依次增加，比如最小值为-1，-1对应索引0，0对应索引1，1对应索引2...）
        for (int i = 0; i < a.length; i++) {
            b[a[i] - min]++;
        }
        //对应索引的值为多少就输出多少次索引值
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < b[i]; j++) {
                System.out.print(i + min);
                System.out.print(" ");
            }            
        }
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
            
            CountSort(a);

            System.out.println("");
        }
    }
}
