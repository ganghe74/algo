#include <iostream>
int main() {
	int N;
	scanf("%d", &N);
	for (int i=N-1;i>=0;i--) {
		for (int j=0;j<i;j++) {
			printf(" ");
		}
		for (int j=0;j<N-i;j++) {
			printf("* ");
		}
		printf("\n");
	}
}
