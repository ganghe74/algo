#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

struct stat S;
char*J=(char*)mmap(0,S.st_size,1,2,0,fstat(0,&S));

int n, x;

char getc() {
    return *J++;
}

int getu() {
    int ret = 0;
    char c = getc();
    while (c == ' ' || c == '\n') c = getc();
    while ('0' <= c && c <= '9') {
        ret = ret * 10 + c - 48;
        c = getc();
    }
    return ret;
}

int geti() {
    int ret = 0, sign = 1;
    char c = getc();
    while (c == ' ' || c == '\n') c = getc();
    if (c == '-') sign = -1, c = getc();
    while ('0' <= c && c <= '9') {
        ret = ret * 10 + c - 48;
        c = getc();
    }
    return sign * ret;
}

int main() {
    n = getu();
    printf("%d\n", n);
    while (n--) {
        x = getu();
        printf("%d\n", x);
    }
}
