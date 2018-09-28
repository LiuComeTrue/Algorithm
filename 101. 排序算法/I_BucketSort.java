import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * 桶排序
 * @author ZC
 *
 */
public class I_BucketSort {

    public static void BucketSort(int[] a) {
        if (a == null || a.length == 0)
            return;
        
        //桶的数量为10(假定数据为0-100)
        int bucketNums = 10;
        List<List<Integer>> buckets = new ArrayList<List<Integer>>();
        
        //每个桶都是一个链表
        for (int i = 0; i < bucketNums; i++) {
            buckets.add(new LinkedList<Integer>());
        }
        
        //根据映射函数将每个值加到对应的桶里
        for (int i = 0; i < a.length; i++) {
            buckets.get(f(a[i])).add(a[i]);
        }
        
        for (int i = 0; i < bucketNums; i++) {
            if (!buckets.get(i).isEmpty())
                Collections.sort(buckets.get(i)); // 对每个桶进行排序
        }
        
        //遍历每个桶，按顺序取出值赋给原数组
        int i = 0;
        for (List<Integer> bucket : buckets) {
            for (Integer x : bucket)
                a[i++] = x;
        }      
    }
    
    //映射函数
    public static int f(int i) {
        return i / 10;
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
            
            BucketSort(a);
            
            for (int i = 0; i < length; i++)
                System.out.print(a[i] + " ");
            System.out.println("");
        }
    }
}
