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

int n;
vector<Node> trie;

int init() {
    Node x;
    trie.push_back(x);
    return (int)trie.size()-1;
}

void add(int node, const string &s, int index) {
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

pair<int,int> solve(int node) {
    int nochild = 0;
    int types = 0, words = 0;
    for (int i=0;i<26;++i) {
        int child = trie[node].children[i];
        if (child != -1) {
            nochild++;
            auto [t1, t2] = solve(child);
            types += t1; words += t2;
        }
    }
    if (node == 0 || !(nochild == 0 || (nochild == 1 && !trie[node].valid)))
        types += words;
    if (trie[node].valid)
        words++;
    return {types, words};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout.setf(ios::fixed); cout.precision(2);
    while (cin >> n) {
        trie.clear();
        int root = init();
        for (int i=0;i<n;++i) {
            string s;
            cin >> s;
            add(root, s, 0);
        }
        cout << (double)solve(0).first / n << '\n';
    }
}
