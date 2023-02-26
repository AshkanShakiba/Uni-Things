import java.util.ArrayList;
import java.util.Scanner;

public class E2Q2 {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int i, j = 1, countOfTrucks;
        ArrayList<Integer> trucks = new ArrayList<>();
        ArrayList<Integer> auxiliary = new ArrayList<>();

        while (input.hasNextInt()) {
            trucks.add(input.nextInt());
        }

        countOfTrucks = trucks.size();

        for (i = 0; i < countOfTrucks; i++) {
            auxiliary.add(trucks.get(i));
            while (auxiliary.size() > 0 && j < countOfTrucks && auxiliary.get(auxiliary.size() - 1).equals(j)) {
                auxiliary.remove(auxiliary.size() - 1);
                j++;
            }
        }

        if (j < countOfTrucks)
            System.out.println("no");
        else
            System.out.println("yes");
    }
}