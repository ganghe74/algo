#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    string x;
    cin >> N;
    while (N--) {
        cin >> x;
        if (x[x.size()/2] == x[x.size()/2-1]) cout << "Do-it" << '\n';
        else cout << "Do-it-Not" << '\n';
    }
}