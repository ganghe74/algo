#include <bits/stdc++.h>
using namespace std;

struct Node {
    int children[26];
    int pi;
    bool valid;
    Node() {
        for (int i=0;i<26;++i) children[i] = -1;
        valid = false;
        pi = -1;
    }
};
vector<Node> trie;
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
    int c = s[index] - 'A';
    if (trie[node].children[c] == -1) {
        int next = init();
        trie[node].children[c] = next;
    }
    add(trie[node].children[c], s, index+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, n, m;
    string dna, marker;
    cin >> T;
    while (T--) {
        cin >> n >> m >> dna >> marker;
        trie.clear();

        int root = init();
        add(root, marker, 0);
        for (int i=0;i<m;++i) {
            for (int j=i+1;j<m;++j) {
                reverse(marker.begin() + i, marker.begin() + j + 1);
                add(root, marker, 0);
                reverse(marker.begin() + i, marker.begin() + j + 1);
            }
        }

        queue<int> q;
        q.push(root);
        trie[root].pi = root;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i=0;i<26;++i) {
                int next = trie[cur].children[i];
                if (next == -1) continue;
                if (cur == root) trie[next].pi = root;
                else {
                    int x = trie[cur].pi;
                    while (x != root && trie[x].children[i] == -1) x = trie[x].pi;
                    if (trie[x].children[i] != -1) x = trie[x].children[i];
                    trie[next].pi = x;
                }
                int pi = trie[next].pi;
                trie[next].valid |= trie[pi].valid;
                q.push(next);
            }
        }

        int node = root, cnt = 0;
        for (int i=0;i<n;++i) {
            int c = dna[i] - 'A';
            while (node != root && trie[node].children[c] == -1) node = trie[node].pi;
            if (trie[node].children[c] != -1) node = trie[node].children[c];
            if (trie[node].valid) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}