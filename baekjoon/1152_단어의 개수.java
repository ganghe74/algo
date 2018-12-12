import java.util.Scanner;

public class Main {
	public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String s = in.nextLine().trim();
        if (s.equals("")) System.out.println(0);
        else System.out.println(s.split(" ").length);
	}
}