#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;
    int M = 0;
    for (int i=0;i<s.length();++i)
        if (s[i] == '8')
            M++;
    cout << min(M, N/11);
}