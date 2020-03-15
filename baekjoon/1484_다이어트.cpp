#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    int G;
    scanf("%d", &G);
    vector<lint> ans;
    for (lint i=1,j=1;j*j-(j-1)*(j-1)<=G;j++) {
        while (j*j-i*i > G) i++;
        if (j*j-i*i == G) ans.push_back(j);
    }
    if (ans.empty()) puts("-1");
    else
        for (lint x : ans) printf("%lld\n", x);
}
