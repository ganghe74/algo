#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
int base = 256;

long long h(string s) {
    long long ans = 0;
    for (char ch : s) ans = (ans * base + ch) % mod;
    return ans;
}

// Time Complexity
// Worst : O(NM)
// Expected : O(N+M)
vector<int> match(string s, string p) {
    vector<int> ret;
    int n = s.length();
    int m = p.length();
    if (n < m) return ret;
    long long hash_p = h(p);
    long long hash_s = h(s.substr(0,m));
    long first = 1;
    for (int i=0;i<m-1;++i) first = (first * base) % mod;
    for (int i=0;i<=n-m;++i) {
        if (hash_p == hash_s) {
            if (s.substr(i, m) == p) ret.push_back(i);
        }
        if (i+m < n) {
            hash_s = hash_s - (s[i] * first) % mod;
            hash_s = (hash_s + mod) % mod;
            hash_s = ((hash_s * base) % mod + s[i+m]) % mod;
        }
    }
    return ret;
}

int main() {
    vector<int> indices;
    indices = match("ababa", "aba");
    for (int i : indices) printf("%d ", i);
    puts("");

    indices = match("aaaaa", "a");
    for (int i : indices) printf("%d ", i);
    puts("");

    indices = match("abdabdabc", "abdabc");
    for (int i : indices) printf("%d ", i);
    puts("");
}
