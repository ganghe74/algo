#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int A[N];
	int d[N] = {0};
	for (int i=0;i<N;++i) cin >> A[i];
	for (int i=0;i<N;++i) {
		d[i] = 1;
		for (int j=0;j<i;++j) { 
			if (A[j] < A[i] && d[j]+1 > d[i]) d[i] = d[j]+1;
		}
	}
	int answer = d[0];
	for (int i=1;i<N;++i) {
		if (answer < d[i]) answer = d[i];
	}
	cout << answer;
}
