// https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
#include <iostream>
#include <unistd.h>
constexpr int BS=1<<22;
char I[BS],*J=I;

int n, x;

int main() {
    syscall(0,0,I,BS);
    auto daer=[&]{if(J>=I+BS-16){char*p=I;do*p++=*J++;while(J!=I+BS);syscall(0,0,p,I+BS-p);J=I;}};
    auto getu=[&]{daer();int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;};
    auto geti=[&]{daer();int x=0;bool e=*J=='-';J+=e;do x=x*10+*J-'0';while(*++J>='0');++J;return e?-x:x;};
    n = getu();
    printf("%d\n", n);
    while (n--) {
        x = getu();
        printf("%d\n", x);
    }
}
