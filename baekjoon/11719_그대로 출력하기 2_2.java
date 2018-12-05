import java.io.IOException;

public class Main {
	public static void main(String[] args) {
		try {
            int x;
			while ((x = System.in.read()) != -1) {
                System.out.write(x);
            }
		} catch (IOException e) {
		}
	}
}