#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> m;
    int N, M;
    scanf("%d%d", &N, &M);
    char names[N+1][21];
    for (int i=1;i<=N;++i) {
        scanf("%s", names[i]);
        m[names[i]] = i;
    }
    for (int i=0;i<M;++i) {
        char find[21];
        scanf("%s", find);
        if (find[0] < 'A') {
            int idx = atoi(find);
            printf("%s\n", names[idx]);
        }
        else {
            printf("%d\n", m[find]);
        }
    }
}