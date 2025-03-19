import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine().trim());
        reader.readLine();
        boolean firstIter = true;
        while (t > 0) {
            if (firstIter) {
                firstIter = false;
            } else {
                System.out.println();
            }
            ArrayList<String> expr = new ArrayList<>();
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    break;
                }
                expr.add(line);
            }
            String[] res = toPostfix(expr.toArray(new String[0]));
            for (String s : res) {
                System.out.print(s);
            }
            System.out.println();
            --t;
        }
        reader.close();
    }

    public static String[] toPostfix(String[] inputData) {
        HashSet<String> operators = new HashSet<>();
        operators.add("+");
        operators.add("-");
        operators.add("*");
        operators.add("/");

        Stack<String> opStack = new Stack<>();
        ArrayList<String> output = new ArrayList<>();

        for (String s : inputData) {
            if (s.matches("\\d")) {
                output.add(s);
            } else if (s.equals("(")) {
                opStack.push(s);
            } else if (s.equals(")")) {
                while (!opStack.isEmpty() && !opStack.peek().equals("(")) {
                    output.add(opStack.pop());
                }
                if (!opStack.isEmpty()) {
                    opStack.pop();
                }
            } else if (operators.contains(s)) {
                while (!opStack.isEmpty() && prio(s) <= prio(opStack.peek())) {
                    output.add(opStack.pop());
                }
                opStack.push(s);
            }
        }

        while (!opStack.isEmpty()) {
            output.add(opStack.pop());
        }

        return output.toArray(new String[0]);
    }

    public static int prio(String op) {
        switch (op) {
            case "+":
            case "-":
                return 1;
            case "*":
            case "/":
                return 2;
            default:
                return -1;
        }
    }
}
