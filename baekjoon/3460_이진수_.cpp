#include <cstdio>
int main(){
    int n,t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for(int i=0; n; i++,n/=2) if(n&1) printf("%d ",i);
        puts("");
    }
}