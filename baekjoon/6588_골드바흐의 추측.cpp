#include <cstdio>
int main() {
	bool prime[1000001] = {1,1};
	for (int i=2;i*i<=1000000;++i) {
		if (prime[i] == 0) {
			for (int j=2;j*i<=1000000;++j) {
				prime[i*j] = 1;
			}
		}
	}
	int n;
	scanf("%d", &n);
	while (n != 0) {
		int i = 3;
		while (true) {
			if (!prime[i] && !prime[n-i]) {
				printf("%d = %d + %d\n", n, i, n-i);
				break;
			}
			i += 2;
		}
		scanf("%d", &n);
	}
}
