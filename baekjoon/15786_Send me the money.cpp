#include <iostream>
using namespace std;
int main() {
    char S[101], post[1001];
    int N, M;
    scanf("%d%d", &N, &M);
    scanf("%s", S);
    for (int i=0;i<M;++i) {
        int j = 0, find = 0;
        scanf("%s", post);
        while (post[j] != '\0')
            if (post[j++] == S[find]) find++;
        if (find == N) puts("true");
        else puts("false");
    }
}