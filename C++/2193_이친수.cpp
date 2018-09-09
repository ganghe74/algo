#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	long long d[N+1][2] = {0};
	d[1][0] = 1;
	d[1][1] = 1;
	for (int i=2;i<=N;++i) {
		d[i][0] = d[i-1][0] + d[i-1][1];
		d[i][1] = d[i-1][0];
	}
	cout << d[N][1];
}
