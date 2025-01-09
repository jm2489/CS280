import java.io.*;

// A -> I = E
// E -> P O P | P
// O -> + | - | * | / | **
// P -> I | L | UI | UL | (E)
// U -> + | - | !
// I -> C | CI
// C -> a | b | ... | y | z
// L -> D | DL
// D -> 0 | 1 | ... | 8 | 9

public class Main {
    private static String s;

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String line;

            while ((line = reader.readLine()) != null) {
                s = line;
                String t = s;

                if (A() && s.isEmpty()) {
                    System.out.println("The string \"" + t + "\" is in the language");
                } else {
                    System.out.println("The string \"" + t + "\" is not in the language");
                }
            }
        // Created a try/catch block to handle any IOExceptions that may occur or file not found.
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }

        System.out.println("\nLink to my GitHub repo for CS280: https://github.com/jm2489/CS280");
    }

    // A -> I = E
    private static boolean A() {
        if (I() && !s.isEmpty() && s.charAt(0) == '=') {
            s = s.substring(1);
            return E();
        }
        return false;
    }

    // E -> P | P O E
    private static boolean E() {
        if (P()) {
            while (!s.isEmpty() && O()) {
                if (!P()) return false;
            }
            return true;
        }
        return false;
    }

    // O -> + | - | * | / | **
    private static boolean O() {
        if (s.startsWith("**")) {
            s = s.substring(2);
            return true;
        } else if (!s.isEmpty() && (s.charAt(0) == '+' || s.charAt(0) == '-' || s.charAt(0) == '/' || s.charAt(0) == '*')) {
            s = s.substring(1);
            return true;
        }
        return false;
    }

    // P -> I | L | UI | UL | (E)
    private static boolean P() {
        if (I() || L()) {
            return true;
        } else if (U()) {
            return I() || L();
        } else if (!s.isEmpty() && s.charAt(0) == '(') {
            s = s.substring(1);
            if (E() && !s.isEmpty() && s.charAt(0) == ')') {
                s = s.substring(1);
                return true;
            }
            return false;
        }
        return false;
    }

    // U -> + | - | !
    private static boolean U() {
        if (!s.isEmpty() && (s.charAt(0) == '+' || s.charAt(0) == '-' || s.charAt(0) == '!')) {
            s = s.substring(1);
            return true;
        }
        return false;
    }

    // I -> C | CI
    private static boolean I() {
        if (C()) {
            while (C()) {}
            return true;
        }
        return false;
    }

    // C -> a | b | ... | y | z
    private static boolean C() {
        if (!s.isEmpty() && 'a' <= s.charAt(0) && s.charAt(0) <= 'z') {
            s = s.substring(1);
            return true;
        }
        return false;
    }

    // L -> D | DL
    private static boolean L() {
        if (D()) {
            while (D()) {}
            return true;
        }
        return false;
    }

    // D -> 0 | 1 | ... | 8 | 9
    private static boolean D() {
        if (!s.isEmpty() && '0' <= s.charAt(0) && s.charAt(0) <= '9') {
            s = s.substring(1);
            return true;
        }
        return false;
    }
}