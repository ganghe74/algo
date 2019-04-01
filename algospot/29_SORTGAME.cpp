#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(const vector<int>& perm) {
    int n = perm.size();
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());
    queue<vector<int>> q;
    map<vector<int>, int> distance;
    distance[perm] = 0;
    q.push(perm);
    while (!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        if (here == sorted) return distance[here];
        int cost = distance[here];
        for (int i=0;i<n;++i) {
            for (int j=i+2;j<=n;++j) {
                reverse(here.begin()+i, here.begin()+j);
                if (distance.count(here) == 0) {
                    distance[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
    return -1;
}

map<vector<int>, int> toSort;

void precalc(int n) {
    vector<int> perm(n);
    for (int i=0;i<n;++i) perm[i] = i;
    queue<vector<int>> q;
    q.push(perm);
    toSort[perm] = 0;
    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        int cost = toSort[here];
        for (int i=0;i<n;++i) {
            for (int j=i+2;j<=n;++j) {
                reverse(here.begin()+i, here.begin()+j);
                if (toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
}

int solve(const vector<int>& perm) {
    int n = perm.size();
    vector<int> fixed(n);
    for (int i=0;i<n;++i) {
        int smaller = 0;
        for (int j=0;j<n;++j)
            if (perm[j] < perm[i])
                ++smaller;
            fixed[i] = smaller;
    }
    return toSort[fixed]; 
}

int main() {
    for (int i=1;i<=8;++i) precalc(i);
    int C, N, num;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        vector<int> a(N);
        for (int i=0;i<N;++i) scanf("%d", &a[i]);
        printf("%d\n", solve(a));
    }
}