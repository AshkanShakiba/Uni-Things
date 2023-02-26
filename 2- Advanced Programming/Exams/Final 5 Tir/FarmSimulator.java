import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class InputReader {
    private int columnCount;
    private int rowCount;
    private final Scanner reader;
    private final ArrayList<String[]> creatures = new ArrayList<>();
    private final ArrayList<String[]> weapons = new ArrayList<>();
    private final ArrayList<String[]> commands = new ArrayList<>();

    InputReader() {
        reader = new Scanner(System.in);
        readInputs();
    }

    private void readInputs() {
        String[] parts = reader.nextLine().split(" ");
        rowCount = Integer.parseInt(parts[0]);
        columnCount = Integer.parseInt(parts[1]);
        int count = Integer.parseInt(reader.nextLine());
        readNextInputs(count, creatures);
        count = Integer.parseInt(reader.nextLine());
        readNextInputs(count, weapons);
        count = Integer.parseInt(reader.nextLine());
        readNextInputs(count, commands);
    }

    private void readNextInputs(int count, ArrayList<String[]> list) {
        for (int i = 0; i < count; i++) {
            String line = reader.nextLine();
            list.add(line.split(" "));
        }
    }

    public int getColumnCount() {
        return columnCount;
    }

    public int getRowCount() {
        return rowCount;
    }

    public ArrayList<String[]> getCreatures() {
        return creatures;
    }

    public ArrayList<String[]> getWeapons() {
        return weapons;
    }

    public ArrayList<String[]> getCommands() {
        return commands;
    }
}

class Location {
    private final int row;
    private final int column;

    public Location(int row, int column) {
        this.row = row;
        this.column = column;
    }

    public int getRow() {
        return row;
    }

    public int getColumn() {
        return column;
    }

    public boolean isValid(int rowCount, int columnCount) {
        if (row >= rowCount) return false;
        if (column >= columnCount) return false;
        return true;
    }

    public static Location stringToLocation(String location) {
        String[] parts = location.replace("(", "").replace(")", "").split(",");
        return new Location(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]));
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Location) {
            Location loc = (Location) obj;
            return getRow() == loc.getRow() && getColumn() == loc.getColumn();
        } else
            return false;
    }
}

public class FarmSimulator {
    public static void main(String[] args) {
//        try {
//            System.setIn(new FileInputStream("testCase1.txt"));
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
        InputReader reader = new InputReader();
        Farm farm = new Farm(reader);
        farm.setData();
        farm.simulate();
    }
}

class Farm {
    private int columnCount;
    private int rowCount;
    private ArrayList<Creature> creatures;
    private ArrayList<Weapon> weapons;
    private ArrayList<String[]> commands;
    private InputReader reader;

    public Farm(InputReader reader) {
        this.reader = reader;
    }

    public void setData() {
        columnCount = reader.getColumnCount();
        rowCount = reader.getRowCount();
        creatures = Creature.stringsToCreatures(rowCount, columnCount, reader.getCreatures());
        weapons = Weapon.stringsToWeapons(reader.getWeapons());
        commands = reader.getCommands();
    }

    public void simulate() {
        for (String[] command : commands) {
            if (command[0].equals("Calculate"))
                calculate();
            if (command[0].equals("Print"))
                print();
            if (command[0].equals("Shoot"))
                shoot(command);
        }
    }

    private void calculate() {
        int value = 0;
        for (Creature creature : creatures) {
            value += creature.getValue();
        }
        System.out.println(value);
    }

    private void print() {
        for (Creature creature : creatures) {
            System.out.println(creature.getId() + "(" + creature.getValue() + ")");
        }
    }

    private void shoot(String[] command) {
        Creature creature = null;
        String id = command[1];
        Location location = Location.stringToLocation(command[2]);
        for (Weapon weapon : weapons) {
            if (weapon.getId().equals(id)) {
                creature = weapon.shoot(location, creatures);
            }
        }
        if (creature != null)
            creatures.remove(creature);
    }
}

abstract class Creature {
    protected String id;
    protected int value;
    protected Location location;

    public String getId() {
        return id;
    }

    public int getValue() {
        return value;
    }

    public Location getLocation() {
        return location;
    }

    public static ArrayList<Creature> stringsToCreatures(int rowCount, int columnCount, ArrayList<String[]> strings) {
        ArrayList<Creature> creatures = new ArrayList<>();
        for (String[] creatureFields : strings) {
            Location location = Location.stringToLocation(creatureFields[2]);
            if (!location.isValid(rowCount, columnCount)) continue;
            if (creatureFields[0].equals("Apple"))
                creatures.add(new Apple(creatureFields));
            if (creatureFields[0].equals("Chicken"))
                creatures.add(new Chicken(creatureFields));
        }
        return creatures;
    }
}

class Apple extends Creature {
    private int age;
    private int fruits;

    public Apple(String[] creatureFields) {
        this.id = creatureFields[1];
        this.location = Location.stringToLocation(creatureFields[2]);
        this.age = Integer.parseInt(creatureFields[3]);
        this.fruits = Integer.parseInt(creatureFields[4]);
        this.value = 5 * age + fruits;
    }
}

class Chicken extends Creature {
    private int weight;
    private int eggs;

    public Chicken(String[] creatureFields) {
        this.id = creatureFields[1];
        this.location = Location.stringToLocation(creatureFields[2]);
        this.weight = Integer.parseInt(creatureFields[3]);
        this.eggs = Integer.parseInt(creatureFields[4]);
        this.value = weight + eggs;
    }
}

abstract class Weapon {
    protected String id;
    protected int bullets;

    public String getId() {
        return id;
    }

    public abstract Creature shoot(Location location, ArrayList<Creature> creatures);

    public static ArrayList<Weapon> stringsToWeapons(ArrayList<String[]> strings) {
        ArrayList<Weapon> weapons = new ArrayList<>();
        for (String[] weaponFields : strings) {
            if (weaponFields[0].equals("Gun"))
                weapons.add(new Gun(weaponFields));
            if (weaponFields[0].equals("Shell"))
                weapons.add(new Shell(weaponFields));
        }
        return weapons;
    }
}

class Gun extends Weapon {
    public Gun(String[] weaponFields) {
        this.id = weaponFields[1];
        this.bullets = Integer.parseInt(weaponFields[2]);
    }

    public Creature shoot(Location location, ArrayList<Creature> creatures) {
        for (Creature creature : creatures) {
            if (creature.getLocation().equals(location))
                if (creature instanceof Chicken)
                    return creature;
        }
        return null;
    }
}

class Shell extends Weapon {
    public Shell(String[] weaponFields) {
        this.id = weaponFields[1];
        this.bullets = Integer.parseInt(weaponFields[2]);
    }

    public Creature shoot(Location location, ArrayList<Creature> creatures) {
        for (Creature creature : creatures) {
            if (creature.getLocation().equals(location))
                return creature;
        }
        return null;
    }
}

// By Ashkan Shakiba