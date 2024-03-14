package Day10;

public class Pattern {
    public static void printPattern(int n) {
        int count = 0;
        for (int c = 1; c < n; c++) {
            if (c % 2 == 0)
                System.out.println("   *");
            // for (int i = 0; i <= (n % 4 != 0 ? (n / 4) : (n / 4) + 1); i++) {
            if (c == (4 * (c / 4)) + 1) {
                System.out.println("*");
                // break;
            }
            if (c == (3 * ((c / 4) + 1)) + count) {
                System.out.println("      *");
                // break;
                count++;
            }
            // }
        }
    }
    public static void main(String[] args) {
        printPattern(590);
    }
}