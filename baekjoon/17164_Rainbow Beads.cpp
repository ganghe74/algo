#include <iostream>
using namespace std;
int main() {
	char d[3] = {'V', 'R', 'B'};
	char s[250005];
	int N, cnt = 0, ans = 0;
	scanf("%d", &N);
	scanf("%s", s);
	s[N] = 'a';
	for (int i=0;i<N;++i) {
		bool beautiful = true;
		char a[2];
		for (int j=0;j<3;++j) {
			a[0] = s[i];
			a[1] = s[i+1];
			if (a[0] == 'V') a[0] = d[j];
			if (a[1] == 'V') a[1] = d[j];
			if (a[0] == a[1]) beautiful = false;
		}
		cnt++;
		ans = max(ans, cnt);
		if (!beautiful) {
			cnt = 0;
		}
	}
	printf("%d", ans);
}