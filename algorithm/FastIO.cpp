// https://github.com/ganghe74/algorithm-training/tree/master/baekjoon/special/11921
#include <iostream>
#include <unistd.h>
constexpr int IS=1<<22;
char I[IS],*J=I;

int n;
long long s;

int main() {
    syscall(0,0,I,IS);
    auto daer=[&]{if(J>=I+IS-16){char*p=I;do*p++=*J++;while(J!=I+IS);syscall(0,0,p,I+IS-p);J=I;}};
    auto getu=[&]{daer();int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;};
    auto geti=[&]{daer();int x=0;bool e=*J=='-';J+=e;do x=x*10+*J-'0';while(*++J>='0');++J;return e?-x:x;};
    n = getu();
    printf("%d\n", n);
    while (n--) s += getu();
    printf("%lld", s);
}
