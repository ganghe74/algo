#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int A[N];
	int d[N];
	for (int i=0;i<N;++i) cin >> A[i];
	for (int i=0;i<N;++i) {
		d[i] = A[i];
		for (int j=0;j<i;++j) {
			if (A[i] > A[j] && d[i] < d[j] + A[i]) d[i] = d[j] + A[i];
		}
	}
	int answer = d[0];
	for (int i=1;i<N;++i) {
		if (answer < d[i]) answer = d[i];
	}
	cout << answer;
}
