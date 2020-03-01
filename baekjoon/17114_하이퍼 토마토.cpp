#include <bits/stdc++.h>
using namespace std;

int dims[11], delta[] = {1,-1};

int main() {
    for (int i=0;i<11;++i) scanf("%d", &dims[i]);
    int a[dims[0]][dims[1]][dims[2]][dims[3]][dims[4]][dims[5]][dims[6]][dims[7]][dims[8]][dims[9]][dims[10]];
    int dist[dims[0]][dims[1]][dims[2]][dims[3]][dims[4]][dims[5]][dims[6]][dims[7]][dims[8]][dims[9]][dims[10]];
    queue<vector<int>> q;

    for (int i10=0;i10<dims[10];++i10)
        for (int i9=0;i9<dims[9];++i9)
            for (int i8=0;i8<dims[8];++i8)
                for (int i7=0;i7<dims[7];++i7)
                    for (int i6=0;i6<dims[6];++i6)
                        for (int i5=0;i5<dims[5];++i5)
                            for (int i4=0;i4<dims[4];++i4)
                                for (int i3=0;i3<dims[3];++i3)
                                    for (int i2=0;i2<dims[2];++i2)
                                        for (int i1=0;i1<dims[1];++i1)
                                            for (int i0=0;i0<dims[0];++i0) {
                                                scanf("%d", &a[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10]);
                                                if (a[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] == 1) {
                                                    dist[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] = 0;
                                                    q.push({i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10});
                                                }
                                            }

    int ans = 0;
    while (!q.empty()) {
        auto now = q.front(); q.pop();
        int cost = dist[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]];
        ans = max(ans, cost);
        for (int dim=0;dim<11;++dim) {
            for (int k=0;k<2;++k) {
                now[dim] += delta[k];
                if (0 <= now[dim] && now[dim] < dims[dim]) {
                    if (a[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]] == 0) {
                        q.push(now);
                        a[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]] = 1;
                        dist[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]] = cost + 1;
                    }
                }
                now[dim] -= delta[k];
            }
        }
    }

    for (int i10=0;i10<dims[10];++i10)
        for (int i9=0;i9<dims[9];++i9)
            for (int i8=0;i8<dims[8];++i8)
                for (int i7=0;i7<dims[7];++i7)
                    for (int i6=0;i6<dims[6];++i6)
                        for (int i5=0;i5<dims[5];++i5)
                            for (int i4=0;i4<dims[4];++i4)
                                for (int i3=0;i3<dims[3];++i3)
                                    for (int i2=0;i2<dims[2];++i2)
                                        for (int i1=0;i1<dims[1];++i1)
                                            for (int i0=0;i0<dims[0];++i0) {
                                                if (a[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] == 0) {
                                                    puts("-1");
                                                    return 0;
                                                }
                                            }
    printf("%d", ans);
}
