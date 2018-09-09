#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0;i<n;++i) cin >> a[i];
	int d[n];
	d[0] = a[0]; 
	for (int i=1;i<n;++i) {
		d[i] = a[i];
		if (d[i] < d[i-1] + a[i]) d[i] = d[i-1]+a[i];
	}
	int answer = d[0];
	for (int i=1;i<n;++i) {
		if (d[i] > answer) answer = d[i];
	}
	cout << answer;
}
