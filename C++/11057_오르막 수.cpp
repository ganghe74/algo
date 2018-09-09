#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int d[N+1][10] = {{0}};
	for (int i=0;i<10;++i) d[1][i] = 1;
	for (int i=2;i<=N;++i) {
		for (int j=0;j<10;++j) {
			for (int l=0;l<=j;++l) d[i][j] +=d[i-1][l];
			d[i][j] %= 10007;
		}
	}
	int answer=0;
	for (int i=0;i<10;++i) answer = (answer + d[N][i]) % 10007;
	cout << answer;
}
