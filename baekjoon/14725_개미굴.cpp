#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<string,int> children;
};

int n, k, root;
string s;
vector<Node> trie;

int init() {
    Node x;
    trie.push_back(x);
    return (int)trie.size() - 1;
}

void add(const vector<string> &p, int node, int idx) {
    if (p.size() == idx) return;
    if (!trie[node].children[p[idx]])
        trie[node].children[p[idx]] = init();
    int next = trie[node].children[p[idx]];
    add(p, next, idx+1);
}

void print(int node, int depth) {
    for (auto [s, next] : trie[node].children) {
        cout << string(depth*2, '-') << s << '\n';
        print(next, depth+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    root = init();
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> k;
        vector<string> p;
        while (k--) {
            cin >> s;
            p.push_back(s);
        }
        add(p, root, 0);
    }
    print(root, 0);
}
