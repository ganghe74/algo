#include <iostream>
using namespace std;
int d[1000001] = {0};
int solve(int n) {
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = solve(n-1) + 1;
	if (n%2 == 0) {
		if (solve(n/2)+1 < d[n]) d[n] = solve(n/2) + 1;
	}
	if (n%3 == 0) {
		if (solve(n/3)+1 < d[n]) d[n] = solve(n/3) + 1;
	}
	return d[n];
}
int main() {
	int N;
	cin >> N;
	cout << solve(N);
}
