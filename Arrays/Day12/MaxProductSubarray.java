package Day12;

public class MaxProductSubarray {
    public static int maxProduct(int[] arr) {
        int maxProd = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            int prod = 1;
            for (int j = i; j < arr.length; j++) {
                prod *= arr[j];

                maxProd = Math.max(maxProd, prod);
            }
        }
        return maxProd;
    }

    public static int maxProdutSumOptimal(int[] arr) {
        int maxProd = Integer.MIN_VALUE;

        int preProd = 1, suProd = 1;
        for (int i = 0; i < arr.length; i++) {
            if (preProd == 0)
                preProd = 1;
            if (suProd == 0)
                suProd = 1;
            preProd *= arr[i];
            suProd *= arr[arr.length - 1 - i];

            maxProd = Math.max(maxProd, Math.max(suProd, preProd));
        }

        return maxProd;
    }

    public static void main(String[] args) {
        int arr[] = { 2, 3, -2, 4 };
        System.out.println(maxProduct(arr));
        System.out.println(maxProdutSumOptimal(arr));
    }
}