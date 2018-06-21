#include <iostream>
int main() {
	int N, sum = 0;
	scanf("%d", &N);
	char nums[N+1];
	scanf("%s", nums);
	for (int i=0;i<N;i++){
		sum += nums[i] - '0';
	}
	printf("%d", sum);
}
