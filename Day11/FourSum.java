package Day11;

import java.util.*;

public class FourSum {
    public static Set<List<Integer>> sum4brute(int[] arr, int target) {
        int n = arr.length;
        Set<List<Integer>> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        int sum = arr[i] + arr[j] + arr[k] + arr[l];

                        if (sum == target) {
                            List<Integer> temp = Arrays.asList(arr[i], arr[j], arr[k], arr[l]);
                            Collections.sort(temp);
                            set.add(temp);
                        }
                    }
                }
            }
        }
        return set;
    }

    public static Set<List<Integer>> sum4better(int[] arr, int target) {
        Set<List<Integer>> set = new HashSet<>();
        Set<Integer> hash = new HashSet<>();

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                for (int k = j + 1; k < arr.length; k++) {
                    int quad = target - (arr[i] + arr[j] + arr[k]);

                    if (hash.contains(quad)) {
                        List<Integer> temp = Arrays.asList(arr[i], arr[j], arr[k], quad);
                        Collections.sort(temp);
                        set.add(temp);
                    }

                    hash.add(arr[k]);
                }
                hash.clear();
            }
        }
        return set;
    }

    public static Set<List<Integer>> sum4optimal(int[] arr, int target) {
        Arrays.sort(arr);
        Set<List<Integer>> set = new HashSet<>();

        for (int i = 0; i < arr.length; i++) {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < arr.length; j++) {
                if (j != i + 1 && arr[j] == arr[j - 1])
                    continue;
                int k = j + 1, l = arr.length - 1;

                while (k < l) {
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum < target)
                        k++;
                    else if (sum > target)
                        l--;
                    else {
                        List<Integer> temp = Arrays.asList(arr[i], arr[j], arr[k], arr[l]);
                        set.add(temp);
                        k++;
                        l--;

                        while (k < l && arr[k] == arr[k - 1])
                            k++;
                        while (k < l && arr[l] == arr[l + 1])
                            l--;
                    }
                }
            }
        }

        return set;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };
        System.out.println(sum4optimal(arr, 8));
        System.out.println(sum4better(arr, 8));
        System.out.println(sum4brute(arr, 8));
    }
}
