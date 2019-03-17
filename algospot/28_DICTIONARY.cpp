#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
void makeGraph(const vector<string>& words) {
    adj = vector<vector<int>>(26, vector<int>(26, 0));
    for (int j=1;j<words.size();++j) {
        int i = j-1, len = min(words[i].size(), words[j].size());
        for (int k=0;k<len;++k)
            if (words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
    }
}

vector<int> seen, order;
void dfs(int here) {
    seen[here] = 1;
    for (int there = 0; there<adj.size();++there)
        if (adj[here][there] && !seen[there])
            dfs(there);
    order.push_back(here);
}

vector<int> topologicalSort() {
    int n = adj.size();
    seen = vector<int>(n, 0);
    order.clear();
    for (int i=0;i<n;++i) if(!seen[i]) dfs(i);
    reverse(order.begin(), order.end());
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            if(adj[order[j]][order[i]])
                return vector<int>();
    return order;
}

int main() {
    int C, N;
    cin >> C;
    while (C--) {
        string word;
        cin >> N;
        vector<string> words;
        while (N--) {
            cin >> word;
            words.push_back(word);
        }
        makeGraph(words);
        vector<int> ret = topologicalSort();
        if (ret.empty()) puts("INVALID HYPOTHESIS");
        else {
            for (int n : ret) printf("%c", n + 'a');
            puts("");
        }
    }
}