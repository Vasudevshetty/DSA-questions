package Day1;

/*Implemented very basic way to extract elemetns from the given number, and count the number of digits in a number. */

public class BasicNumber {
    // time complexity of all these wil be around O(log10(n)) where n is the number given
    public int countDigits(int n) {
        return n > 0 ? countDigits(n /= 10) + 1 : 0;
    }

    public int countDigitsLog(int n) {
        return (int)(Math.log10((double)(n))+1);
    }

    public int[] digits(int n) {
        int[] digit = new int[countDigits(n)];
        int i = countDigits(n);
        while (n > 0) {
            digit[--i] = n % 10;
            n /= 10;
        }
        return digit;
    }

    // function to reverse a given number.
    public int reverseNumber(int n) {
        int revNo = 0;
        while (n > 0) {
            int lastDigit = n%10;
            revNo = revNo*10 + lastDigit;
            n/= 10;
        }
        return revNo;
    }

    // function to check whether the given number is a palindrome.
    public boolean isPalindrome(int n) {
        return n == reverseNumber(n);
    }

    public boolean isArmstrong(int n) {
        int sum = 0, number = n;
        while (n > 0) {
            int lastDigit = n % 10;
            sum += Math.pow(lastDigit, 3);
            n /= 10;
        }
        return number == sum;
    }
    // function to get divsors in O(n) time.
    public String divsors(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                sb.append(i).append(" ");
        }
        return sb.toString();
    }
    // function to get divsors in O(sqrt(n)) time
    public String divsorsOptmised(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                sb.append(i).append(" ");
                if (n / i != i)
                    sb.append(n / i).append(" ");
            }
        }
        return sb.toString();
    }
    // function to check whether the given no is a prime in O(sqrt(n)) time.
    public boolean isPrime(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
                if ((n / i) != i)
                    count++;
            }
        }
        return count == 2;
    }
    // function to give you the gcd of two numbers
    public int gcd(int a, int b) {
        if (a == b)
            return a;
        else
            return a > b ? gcd(a - b, b) : gcd(a, b - a);
    }
    // function to find gcd in beteter time.
    public int gcdOptimised(int a, int b) {
        if (a == b)
            return a;
        else
            return a > b ? gcd(a % b, b) : gcd(a, b % a);
    }
    public static void main(String args[]) {
        BasicNumber b = new BasicNumber();
        System.out.println(b.reverseNumber(101) + " " + b.isPalindrome(101));
        System.out.println(b.isArmstrong(371) + " " + b.isArmstrong(1634));
        System.out.println(b.divsors(36));
        System.out.println(b.divsorsOptmised(36));
        System.out.println(b.isPrime(5) + " " + b.isPrime(2));
        System.out.println(b.gcdOptimised(15,20));
    }
}

