#include <iostream>
using namespace std;
int gcd(int x, int y) {
	int r;
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
int main() {
	int t;
	long long answer;
	cin >> t; 
	while (t--) {
		answer = 0;
		int n;
		cin >> n;
		int a[n];
		for (int i=0;i<n;++i) {
			cin >> a[i];
		}
		if (n==1) answer = 1;
		for (int i=0;i<n;++i) {
			for (int j=0;j<i;++j) {
				answer += gcd(a[i], a[j]);
			}
		}
		cout << answer << endl;
	}
}
