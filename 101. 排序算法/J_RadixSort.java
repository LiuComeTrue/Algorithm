import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * 基数排序
 * @author ZC
 *
 */
public class J_RadixSort {

    public static void RadixSort(int[] a) {
        if (a == null || a.length == 0)
            return;
        
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < a.length; i++) { //找出数组中最大值
            if (max < a[i])
                max = a[i];
        }
        //数组中最大数的位数
        int n = 1;
        while (max / 10 != 0) {
            n++;
            max /= 10;
        }            

        //每一个位值为0-9，定义10个桶
        List<List<Integer>> b = new ArrayList<List<Integer>>(10);
        for (int i = 0; i < 10; i++)
            b.add(new LinkedList<Integer>());
        
        int index = 0;
        //按每一位的数填入对应的桶中
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < a.length; j++) {
                index = getIndex(a[j], i);
                b.get(index).add(a[j]);
            }
            
            //将一次排序的结果赋给原数组
            int p = 0;
            for (int j = 0; j < 10; j++) {
                if (!b.get(j).isEmpty())
                    for (int k = 0; k < b.get(j).size(); k++)
                        a[p++] = b.get(j).get(k);
            }
            
            for (int j = 0; j < 10; j++)
                b.get(j).clear();
        }
    }
    //返回数字某一位上的数字，如果没有高位返回0（n=1为个位，n=2为十位）
    public static int getIndex(int num, int n) {
        int index = 0;
        while (n != 0) {
            index = num % 10;
            num /= 10;
            n--;
        }
        return index;
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
            
            RadixSort(a);
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
