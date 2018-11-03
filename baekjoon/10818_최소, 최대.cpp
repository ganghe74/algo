#include <iostream>
int main() {
	int min, max, N;
	scanf("%d", &N);
	int nums[N];
	for (int i=0;i<N;i++) {
		scanf("%d", &nums[i]);
	}
	min = nums[0];
	max = nums[0];
	for (int j=1;j<N;j++) {
		if (min > nums[j]) min = nums[j];
		if (max < nums[j]) max = nums[j];
	}
	printf("%d %d", min, max);
}
