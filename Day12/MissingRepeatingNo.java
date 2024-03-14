package Day12;

import java.util.HashMap;

public class MissingRepeatingNo {
    public static void missrepeatbrute(int[] arr) {
        int repeating = -1, missing = -1;

        for (int i = 1; i <= arr.length; i++) {
            int count = 0;
            for (int ele : arr)
                if (ele == i)
                    count++;
            if (count == 2)
                repeating = i;
            if (count == 0)
                missing = i;

            if (repeating != -1 && missing != -1)
                break;
        }

        System.out.println(repeating + " " + missing);
    }

    public static void missRepeatBetter(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int repeating = -1, missing = -1;

        for (int ele : arr)
            map.put(ele, map.getOrDefault(ele, 0) + 1);

        for (int i = 1; i <= arr.length; i++) {
            if (!map.containsKey(i))
                missing = i;
            if (map.get(i) != null && map.get(i) == 2)
                repeating = i;
            if (repeating != -1 && missing != -1)
                break;
        }

        System.out.println(repeating + " " + missing);
    }

    public static void missingRepeatingMath(int[] arr) {
        int n = arr.length;
        int s = 0;
        int sn = (n * (n + 1)) / 2;
        int s2 = 0;
        int s2n = ((n) * (n + 1) * (2 * n + 1)) / 6;

        for (int ele : arr) {
            s += ele;
            s2 += (ele * ele);
        }

        int val1 = s - sn;
        int val2 = s2 - s2n;

        val2 /= val1;

        int repeating = (val1 + val2) / 2, missing = val2 - repeating;

        System.out.println(repeating + " " + missing);
    }

    public static void missingReaptingXor(int[] arr) {
        int xor = 0;
        for (int i = 0; i < arr.length; i++) {
            xor ^= arr[i];
            xor ^= (i + 1);
        }

        int bitNo = 0;
        while (true) {
            if ((xor & (1 << bitNo)) != 0)
                break;
            else
                bitNo++;
        }

        int zero = 0;
        int one = 0;

        for (int ele : arr) {
            if ((ele & (1 << bitNo)) != 0)
                one ^= ele;
            else
                zero ^= ele;
        }


        // number = (1<<bitNo) ==> xor & ~(xor - 1)
        for (int i = 1; i <= arr.length; i++) {
            if ((i & (1 << bitNo)) != 0)
                one ^= i;
            else
                zero ^= i;
        }

        int count = 0;
        for(int ele :arr){
            if (ele == one)
                count++;
        }
        int missing = count == 0? one : zero;
        int repeating  = missing == one? zero: one;
        
        System.out.println(repeating + " " + missing);
    }

    public static void main(String[] args) {
        int arr[] = { 4, 3, 6, 2, 1, 1 };
        missrepeatbrute(arr);
        missingRepeatingMath(arr);
        missRepeatBetter(arr);
        missingReaptingXor(arr);
    }
}
