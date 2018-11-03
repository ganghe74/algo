#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> a[1001];
int check[1001] = {0};
void dfs(int x) {
	check[x] = 1;
	printf("%d ", x);
	for (auto &n : a[x]) {
		if (check[n] == 0) {
			dfs(n);
		}
	}
}

void bfs(int x) {
	check[x] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		printf("%d ", x);
		for (auto &n : a[x]) {
			if (check[n] == 0) {
				check[n] = 1;
				q.push(n);
			}
		}
		q.pop();
		x = q.front();
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	while (M--) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		sort(a[x].begin(), a[x].end());
		sort(a[y].begin(), a[y].end());
	}
	
	dfs(V);
	memset(check, 0, sizeof(check));
	printf("\n");
	bfs(V);
}
