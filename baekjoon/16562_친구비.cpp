#include <bits/stdc++.h>
using namespace std;

int N, M, k;
int money[10001];
bool check[10001];
vector<int> friends[10001];

int searchCheapestFriend(int x) {
    int cheapest = money[x];
    check[x] = true;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        if (money[q.front()] < cheapest) cheapest = money[q.front()];
        for (int f : friends[q.front()]) {
            if (!check[f]) {
                check[f] = true;
                q.push(f);
            }
        }
        q.pop();
    }
    return cheapest;
}

int main() {
    scanf("%d %d %d", &N, &M, &k);
    for (int i=1;i<=N;++i) scanf("%d", &money[i]);
    while (M--) {
        int v, w;
        scanf("%d %d", &v, &w);
        friends[v].push_back(w);
        friends[w].push_back(v);
    }
    int answer = 0;
    for (int i=1;i<=N;++i) {
        if (!check[i]) {
            answer += searchCheapestFriend(i);
        }
    }
    if (answer > k) printf("Oh no");
    else printf("%d", answer);
}