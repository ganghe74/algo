#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n+1];
	for (int i=1;i<=n;++i) cin >> a[i];
	int d[n+1];
	d[1] = a[1];
	d[2] = a[1]+a[2];
	for (int i=3;i<=n;++i) {
		if (d[i]<d[i-2]+a[i]) d[i] = d[i-2]+a[i];
		if (d[i]<d[i-3]+a[i-1]+a[i]) d[i] = d[i-3]+a[i-1]+a[i];
	}
	cout << d[n];
}
