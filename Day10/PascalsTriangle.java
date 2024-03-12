package Day10;

import java.util.ArrayList;

public class PascalsTriangle {
    private static int getCombination(int n, int r) {
        int result = 1;
        for (int i = 0; i < r; i++) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

    public static int getPascalsValue(int row, int col) {
        return getCombination(row - 1, col - 1);
    }

    public static ArrayList<Integer> getPascalsRow(int row) {
        ArrayList<Integer> rowValues = new ArrayList<>();
        // this one is of O(n*r) time.
        // for (int i = 0; i < row; i++)
        // rowValues.add(getPascalsValue(row, i + 1));

        // int range = Math.ceilDiv(row,2);
        // for (int i = 0; i < range; i++) {
        // int value = getPascalsValue(row, i + 1);
        // rowValues[i] = rowValues[row - i - 1] = value;
        // }

        // most optimised O(n)
        int ans = 1;
        rowValues.add(ans);
        for (int col = 1; col <= row; col++) {
            ans *= (row - col);
            ans /= col;

            if (col != row)
                rowValues.add(ans);
        }
        return rowValues;
    }

    public static ArrayList<ArrayList<Integer>> getPascalsTriangle(int size) {
        ArrayList<ArrayList<Integer>> triangle = new ArrayList<>();
        for (int i = 1; i <= size; i++)
            triangle.add(getPascalsRow(i));
        return triangle;
    }

    public static void main(String args[]) {
        System.out.println(getCombination(7, 2));
        System.out.println(getPascalsTriangle(8));
    }
}
