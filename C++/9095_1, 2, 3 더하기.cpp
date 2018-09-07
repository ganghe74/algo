#include <iostream>
using namespace std;
int d[12] = {1,1,2};
int solve(int x) {
	if (d[x] > 0) return d[x];
	d[x] = solve(x-1) + solve(x-2) + solve(x-3);
	return d[x];
}
int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << solve(n) << endl;
	}
}
