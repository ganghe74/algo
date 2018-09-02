#include <iostream>
int main() {
	int N;
	scanf("%d", &N);
	for (int i=1;i<=N;++i) {
		for (int j=0; j<N;j++) {
			if (j<N-i) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
	for (int i=N-1;i>0;--i) {
		for (int j=0; j<N;j++) {
			if (j<N-i) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}
