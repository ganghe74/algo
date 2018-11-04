// nlogn
#include <iostream>
#include <vector>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

using namespace std;
vector<int> H;

int solve(int left, int right) {
    if (left == right) return H[left];
    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid+1, right));
    int lo = mid, hi = mid+1;
    int height = min(H[lo], H[hi]);
    ret = max(ret, height * 2);
    while(left < lo || hi < right) {
        if (hi < right && (lo == left || H[lo-1] < H[hi+1])) {
            ++hi;
            height = min(height, H[hi]);
        }
        else {
            --lo;
            height = min(height, H[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
    int C;
    scanf("%d",&C);
    while(C--) {
        int N;
        scanf("%d", &N);
        for (int i=0;i<N;++i) {
            int temp;
            scanf("%d", &temp);
            H.push_back(temp);
        }
        printf("%d\n", solve(0, N-1));
        H.clear();
    }
}