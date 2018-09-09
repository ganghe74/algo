#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i=0;i<N;++i) cin >> A[i];
	int up[N], down[N];
	
	for (int i=0;i<N;++i) {
		up[i] = 1;
		for (int j=0;j<i;++j) {
			if (A[j]<A[i] && up[j]+1>up[i]) up[i] = up[j]+1;
		}
	}
	for (int i=N-1;i>=0;--i) {
		down[i] = 1;
		for (int j=i;j<N;++j) {
			if (A[j]<A[i] && down[j]+1>down[i]) down[i] = down[j]+1;
		}
	}
	int answer=0;
	for (int i=0;i<N;++i) {
		if (answer < up[i]+down[i]-1) answer = up[i]+down[i]-1;
	}
	cout << answer;
}
