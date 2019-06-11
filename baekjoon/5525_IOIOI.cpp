#include <iostream>
using namespace std;
int main() {
    char s[1000001];
    int N, M;
    scanf("%d%d", &N, &M);
    scanf("%s", s);
    int ans = 0, cnt = 0;
    int i = 0;
    while (i < M-2) {
        if (s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') {
            cnt++;
            i+=2;
        }
        else {
            if (cnt >= N) ans += cnt - N + 1;
            cnt = 0;
            i++;
        }
    }
    if (cnt >= N) ans += cnt - N + 1;
    printf("%d", ans);
}