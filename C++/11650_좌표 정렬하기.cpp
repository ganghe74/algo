// using vector and pair
/*
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
*/




// struct Point and overloading operator
/*
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
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end());
	for (int i=0;i<N;++i) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
}
*/
