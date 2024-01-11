package Day2;

import java.util.Hashtable;
import java.util.Map;

public class Hashing {
    public int getCount(int array[], int num) {
        int count = 0;
        for (int a : array)
            if (a == num)
                count++;
        return count;
    }

    // say the array only contains upto 0-9
    public int[] getFreq(int array[]) {
        int[] freq = new int[10];
        for (int a : array)
            freq[a]++;
        return freq;
    }

    public int[] getFreqChar(char array[]) {
        int[] freq = new int[26];
        for (int i = 0; i < array.length; i++)
            freq[array[i] - 97]++;
        return freq;
    }

    // fucntion to use hashtable and fetch the highest and loweest.
    public void highLowFreq(int array[]) {
        Hashtable<Integer, Integer> ht = new Hashtable<>();
        for (int a : array) {
            ht.put(a, ht.getOrDefault(a, 0) + 1);
        }
        int low = Integer.MAX_VALUE, high = 0;
        int lowNo = 0, highNo = 0;
        for (Map.Entry<Integer, Integer> count : ht.entrySet()) {
            if (count.getValue() > high) {
                high = count.getValue();
                highNo = count.getKey();
            }
            if (count.getValue() < low) {
                low = count.getValue();
                lowNo = count.getKey();
            }
        }
        System.out.println(low + " " + lowNo + " " + high + " " + highNo);
    }

    public static void main(String[] args) {
        Hashing h = new Hashing();
        char array[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                't', 'u', 'v' };
        for (int a : h.getFreqChar(array)) {
            System.out.print(a + " ");
        }
        System.out.println();
        int arr[] = { 1, 1, 2, 1, 2, 3, 2, 1, 2, 3, 1, 2, 1, 4 };
        h.highLowFreq(arr);
    }
}