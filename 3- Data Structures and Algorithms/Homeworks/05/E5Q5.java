import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class E5Q5 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String name;
        int i, c, k, size, m = Integer.parseInt(scanner.nextLine());
        HashMap<String, Boolean> hashMap = new HashMap<>();
        for (i = 0; i < m; i++) {
            name = scanner.nextLine();
            hashMap.put(name, false);
        }
        int n = Integer.parseInt(scanner.nextLine());
        ArrayList<String> arrayList = new ArrayList<>();
        for (i = 0; i < n; i++) {
            name = scanner.nextLine();
            arrayList.add(name);
        }
        i = 0;
        c = 0;
        k = 0;
        size = arrayList.size();
        while (i < size) {
            boolean bool = hashMap.get(arrayList.get(i));
            hashMap.put(arrayList.get(i), true);
            if (!bool) k++;
            if (m == k) {
                c++;
                HashSet<String> keySet = new HashSet<>(hashMap.keySet());
                for (String key : keySet) hashMap.put(key, false);
                hashMap.put(arrayList.get(i), true);
                k = 1;
            }
            i++;
        }
        System.out.println(c);
    }
}
