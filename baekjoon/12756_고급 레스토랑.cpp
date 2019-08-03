#include <bits/stdc++.h>
using namespace std;

int main() {
    int at1, at2, hp1, hp2;
    cin >> at1 >> hp1 >> at2 >> hp2;
    while (hp1 > 0 && hp2 > 0) {
        hp1 -= at2;
        hp2 -= at1;
    }
    if (hp1 > 0) cout << "PLAYER A";
    else if (hp2 > 0) cout << "PLAYER B";
    else cout << "DRAW";
}