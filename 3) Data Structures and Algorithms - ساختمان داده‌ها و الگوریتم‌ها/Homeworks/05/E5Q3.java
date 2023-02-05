import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class E5Q3 {
    static Reader reader = new Reader();
    static ArrayList<int[]> arrayList;
    static boolean bool = true;

    public static void main(String[] args) {
        int n = reader.nextInt() + 1;
        int m = reader.nextInt();
        arrayList = new ArrayList<>();
        ArrayList<ArrayList<Integer>> arrayLists = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            arrayLists.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int num1 = reader.nextInt();
            int num2 = reader.nextInt();
            arrayLists.get(num1).add(num2);
            arrayLists.get(num2).add(num1);
        }

        int[] order = new int[n], bridge = new int[n];
        boolean[] booleans = new boolean[n];

        if (DFS(arrayLists, order, bridge, booleans, 1, 0))
            System.out.println("1");
        else
            System.out.println("-1");
    }

    static boolean DFS(ArrayList<ArrayList<Integer>> arrayLists, int[] order, int[] bridge, boolean[] booleans, int x, int y) {
        int tmp;
        int[] array;
        booleans[x] = true;
        order[x] = order[y] + 1;
        bridge[x] = order[x];

        for (int i = 0; i < arrayLists.get(x).size(); i++) {
            tmp = arrayLists.get(x).get(i);
            if (order[x] >= order[tmp] && tmp != y) {
                if (booleans[tmp] && order[tmp] < bridge[tmp])
                    bridge[x] = order[tmp];
                if (!booleans[tmp])
                    DFS(arrayLists, order, bridge, booleans, tmp, x);
                if (bridge[tmp] < bridge[x])
                    bridge[x] = bridge[tmp];
                array = new int[]{x, tmp};
                arrayList.add(array);
            }
        }

        if (order[x] == bridge[x])
            if (y != 0) bool = false;

        return bool;
    }
}

class Reader {
    BufferedReader bufferedReader;
    StringTokenizer stringTokenizer;

    public Reader() {
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