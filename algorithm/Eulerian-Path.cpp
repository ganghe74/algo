// https://www.acmicpc.net/problem/1199
#include <bits/stdc++.h>
using namespace std;

// Euler Circuit : start == end
// all vertices have even degrees.
// if directed graph, all indgree == outdegree
// any vertex can be start vertex.

// Euler Path : start != end
// two vertices have odd degree, and others has even degree.
// start vertex must indegree == outdegree - 1

// If it is not guaranteed that eulerian path or circuit exists,
// you need to valid input by checking degrees, or graph is connectd.

int n, a[1000][1000];

void Eulerian(int now) {
    for (int i=0;i<n;++i) {
        if (a[now][i]) {
            a[now][i]--;
            a[i][now]--;
            Eulerian(i);
        }
    }
    printf("%d ", now+1);
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j) scanf("%d", &a[i][j]);
    for (int i=0;i<n;++i) {
        int cnt = 0;
        for (int j=0;j<n;++j) cnt += a[i][j];
        if (cnt & 1) {
            puts("-1");
            return 0;
        }
    }
    Eulerian(0);
}