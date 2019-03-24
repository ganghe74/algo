#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N, ans = 0;
    scanf("%d", &N);
    pair<int,int> lines[N];
    for (int i=0;i<N;++i) scanf("%d%d", &lines[i].first, &lines[i].second);
    sort(lines, lines+N);
    for (int i=0;i<N-1;++i) {
        if (lines[i+1].second <= lines[i].second) {
            lines[i+1] = lines[i];
            lines[i] = {0,0};

        }
        if (lines[i+1].first < lines[i].second) {
            lines[i+1].first = lines[i].first;
            lines[i] = {0,0};
        }
    }
    for (int i=0;i<N;++i) ans += lines[i].second - lines[i].first;
    printf("%d", ans);
}