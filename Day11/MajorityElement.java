package Day11;

import java.util.ArrayList;
import java.util.HashMap;

public class MajorityElement {
    public static ArrayList<Integer> majorityElement(int[] arr) {
        int target = Math.floorDiv(arr.length, 3);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if (list.isEmpty() || !list.contains(arr[i])) {
                int count = 0;
                for (int j = 0; j < arr.length; j++) {
                    if (arr[j] == arr[i])
                        count++;
                }
                if (count > target)
                    list.add(arr[i]);
                if (list.size() == 2)
                    break;
            }
        }
        return list;
    }

    public static ArrayList<Integer> majorityHash(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> list = new ArrayList<>();

        for (int ele : arr) {
            if (map.containsKey(ele))
                map.put(ele, map.get(ele) + 1);
            else
                map.put(ele, 1);

            if (map.get(ele) > Math.floorDiv(arr.length, 3))
                list.add(ele);
            if (list.size() == 2)
                break;
        }

        return list;
    }

    public static ArrayList<Integer> majority(int[] arr) {
        int count1 = 0, count2 = 0;
        int ele1 = Integer.MIN_VALUE, ele2 = Integer.MIN_VALUE;
        ArrayList<Integer> list = new ArrayList<>();
        
        for (int ele : arr) {
            if (count1 == 0 && ele2 != ele) {
                count1 = 1;
                ele1 = ele;
            } else if (count2 == 0 && ele1 != ele) {
                count2 = 1;
                ele2 = ele;
            } else if (ele1 == ele)
                count1++;
            else if (ele2 == ele)
                count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int ele : arr) {
            if (ele == ele1)
                count1++;
            if (ele == ele2)
                count2++;
        }
        
        int majority = Math.floorDiv(arr.length, 3);
        if (count1 > majority)
            list.add(ele1);
        if (count2 > majority)
            list.add(ele2);
        return list;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 1, 1, 3, 3, 2, 2, 2 };
        System.out.println(majorityElement(arr));
        System.out.println(majorityHash(arr));
        System.out.println(majority(arr));
    }
}