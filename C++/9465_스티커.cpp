#include <iostream>
#include <algorithm> 
using namespace std;
int solve(int N) {
	int d[N+1][3] = {0};
	for (int i=1;i<=2;++i) {
		for (int j=1;j<=N;++j) {
			cin >> d[j][i];
		}
	}
	for (int i=2; i<=N; ++i) {
		d[i][0] = max({d[i-1][1], d[i-1][2]});
		d[i][1] = max({d[i-1][0], d[i-1][2]}) + d[i][1];
		d[i][2] = max({d[i-1][0], d[i-1][1]}) + d[i][2];
	}
	return max({d[N][0], d[N][1], d[N][2]});
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
