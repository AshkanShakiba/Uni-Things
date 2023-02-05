import java.util.Scanner;

class E3Q4 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] arg) {
        MinHeap minHeap = new MinHeap(5000000);

        scanner.nextInt();
        while (scanner.hasNextInt()) {
            minHeap.insert(scanner.nextInt());
        }

        while (minHeap.length > 0) {
            System.out.print(minHeap.removeMin() + " ");
        }
    }
}

class MinHeap {
    int length;
    int maxSize;
    int[] nodes;

    MinHeap(int maxSize) {
        this.length = 0;
        this.maxSize = maxSize;
        nodes = new int[maxSize + 1];
    }

    void insert(int value) {
        if (length >= maxSize) {
            return;
        }
        length++;

        nodes[length] = value;
        int nodeIndex = length;

        while (nodes[nodeIndex] < nodes[nodeIndex / 2]) {
            swap(nodeIndex, nodeIndex / 2);
            nodeIndex /= 2;
        }
    }

    void swap(int i, int j) {
        int tmp = nodes[j];
        nodes[j] = nodes[i];
        nodes[i] = tmp;
    }

    void minHeapify(int key) {
        if (length < key || key <= length / 2) {
            if (nodes[key] > nodes[2 * key] || nodes[key] > nodes[(2 * key) + 1]) {
                if (nodes[2 * key] < nodes[(2 * key) + 1]) {
                    swap(key, 2 * key);
                    minHeapify(2 * key);
                } else {
                    swap(key, (2 * key) + 1);
                    minHeapify((2 * key) + 1);
                }
            }
        }
    }

    int removeMin() {
        int min = nodes[1];
        nodes[1] = nodes[length];
        length--;
        minHeapify(1);
        return min;
    }
}