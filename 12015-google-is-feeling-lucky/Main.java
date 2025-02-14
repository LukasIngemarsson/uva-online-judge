import java.util.Scanner;

class Main {
    public static int getMaxVal(int[] arr) {
        int maxVal = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nrOfCases = Integer.parseInt(in.nextLine());

        for (int i = 0; i < nrOfCases; i++) {
            System.out.println("Case #" + (i + 1) + ":");

            String[] websites = new String[10];
            int[] relevance = new int[10];

            for (int j = 0; j < 10; j++) {
                String[] siteAndRel = in.nextLine().split(" ");
                websites[j] = siteAndRel[0];
                relevance[j] = Integer.parseInt(siteAndRel[1]);
            }
            int maxVal = getMaxVal(relevance);

            for (int j = 0; j < 10; j++) {
                if (relevance[j] == maxVal) {
                    System.out.println(websites[j]);
                }
            }
        }
        in.close();
    }
}
