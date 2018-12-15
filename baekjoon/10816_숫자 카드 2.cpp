#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> card(20000001);
    int N, M, temp;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &temp);
        card[temp+10000000] += 1;
    }
    scanf("%d", &M);
    int find[M];
    for (int i=0;i<M;++i) scanf("%d", &find[i]);
    for (int i=0;i<M;++i) printf("%d ", card[find[i]+10000000]);
}