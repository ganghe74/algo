#include <bits/stdc++.h>
using namespace std;

struct Node {
    int children[26];
    bool valid;
    Node() {
        for (int i=0;i<26;++i) children[i] = -1;
        valid = false;
    }
};
vector<Node> trie;
int root;

int init() {
    Node x;
    trie.push_back(x);
    return (int)trie.size() - 1;
}

void add(int node, string &s, int index) {
    if (index == s.size()) {
        trie[node].valid = true;
        return;
    }
    int c = s[index] - 'a';
    if (trie[node].children[c] == -1) {
        int next = init();
        trie[node].children[c] = next;
    }
    int child = trie[node].children[c];
    add(child, s, index+1);
}

bool search(int node, string &s, int index) {
    if (node == -1) return false;
    if (index == s.size()) return true;
    int c = s[index] - 'a';
    int child = trie[node].children[c];
    return search(child, s, index+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    root = init();
    int N, M, ans = 0;
    string s;
    cin >> N >> M;
    while (N--) {
        cin >> s;
        add(root, s, 0);
    }
    while (M--) {
        cin >> s;
        if (search(0, s, 0)) ans++;
    }
    cout << ans;
}