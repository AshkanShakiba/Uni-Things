import java.util.Arrays;
import java.util.Scanner;

class E5Q4 {
    static Scanner scanner = new Scanner(System.in);
    static int[][] a = new int[1024][1024];

    static int function(int n, int m) {
        if (a[n][m] != -1) {
            return a[n][m];
        }
        if (n == 1 || m == 1 || m == 0) {
            return m;
        }
        int min, r;
        min = Integer.MAX_VALUE;
        for (int i = 1; i <= m; i++) {
            if (function(n - 1, i - 1) > function(n, m - i))
                r = function(n - 1, i - 1);
            else
                r = function(n, m - i);
            min = Math.min(r, min);
        }
        a[n][m] = min + 1;
        return a[n][m];
    }

    public static void main(String[] args) {
        int m, n;
        m = scanner.nextInt();
        n = scanner.nextInt();
        for (int[] ints : a)
            Arrays.fill(ints, -1);
        int answer = function(n, m);
        System.out.println(answer);
    }
}