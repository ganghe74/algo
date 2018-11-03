#include <iostream>
using namespace std; 
int main() {
	int N;
	cin >> N;
	int d[N+1][10] = {0};
	for (int i=0;i<10;++i) d[1][i] = 1;
	for (int i=2;i<=N;++i) {
		for (int j=0;j<10;++j) {
			if (j<9) d[i][j] = (d[i][j] + d[i-1][j+1]) % 1000000000;
			if (j>0) d[i][j] = (d[i][j] + d[i-1][j-1]) % 1000000000;
		}
	}
	int answer = 0;
	for (int i=1;i<10;++i) answer = (answer + d[N][i]) % 1000000000;  
	cout << answer;
}
