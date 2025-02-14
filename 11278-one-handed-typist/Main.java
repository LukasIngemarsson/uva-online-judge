import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        String qwertyLayout = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ";
        String shiftQwertyLayout = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
        String qwerty = qwertyLayout + shiftQwertyLayout;

        String dvorakLayout = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ";
        String shiftDvorakLayout = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
        String dvorak = dvorakLayout + shiftDvorakLayout;

        Map<Character, Character> qwertyToDvorak = new HashMap<>();
        for (int i = 0; i < qwerty.length(); i++) {
            qwertyToDvorak.put(qwerty.charAt(i), dvorak.charAt(i));
        }

        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            StringBuilder out = new StringBuilder();

            for (char ch : line.toCharArray()) {
                out.append(qwertyToDvorak.getOrDefault(ch, ch));
            }

            System.out.println(out);
        }
        scanner.close();
    }
}