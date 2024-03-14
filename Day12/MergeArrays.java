package Day12;

import java.util.Arrays;

public class MergeArrays {
    public static void mergeArrays(int[] arr1, int[] arr2) {
        int[] merge = new int[arr1.length + arr2.length];

        int i = 0, j = 0, k = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j])
                merge[k++] = arr1[i++];
            else
                merge[k++] = arr2[j++];
        }

        while (i < arr1.length)
            merge[k++] = arr1[i++];

        while (j < arr2.length)
            merge[k++] = arr2[j++];

        for (int x = 0; x < merge.length; x++) {
            if (x < arr1.length)
                arr1[x] = merge[x];
            else
                arr2[x - arr1.length] = merge[x];
        }
    }

    public static void mergeOptimal(int[] arr1, int[] arr2) {
        for (int i = arr1.length - 1, j = 0; i >= 0 && j < arr2.length; i--, j++) {
            if (arr1[i] > arr2[j]) {
                int temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = temp;
            } else
                break;
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
    }

    private static void swapIfGreater(int[] arr1, int[] arr2, int ind1, int ind2) {
        if (arr1[ind1] > arr2[ind2]) {
            int temp = arr1[ind1];
            arr1[ind1] = arr2[ind2];
            arr2[ind2] = temp;
        }
    }

    public static void mergeOptimal2(int[] arr1, int[] arr2) {
        int gap = Math.ceilDiv((arr1.length + arr2.length), 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < (arr1.length + arr2.length)) {
                // in arr1, and arr2
                if (left < arr1.length && right >= arr1.length) {
                    swapIfGreater(arr1, arr2, left, right - arr1.length);
                } else if (left >= arr1.length) { // in arr2
                    swapIfGreater(arr2, arr2, left - arr1.length, right - arr1.length);
                } else { // in arr1
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++;
                right++;
            }
            if (gap == 1)
                break;
            gap = Math.ceilDiv(gap, 2);
        }
    }

    public static void main(String[] args) {
        int arr1[] = { 1, 3, 5, 7 };
        int arr2[] = { 0, 2, 6, 8, 9 };

        mergeOptimal2(arr1, arr2);

        for (int i : arr1)
            System.out.print(i + " ");
        System.out.println();
        for (int i : arr2)
            System.out.print(i + " ");
    }
}
