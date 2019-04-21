#include <iostream>
#include <stack>
using namespace std;

int isp(char op) {
    if (op == '*' || op == '/') return 1;
    if (op == '+' || op == '-') return 2;
    if (op == '(') return 8;
    return 8;
}

int icp(char op) {
    if (op == '(') return 0;
    if (op == '*' || op == '/') return 1;
    if (op == '+' || op == '-') return 2;
    return 8;
}

int main() {
    char str[101];
    stack<char> s;
    s.push('#');
    scanf("%s", str);
    for (int i=0;str[i]!='\0';++i) {
        if ('A' <= str[i] && str[i] <= 'Z') putchar(str[i]);
        else if (str[i] == ')') {
            while (s.top() != '(') {
                putchar(s.top());
                s.pop();
            }
            s.pop();
        }
        else {
            while (icp(str[i]) >= isp(s.top())) {
                putchar(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while (s.size() > 1) {
        putchar(s.top());
        s.pop();
    }
}