#include <cstdio>
int main() {
	int N;
	scanf("%d", &N);
	for (int i=N;i>0;i--){
		for (int j=1;j<N+1;j++){
			if (j >= i) putchar('*');
			else putchar(' ');
		}
		putchar('\n');
	}
}
