#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int wine[n+1] = {0};
	int d[n+1] = {0};
	for (int i=1;i<=n;++i) cin>>wine[i];
	d[1] = wine[1];
	d[2] = wine[1] + wine[2];
	for (int i=3;i<=n;++i) {
		d[i] = d[i-1];
		if (d[i] < d[i-2] + wine[i]) {
			d[i] = d[i-2] + wine[i];
		}
		if (d[i] < d[i-3] + wine[i] + wine[i-1]) {
			d[i] = d[i-3] + wine[i] + wine[i-1];
		}
	}
	cout << d[n];
}
