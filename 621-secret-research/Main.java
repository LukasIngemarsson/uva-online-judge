import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nrOfLines = Integer.parseInt(in.nextLine());

        for (int i = 0; i < nrOfLines; i++) {
            String line = in.nextLine();

            if (line.equals("1") || line.equals("4") || line.equals("78")) {
                System.out.println("+");
            }
            else if (line.endsWith("35")) {
                System.out.println("-");
            }
            else if (line.startsWith("9") && line.endsWith("4")) {
                System.out.println("*");
            }
            else if (line.startsWith("190")) {
                System.out.println("?");
            }
        }
        in.close();
    }
}