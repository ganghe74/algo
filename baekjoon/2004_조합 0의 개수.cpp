#include <iostream>
using namespace std;
int main() {
	int n, m;
	long long E, O;
	E = O = 0;
	cin >> n >> m;
	for (long long i=2;i<=n;i*=2) {
		E += n/i;
	}
	for (long long i=5;i<=n;i*=5) {
		O += n/i;
	}
	for (long long i=2;i<=m;i*=2) {
		E -= m/i;
	}
	for (long long i=5;i<=m;i*=5) {
		O -= m/i;
	}
	for (long long i=2;i<=n-m;i*=2) {
		E -= (n-m)/i;
	}
	for (long long i=5;i<=n-m;i*=5) {
		O -= (n-m)/i;
	}
	cout << (E<O?E:O);
}
