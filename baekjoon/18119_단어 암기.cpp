#include <bits/stdc++.h>
using namespace std;

int N, M, o;
int status = 0xffffffff;
vector<int> words;
char s[1001], x;

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        scanf("%s", s);
        int word = 0;
        for (int i=0;s[i]!='\0';++i)
            word |= 1 << (s[i]-'a');
        words.push_back(word);
    }
    while (M--) {
        scanf("%d %c", &o, &x);
        if (o == 1) status &= ~(1 << (x-'a'));
        else status |= (1 << (x-'a'));
        int cnt = 0;
        for (int i=0;i<N;++i)
            if ((words[i] & status) == words[i]) cnt++;
        printf("%d\n", cnt);
    }
}
