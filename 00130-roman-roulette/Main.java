import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.ArrayList;

class Main {
    private static int roulette(int n, int k, int i) {
        ArrayList<Integer> people = new ArrayList<Integer>();
        for (int j = 1; j <= n; ++j)
            people.add(j);

        int currIdx = i;
        while (people.size() > 1) {
            int killIdx = (currIdx + k - 1) % people.size();
            people.remove(killIdx);

            int burierIdx = (killIdx + k - 1) % people.size();
            int burier = people.get(burierIdx);
            people.remove(burierIdx);
            if (burierIdx < killIdx)
                --killIdx;
            people.add(killIdx, burier);

            currIdx = (killIdx + 1) % people.size();
        }

        return people.get(0);
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        while (true) {
            int n = io.getInt(), k = io.getInt();
            if (n == 0 && k == 0)
                break;

            for (int i = 0; i < n; ++i) {
                int survivor = roulette(n, k, i);
                if (survivor == 1) {
                    io.println(i + 1);
                    break;
                }
            }
        }

        io.close();
    }
    
    static class Kattio extends PrintWriter {
        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }
        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasMoreTokens() {
            return peekToken() != null;
        }

        public int getInt() {
            return Integer.parseInt(nextToken());
        }

        public double getDouble() { 
            return Double.parseDouble(nextToken());
        }

        public long getLong() {
            return Long.parseLong(nextToken());
        }

        public String getWord() {
            return nextToken();
        }

        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        private String peekToken() {
            if (token == null) {
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) {}
            }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }
    }
}
