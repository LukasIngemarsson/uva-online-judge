import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    public static boolean doesOverlap(ArrayList<int[]> tasks) {
        boolean[] slots = new boolean[1000000];
        
        for (int[] task : tasks) {
            int start = task[0], end = task[1], rep = task[2];

            for (int i = 0; i <= 1000000 - end; i += rep) {
                for (int j = start + i; j < end + i; j++) {
                    if (slots[j]) return true;
                    slots[j] = true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Deque<String> lines = new ArrayDeque<>();
        
        while (in.hasNextLine()) {
            lines.add(in.nextLine());
        }

        while (true) {
            String[] firstLine = lines.poll().split(" ");
            int n = Integer.parseInt(firstLine[0]);
            int m = Integer.parseInt(firstLine[1]);

            if (n == 0 && m == 0) break;

            ArrayList<int[]> tasks = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                String[] line = lines.poll().split(" ");
                int a = Integer.parseInt(line[0]);
                int b = Integer.parseInt(line[1]);
                tasks.add(new int[]{a, b, 1000000});
            }

            for (int i = 0; i < m; i++) {
                String[] line = lines.poll().split(" ");
                int a = Integer.parseInt(line[0]);
                int b = Integer.parseInt(line[1]);
                int rep = Integer.parseInt(line[2]);
                tasks.add(new int[]{a, b, rep});
            }

            if (doesOverlap(tasks)) {
                System.out.println("CONFLICT");
            } 
            else {
                System.out.println("NO CONFLICT");
            }
        }
        in.close();
    }
}