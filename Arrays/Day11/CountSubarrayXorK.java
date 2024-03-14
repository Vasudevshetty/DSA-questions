package Day11;

import java.util.HashMap;

public class CountSubarrayXorK {
    // brute and better.
    public static int countXorBrute(int[] arr, int k) {
        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            int result = 0;
            for (int j = i; j < arr.length; j++) {
                result ^= arr[j];
                if (result == k)
                    count++;
            }
        }

        return count;
    }

    // optimal
    public static int countXorOptimal(int[] arr, int k) {
        int count = 0, preXor = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        for (int c : arr) {
            preXor ^= c;

            int remove = k ^ preXor;
            count += map.getOrDefault(remove, 0);

            map.put(preXor, map.getOrDefault(preXor, 0) + 1);
        }
        return count;
    }

    public static void main(String[] args) {
        int arr[] = { 4, 2, 2, 6, 4 };
        System.out.println(countXorBrute(arr, 6));
        System.out.println(countXorOptimal(arr, 6));
    }

}
