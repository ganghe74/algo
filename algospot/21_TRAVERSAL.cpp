#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
    const int N = preorder.size();
    if(preorder.empty()) return;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - 1 - L;
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
    printf("%d ", root);
}
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        vector<int> preorder(N), inorder(N);
        for (int i=0;i<N;++i) scanf("%d", &preorder[i]);
        for (int i=0;i<N;++i) scanf("%d", &inorder[i]);
        printPostOrder(preorder, inorder);
    }
    
}