#include <iostream>
using namespace std;
int d[1001] = {0,1,2};
int solve(int x) {
	if (d[x] > 0) return d[x];
	d[x] = (solve(x-2) + solve(x-1)) % 10007;
	return d[x];
}
int main() {
	int n;
	cin >> n;
	cout << solve(n);
}
