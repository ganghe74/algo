#include <bits/stdc++.h>
using namespace std;
int N, a[1000000], d[1000000];
vector<int> lis = {(int)-2e9};
int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &a[i]);
        if (lis.back() < a[i]) {
            lis.push_back(a[i]);
            d[i] = lis.size()-1;
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
            d[i] = it - lis.begin();
        }
    }
    printf("%d\n", lis.size()-1);
    stack<int> st;
    for (int i=N-1,len=lis.size()-1;i>=0;--i) {
        if (d[i] == len) {
            st.push(a[i]);
            len--;
        }
    }
    while (!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
}