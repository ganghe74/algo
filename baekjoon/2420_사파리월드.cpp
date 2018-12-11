#include <cstdio>
#define abs(a) (((a)>0)?(a):-(a))
using namespace std;
int main() {
    long long N, M;
    scanf("%lld%lld", &N, &M);
    printf("%lld", abs(N-M));
}