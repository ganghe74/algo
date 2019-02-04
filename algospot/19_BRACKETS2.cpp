#include <iostream>
#include <stack>
using namespace std;
int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        char s[10005];
        scanf("%s", s);
        stack<int> S;
        bool yes = true;
        for (int i=0;s[i]!='\0';++i) {
            if (s[i] == '(') S.push(1);
            else if (s[i] == '{') S.push(2);
            else if (s[i] == '[') S.push(3);
            else if (S.empty()) {
                yes = false;
                continue;
            }
            else if (s[i] == ')' && S.top() == 1) S.pop();
            else if (s[i] == '}' && S.top() == 2) S.pop();
            else if (s[i] == ']' && S.top() == 3) S.pop();
            else yes = false;
        }
        if (yes && S.empty()) printf("YES\n");
        else printf("NO\n");
    }
}