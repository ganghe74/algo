#include <iostream>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	int d[K+1][N+1] = {0};
	for (int i=0;i<=N;++i) d[1][i] = 1;
	
	for (int i=2;i<=K;++i) { // i = K, j = N
		for (int j=0;j<=N;++j) { 
			for (int k=0;k<=j;++k) {
				d[i][j] = (d[i][j] + d[i-1][k]) % 1000000000;
			}
			cout << "K N" << i << " " << j << " " << d[i][j] << endl;
		}
	}
	cout << d[K][N];
}
