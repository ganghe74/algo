#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    int d[16] = {0};
    stack<char> a;
    string x;
    cin >> x;
    for (int i=0;i<x.size();++i) {
        if (x[i] == '(' || x[i] == '[') a.push(x[i]);
        else {
            if (!a.empty()) {
                if (x[i] == ')' && a.top() == '(') {
                    a.pop();
                    if (d[a.size()+1] == 0) d[a.size()+1] += 1;
                    d[a.size()] = d[a.size()] + d[a.size()+1] * 2;
                    d[a.size()+1] = 0;
                }
                else if (x[i] == ']' && a.top() == '[') {
                    a.pop();
                    if (d[a.size()+1] == 0) d[a.size()+1] += 1;
                    d[a.size()] = d[a.size()] + d[a.size()+1] * 3;
                    d[a.size()+1] = 0;
                }
                else {
                    d[0] = 0;
                    break;
                }
            }
            else {
                d[0] = 0;
                break;
            }
        }
    }
    if (!a.empty()) d[0] = 0;
    cout << d[0];
}