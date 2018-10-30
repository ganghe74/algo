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
    
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int i = n/2;
		while (true) {
			if (!prime[i] && !prime[n-i]) {
				printf("%d %d\n",i, n-i);
				break;
			}
			i--;
		}
	}
}