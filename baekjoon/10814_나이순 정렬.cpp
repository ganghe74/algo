#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct member {
	char Name[101];
	int Age;
	bool operator < (const member &v) const {
		return Age < v.Age;
	};
};
int main() {
	int N;
	scanf("%d", &N);
	vector<member> a(N);
	for (int i=0;i<N;++i) {
		scanf("%d %s", &a[i].Age, &a[i].Name);
	}
	stable_sort(a.begin(), a.end());
	for (int i=0;i<N;++i) {
		printf("%d %s\n", a[i].Age, a[i].Name);
	}
}
