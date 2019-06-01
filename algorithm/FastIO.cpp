#include <iostream>
using namespace std;

void fastscan(int &x) {
    bool neg=false;
    register int c;
    x = 0;
    c = getchar();
    if(c == '-') {
        neg = true;
        c = getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *= -1;
}

static char _buffer[524288];
static unsigned _currentChar = 0;
  
static inline int _read() {
    if (_currentChar == 524288) {
        fread(_buffer, 1, 524288, stdin);
        _currentChar = 0;
    }
    return _buffer[_currentChar++];
}
  
unsigned c, x;
  
static inline unsigned _readInt() {
    c = _read();
    while (c <= 32) c = _read();
    x = 0;
    while (c > 32) {
        x *= 10;
        x += c - '0';
        c = _read();
    }
    return x;
}

int main() {
    int a;
    fastscan(a);
    printf("%d\n", a);
    
    a = _readInt();
    printf("%d\n", a);
}