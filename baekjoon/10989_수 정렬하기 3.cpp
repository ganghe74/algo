#include <cstdio>
using namespace std;
int main() {
	int N, temp;
	scanf("%d", &N);
	int cnt[10001] = {0};
	while (N--) {
		scanf("%d", &temp);
		cnt[temp] += 1;
	}
	for (int i=1;i<=10000;++i) {
		if (cnt[i] > 0) {
			while (cnt[i]--) {
				printf("%d\n", i);
			}
		}
	}
}