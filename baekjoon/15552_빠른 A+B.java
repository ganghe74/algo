import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        br.lines().limit(n).forEach(x -> {
            String[] temp = x.split(" ");
            int a = Integer.parseInt(temp[0]);
            int b = Integer.parseInt(temp[1]);
            try {
                bw.write((a+b) + "\n");
            } catch (IOException e) {
            }
        });

        bw.close();
	}
}