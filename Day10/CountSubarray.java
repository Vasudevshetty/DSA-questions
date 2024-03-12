package Day10;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class CountSubarray {
    public static int countSubarray(final ArrayList<Integer> arr, int k) {
        int prefix = 0, count = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        for (int c : arr) {
            prefix += c;
            int remove = prefix - k;
            count += map.getOrDefault(remove, 0);
            map.put(prefix, map.getOrDefault(prefix, 0) + 1);
        }
        return count;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int ele = scan.nextInt();
            arr.add(ele);
        } 
        int k = scan.nextInt();
        System.out.println(countSubarray(arr, k));
        scan.close();
    }
}