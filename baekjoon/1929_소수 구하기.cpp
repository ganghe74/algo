#include <cstdio>
int main() {
	bool prime[1000001] = {1,1};
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i=2;i*i<=N;++i) {
		if (prime[i] == 0) {
			for (int j=2;j*i<=N;++j) {
				prime[i*j] = 1;
			}
		}
	}
	for (int i=M;i<=N;++i) {
		if (prime[i] == 0) printf("%d\n", i);
	}
}
