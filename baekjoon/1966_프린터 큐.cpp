#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        bool printed[N] = {0};
        int important[N] = {0};
        for (int i=0;i<N;++i) {
            scanf("%d", &important[i]);
        }
        int cnt = 0;
        int start = 0;
        while (!printed[M]) {
            int max = 0, maxidx = 0;
            for (int i=start;i<N;++i) {
                if (!printed[i]) {
                    if (max < important[i]) {
                        max = important[i];
                        maxidx = i;
                    }
                }
            }
            for (int i=0;i<start;++i) {
                if (!printed[i]) {
                    if (max < important[i]) {
                        max = important[i];
                        maxidx = i;
                    }
                }
            }
            printed[maxidx] = true;
            start = maxidx + 1;
            if (start >= N) start = 0;
            cnt += 1;
        }
        printf("%d\n", cnt);
    }
}