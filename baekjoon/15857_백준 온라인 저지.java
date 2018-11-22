import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String answer = "abbcdddc";
        int n = in.nextInt();
        System.out.println(answer.charAt(n-1));
    }
}