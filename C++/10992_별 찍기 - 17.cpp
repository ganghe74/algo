#include <iostream>

int main() {
	int N;
	scanf("%d", &N);
	for (int i=1;i<N;i++){
		printf(" ");
	}
	printf("*\n");
	for (int i=N-2;i>0;i--){
		for (int j=0;j<i;j++){
			printf(" ");
		}
		printf("*");
		for (int j=0;j<(N-i-1)*2-1;j++){
			printf(" ");
		}
		printf("*\n");
	}
	if (N!=1){
		for (int i=0;i<N*2-1;i++){
			printf("*");
		}
	}
}
