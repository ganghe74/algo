import java.util.Scanner;

public class Main {
	public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int result = 1;
        int[] answer = new int[10];
        for (int i=0;i<3;++i) result *= in.nextInt();
        String num = Integer.toString(result);
        for (int i=0;i<num.length();++i) {
            answer[(int)num.charAt(i)-'0'] += 1;
        }
        for (int i=0;i<10;++i) {
            System.out.println(answer[i]);
        }
	}
}