#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        int children[2];
        bool valid;
        Node() {
            for (int i=0;i<2;++i) children[i] = -1;
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
    Trie() {
        root = init();
    }
    void add(int node, int num, int bit) {
        if (bit == -1) {
            trie[node].valid = true;
            return;
        }
        int c = (num >> bit) & 1;
        if (trie[node].children[c] == -1) {
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], num, bit-1);
    }
    void add(int num) {
        add (root, num, 31);
    }
    int query(int node, int num, int bit) {
        if (bit == -1) return 0;
        int c = (num >> bit) & 1;
        c = 1-c;
        if (trie[node].children[c] == -1) c = 1-c;
        if (trie[node].children[c] == -1) return 0;
        int next = 0;
        if (c == 1) next = 1 << bit;
        return next | query(trie[node].children[c], num, bit-1);
    }
    int query(int num) {
        return query(root, num, 31);
    }
};

int main() {
    int n, num, ans = 0;
    scanf("%d", &n);
    Trie trie;
    for (int i=0;i<n;++i) {
        scanf("%d", &num);
        trie.add(num);
        ans = max(ans, trie.query(num) ^ num);
    }
    printf("%d", ans);
}