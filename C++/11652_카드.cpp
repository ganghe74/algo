// Sort
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	long long answer;
	int N, cnt=1, ans_cnt=1;
	scanf("%d", &N);
	vector<long long> a(N);
	for (int i=0;i<N;++i) {
		scanf("%lld", &a[i]);
	}
	sort(a.begin(), a.end());
	answer = a[0];
	for (int i=1;i<N;++i) {
		if (a[i] != a[i-1]) {
			cnt = 0;
		}
		cnt += 1;
		if (cnt > ans_cnt) {
			answer = a[i-1];
			ans_cnt = cnt;
		}
	}
	printf("%lld", answer);
}



// Map
#include <cstdio>
#include <map>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	map<long long, int> a;
	while(N--) {
		long long x;
		scanf("%lld", &x);
		a[x] += 1;
	}
	long long answer;
	int cnt = 0;
	for (auto &p : a) {
		if (p.second > cnt) {
			cnt = p.second;
			answer = p.first;
		}
	}
	printf("%lld", answer);
}
