import java.util.*;

public class Main {
	public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        List list = new ArrayList<>();
        for (int i=0;i<N;++i) {
            list.add(in.nextInt());
        }
        Collections.sort(list);
        for (int i=0;i<N;++i) {
            System.out.println(list.get(i));
        }
	}
}