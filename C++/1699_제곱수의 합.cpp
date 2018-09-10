#include <iostream>
using namespace std;
int d[100001] = {0};
int solve(int n) {
	if (n <= 3) return n;
	if (d[n] > 0) return d[n];
	int result = 100000;
	for (int i=1;i*i<=n;++i) {
		if (result > solve(n-i*i) + 1) result = solve(n-i*i) + 1; 
	}
	d[n] = result;
	return result;
}
int main() {
	int N;
	cin >> N;
	cout << solve(N);
	return 0;
}
