#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x, y;
	bool operator < (const Point &v) const {
		if (x < v.x) return true;
		else if (x == v.x) return y < v.y;
		else return false;
	}
};
int main() {
	int N;
	scanf("%d", &N);
	vector<Point> a(N);
	for (int i=0;i<N;++i) {
		scanf("%d %d", &a[i].y, &a[i].x);
	}
	sort(a.begin(), a.end());
	for (int i=0;i<N;++i) {
		printf("%d %d\n", a[i].y, a[i].x);
	}
}
