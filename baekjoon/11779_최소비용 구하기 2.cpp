#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a[1001];
int d[1001], before[1001] = {-1};
int main()
{
    fill(d, d + 1001, 2e9);
    int N, M, u, v, w, s, e;
    scanf("%d%d", &N, &M);
    while (M--)
    {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back({v, w});
    }
    scanf("%d%d", &s, &e);
    priority_queue<pair<int, int>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        for (auto pi : a[now])
        {
            int next = pi.first;
            int nextDist = dist + pi.second;
            if (nextDist < d[next])
            {
                before[next] = now;
                d[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    printf("%d\n", d[e]);
    stack<int> st;
    while (before[e] != -1)
    {
        st.push(e);
        e = before[e];
    }
    printf("%d\n", st.size());
    while (!st.empty())
    {
        printf("%d ", st.top());
        st.pop();
    }
}