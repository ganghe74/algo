import java.io.IOException;

public class Main {
	public static void main(String[] args) {
		try {
            int len;
            byte[] buf = new byte[10];
			while ((len = System.in.read(buf, 0, 10)) != -1) {
                System.out.write(buf, 0, len);
                System.out.write('\n');
            }
		} catch (IOException e) {
		}
	}
}