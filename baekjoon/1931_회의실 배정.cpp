#include <cstdio>
#include <algorithm>
using namespace std;
struct conference {
    int begin;
    int end;
};
bool cmp(conference a, conference b) {
    if (a.end == b.end) return a.begin < b.begin;
    else return a.end < b.end;
}
int main() {
    int N;
    scanf("%d", &N);
    conference a[N];
    for (int i=0;i<N;++i) {
        scanf("%d %d", &a[i].begin, &a[i].end);
    }
    sort(a, a+N, cmp);
    int now = 0;
    int answer = 0;
    for (int i=0;i<N; i++) {
        if (now <= a[i].begin) {
            now = a[i].end;
            answer += 1;
        }
    }
    printf("%d", answer);
}