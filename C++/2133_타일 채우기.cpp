#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int d[N+1] = {1};
	for (int i=2;i<=N;i+=2) {
		d[i] = d[i-2];
		for (int j=0;j<i;j+=2) {
			d[i] += d[j]*2;
		}
	}
	cout << d[N];
}
