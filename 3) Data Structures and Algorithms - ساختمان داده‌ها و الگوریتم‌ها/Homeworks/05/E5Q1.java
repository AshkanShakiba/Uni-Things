import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class E5Q1 {
    static int m;

    public static void main(String[] args) {
        Reader reader = new Reader();
        int i, j, n = reader.nextInt(), r, p1, p2;
        int[][] edges = new int[n][2];
        for (i = 0; i < n - 1; i++) {
            edges[i][0] = reader.nextInt();
            edges[i][1] = reader.nextInt();
        }
        ArrayList<Integer>[] vector = new ArrayList[edges.length + 2];
        for (i = 0; i < vector.length; i++) {
            vector[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            vector[edge[1]].add(edge[0]);
            vector[edge[0]].add(edge[1]);
        }
        r = Integer.MIN_VALUE;
        for (i = 1; i < edges.length + 2; i++) {
            for (j = 0; j < vector[i].size(); j++) {
                m = 0;
                p1 = DFS(vector, vector[i].get(j), i);
                m = 0;
                p2 = DFS(vector, i, vector[i].get(j));
                if (p1 * p2 > r)
                    r = p1 * p2;
            }
        }
        System.out.println(r);
    }

    static int DFS(ArrayList<Integer>[] vector, int x, int y) {
        int m1 = 0;
        int m2 = 0;
        int t = 0;
        int i, tmp;
        for (i = 0; i < vector[x].size(); i++) {
            if (vector[x].get(i) != y) {
                tmp=DFS(vector, vector[x].get(i), x);
                if (tmp > t)
                    t = tmp;
                if (m1 >= m) {
                    if (m > m2)
                        m2 = m;
                } else {
                    m2 = m1;
                    m1 = m;
                }
            }
        }
        if (m1 + m2 > t)
            t = m1 + m2;
        m = m1 + 1;
        return t;
    }
}

//class Reader {
//    BufferedReader bufferedReader;
//    StringTokenizer stringTokenizer;
//
//    public Reader() {
//        bufferedReader = new BufferedReader(new InputStreamReader(System.in));
//    }
//
//    String next() {
//        while (stringTokenizer == null || !stringTokenizer.hasMoreElements()) {
//            try {
//                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//        }
//        return stringTokenizer.nextToken();
//    }
//
//    int nextInt() {
//        return Integer.parseInt(next());
//    }
//
//    long nextLong() {
//        return Long.parseLong(next());
//    }
//
//    double nextDouble() {
//        return Double.parseDouble(next());
//    }
//
//    String nextLine() {
//        String string = "";
//        try {
//            string = bufferedReader.readLine();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        return string;
//    }
//}