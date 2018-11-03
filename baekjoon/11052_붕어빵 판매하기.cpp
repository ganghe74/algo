#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int d[N+1] = {0};
	int P[N+1];
	for (int i=1;i<=N;++i) {
		cin >> P[i];
	}
	for (int i=1;i<=N;++i) {
		for (int j=1;j<=i;++j) {
			d[i] = (d[i]<d[i-j]+P[j])?d[i-j]+P[j]:d[i];
		}
	}
	cout << d[N];
}
