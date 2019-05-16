#include <bits/stdc++.h>
using namespace std;

int main() {
    double a[26];
    int N;
    char s[101];
    scanf("%d", &N);
    scanf("%s", s);
    for (int i=0;i<N;++i) scanf("%lf", &a[i]);
    stack<double> st;
    for (int i=0;s[i]!='\0';++i) {
        if (isalpha(s[i])) {
            st.push(a[s[i]-'A']);
        }
        else {
            double num = st.top(); st.pop();
            if (s[i] == '+') {
                num += st.top(); st.pop();
            }
            else if (s[i] == '-') {
                num = st.top() - num; st.pop();
            }
            else if (s[i] == '*') {
                num *= st.top(); st.pop();
            }
            else if (s[i] == '/') {
                num = st.top() / num; st.pop();
            }
            st.push(num);
        }
    }
    printf("%.2lf", st.top());
}