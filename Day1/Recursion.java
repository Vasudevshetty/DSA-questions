package Day1;

class Recursion {
    // function to print the no from 1 to n.
    public void printnB(int n) {
        if (n > 0) {
            System.out.print(n + " ");
            printnB(n - 1);
        } else
            return;
    }

    // function to print the no from n to 1.
    public void printn(int n) {
        if (n > 0) {
            printn(n - 1);
            System.out.print(n + " ");
        } else
            return;
    }

    // fucntion to add sum of n numbers using recursion.
    public int sum(int n) {
        return n > 0 ? sum(n - 1) + n : 0;
    }
    
    // function to swap.
    public void swap(int[] array, int l, int r) {
        int temp = array[l];
        array[l] = array[r];
        array[r] = temp;
    }
    // function to reverse a array using recursion
    public void reverse(int[] array, int l, int r) {
        if (l >= r)
            return;
        swap(array, l, r);
        reverse(array, l + 1, r - 1);
    }

    // function reverse using a single pointer.
    public void reverseS(int[] array, int l) {
        if (l >= array.length / 2)
            return;
        swap(array, l, array.length - l - 1);
        reverseS(array, l + 1);
    }

    // function check whetehr teh given string is a palindrome or not.
    public boolean isPalindrome(String s, int l) {
        if (l >= s.length() / 2)
            return true;
        if (s.charAt(l) != s.charAt(s.length() - 1 - l))
            return false;
        return isPalindrome(s, l + 1);
    }

    // function to get nth fib no
    public int fib(int n) {
        return n <= 1 ? n : fib(n - 1) + fib(n - 2);
    }

    public static void main(String args[]) {
        Recursion r = new Recursion();
        r.printn(5);
        System.out.println();
        r.printnB(5);
        System.out.println();
        System.out.println(r.sum(5));
        int[] array = { 1, 2, 3, 4, 5 };
        r.reverse(array, 0, array.length - 1);
        for (int a : array)
            System.out.print(a + " ");
        System.out.println(r.isPalindrome("MAfM", 0));
        for(int i = 0; i < 10; i++) System.out.print(r.fib(i) + " ");
    }
}

