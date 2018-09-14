#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> locate(N);
	for (int i=0;i<N;++i) {
		scanf("%d %d", &locate[i].first, &locate[i].second);
	}
	sort(locate.begin(), locate.end());
	for (auto &n : locate) {
		printf("%d %d\n", n.first, n.second);
	}
}
