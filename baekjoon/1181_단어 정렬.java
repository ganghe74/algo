import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		ArrayList<String> words = new ArrayList<String>();
		int N;
		N = in.nextInt();
		for (int i=0;i<N;++i) {
			String word = in.next();
			if (words.contains(word)) continue;
			else words.add(word);
		}
		
		Collections.sort(words, new Comparator<String>() {
			public int compare(String a, String b) {
				if (a.length() == b.length()) return a.compareTo(b);
				return a.length() - b.length();
			}
		});

		for (String word:words) {
			System.out.println(word);
		}
	}
}