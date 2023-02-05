import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class E2Q4 {
    static ConsoleScanner input = new ConsoleScanner();

    public static void main(String[] args) {
        int n, i, j = 0, stackSize = 0;
        ArrayList<Integer> pushInputs = new ArrayList<>();
        ArrayList<Integer> popOutputs = new ArrayList<>();

        n = input.nextInt();
        for (i = 0; i < n; i++) {
            pushInputs.add(input.nextInt());
        }
        for (i = 0; i < n; i++) {
            popOutputs.add(input.nextInt());
        }

        for (i = 0; i < n; i++) {
            stackSize++;
            while (stackSize > 0 && pushInputs.get(stackSize - 1).equals(popOutputs.get(j))) {
                if (j >= n) break;
                pushInputs.remove(stackSize - 1);
                stackSize--;
                j++;
            }
        }

        if (j < n)
            System.out.println("false");
        else
            System.out.println("true");
    }
}

class ConsoleScanner {
    BufferedReader bufferedReader;
    StringTokenizer stringTokenizer;

    public ConsoleScanner() {
        bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (stringTokenizer == null || !stringTokenizer.hasMoreElements()) {
            try {
                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        String string = "";
        try {
            string = bufferedReader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return string;
    }
}