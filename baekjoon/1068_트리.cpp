#include <iostream>
#include <vector>
using namespace std;
int N, root, del, p;
vector<int> children[50];
int cnt(int r) {
    if (r == del) return 0;
    if (children[r].empty()) return 1;
    if (children[r].size() == 1 && children[r][0] == del) return 1;
    int ret = 0;
    for (int child : children[r]) ret += cnt(child);
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &p);
        if (p == -1) root = i;
        else children[p].push_back(i);
    }
    scanf("%d", &del);
    printf("%d", cnt(root));
}