package Day11;

import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Set;
import java.util.HashMap;
import java.util.LinkedHashSet;

public class ThreeSum {

    public static ArrayList<ArrayList<Integer>> getTripletsBetter(int[] arr) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            Set<Integer> set = new LinkedHashSet<>();
            for (int j = i + 1; j < arr.length; j++) {
                int third = -(arr[i] + arr[j]);

                if (set.contains(third)) {
                    ArrayList<Integer> triplet = new ArrayList<>();
                    triplet.add(arr[i]);
                    triplet.add(arr[j]);
                    triplet.add(third);
                    triplet.sort(Comparator.naturalOrder());
                    if (!list.contains(triplet))
                        list.add(triplet);
                }
                set.add(arr[j]);
            }
        }

        return list;
    }

    // brute force for 3sum
    public static ArrayList<HashMap<Integer, Integer>> getTriplets(int[] arr, int target) {
        ArrayList<HashMap<Integer, Integer>> triplets = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                for (int k = j + 1; k < arr.length; k++) {
                    int sum = arr[i] + arr[j] + arr[k];
                    if (sum == target) {
                        HashMap<Integer, Integer> map = new HashMap<>();
                        map.put(arr[i], i);
                        map.put(arr[j], j);
                        map.put(arr[k], k);
                        triplets.add(map);
                    }
                }
            }
        }

        return triplets;
    }

    public static ArrayList<List<Integer>> getTripletsOptimal(int[] arr) {
        ArrayList<List<Integer>> list = new ArrayList<>();

        int i = 0;
        while (i < arr.length) {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1, k = arr.length - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    list.add(List.of(arr[i], arr[j], arr[k]));
                    j++;
                    k--;
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
        return list;
    }

    public static void main(String[] args) {
        int arr[] = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
        System.out.println(getTriplets(arr, 0));
        System.out.println(getTripletsBetter(arr));
    }
}
