import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cap = 10000;
        int[] maxHeights = new int[cap];

        while (in.hasNextLine()) {
            String[] line = in.nextLine().split("\\s+");
            int R = Integer.parseInt(line[0]);
            int H = Integer.parseInt(line[1]);
            int L = Integer.parseInt(line[2]);

            for (int x = R; x <= L; x++) {
                if (H > maxHeights[x]) maxHeights[x] = H;
            }
        }
        int prev_y = 0;
        boolean firstChange = true;

        for (int x = 0; x < cap; x++) {
            if (maxHeights[x] != prev_y) {
                if (!firstChange) {
                    System.out.print(" ");
                } 
                else {
                    firstChange = false;
                }
                if (maxHeights[x] > prev_y) {
                    System.out.print(x + " " + maxHeights[x]);
                }
                else if (maxHeights[x] < prev_y) {
                    System.out.print(x - 1 + " " + maxHeights[x]);
                }
                prev_y = maxHeights[x];
            } 
        }
        if (maxHeights[cap-1] != 0) {
            System.out.println(" " + (cap - 1) + " " + 0);
        }
        in.close();
    }
}