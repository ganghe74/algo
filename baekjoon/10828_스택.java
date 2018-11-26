import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Stack<Integer> stack = new Stack<>();
		int N = in.nextInt();
		while (N-- > 0) {
			String op = in.next();
			if (op.equals("push")) {
				int temp = in.nextInt();
				stack.push(temp);
			} else if (op.equals("pop")) {
				if (stack.isEmpty())
					System.out.println(-1);
				else
					System.out.println(stack.pop());
			} else if (op.equals("size")) {
				System.out.println(stack.size());
			} else if (op.equals("empty")) {
				if (stack.isEmpty())
					System.out.println(1);
				else
					System.out.println(0);
			} else if (op.equals("top")) {
				if (stack.isEmpty())
					System.out.println(-1);
				else
					System.out.println(stack.peek());
			}
		}
	}
}