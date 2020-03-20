#include <bits/stdc++.h>
using namespace std;

int N, x, cnt[5000];
bitset<5000> s[5000];
vector<int> a, nums[5000];
vector<pair<int,int>> ab;

void trace(int i, int k) {
    if (!i) {
        printf("%d ", nums[ab[i].first].back());
        nums[ab[i].first].pop_back();
        return;
    }
    if (s[i-1][(k-ab[i].first+N)%N]) {
        printf("%d ", nums[ab[i].first].back());
        nums[ab[i].first].pop_back();
        trace(i-1, (k-ab[i].first+N)%N);
    }
    else {
        printf("%d ", nums[ab[i].second].back());
        nums[ab[i].second].pop_back();
        trace(i-1, (k-ab[i].second+N)%N);
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<2*N-1;++i) {
        scanf("%d", &x);
        nums[x%N].push_back(x);
        x %= N;
        if (++cnt[x] >= N) {
            for (int i=0;i<N;++i) {
                printf("%d ", nums[x].back());
                nums[x].pop_back();
            }
            return 0;
        }
        a.push_back(x);
    }

    x = a[0];
    cnt[x]--;
    s[0][x] = 1;
    ab.push_back({x, x});

    priority_queue<pair<int,int>> pq;
    for (int i=0;i<N;++i)
        if (cnt[i]) pq.push({cnt[i], i});

    for (int i=1;i<N;++i) {
        auto [cnt_ai, ai] = pq.top(); pq.pop();
        auto [cnt_bi, bi] = pq.top(); pq.pop();

        if (cnt_ai > 1) pq.push({cnt_ai-1, ai});
        if (cnt_bi > 1) pq.push({cnt_bi-1, bi});

        ab.push_back({ai, bi});
        for (int j=0;j<N;++j) {
            if (s[i-1][j]) {
                s[i][(j+ai)%N] = 1;
                s[i][(j+bi)%N] = 1;
            }
        }
    }

    trace(N-1, 0);
}
