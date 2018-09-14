#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x, y;
	bool operator < (const Point &v) const {
		if (y < v.y) return true;
		else if (y == v.y) return x < v.x;
		else return false;
	}
};
int main() {
	int N;
	scanf("%d", &N);
	vector<Point> a(N);
	for (int i=0;i<N;++i) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end());
	for (int i=0;i<N;++i) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
}
