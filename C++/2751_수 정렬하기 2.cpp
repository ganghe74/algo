#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int> A(N);
	for (int i=0;i<N;++i) {
		scanf("%d", &A[i]);
	}
	sort(A.begin(), A.end());
	for (int i=0;i<N;++i) {
		printf("%d\n", A[i]);
	}
}
