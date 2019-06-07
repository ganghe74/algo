#include <bits/stdc++.h>
using namespace std;
int a[300001], leftMax[300001], leftMin[300001], rightMax[300001], rightMin[300001];
int main() {
	int N;
	scanf("%d", &N);
	for (int i=1;i<=N;++i) scanf("%d", &a[i]);
	stack<pair<int,int>> st;
	for (int i=1;i<=N;++i) {
		while (!st.empty() && st.top().first <= a[i]) st.pop();
		leftMax[i] = st.empty() ? 0 : st.top().second;
		st.push({a[i], i});
	}
	st = stack<pair<int,int>>();
	for (int i=1;i<=N;++i) {
		while (!st.empty() && st.top().first >= a[i]) st.pop();
		leftMin[i] = st.empty() ? 0 : st.top().second;
		st.push({a[i], i});
	}
	st = stack<pair<int,int>>();
	for (int i=N;i>0;--i) {
		while (!st.empty() && st.top().first < a[i]) st.pop();
		rightMax[i] = st.empty() ? N+1 : st.top().second;
		st.push({a[i], i});
	}
	st = stack<pair<int,int>>();
	for (int i=N;i>0;--i) {
		while (!st.empty() && st.top().first > a[i]) st.pop();
		rightMin[i] = st.empty() ? N+1 : st.top().second;
		st.push({a[i], i});
	}
	long long ans = 0;
	for (int i=1;i<=N;++i) {
		long long cnt = 1LL * (rightMin[i] - i) * (i - leftMin[i]);
		ans -= a[i] * cnt;
		cnt = 1LL * (rightMax[i] - i) * (i - leftMax[i]);
		ans += a[i] * cnt;
	}
	printf("%lld\n", ans);
}