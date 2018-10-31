#include <iostream>
#include <string>
using namespace std;
int main() {
    string s[14] = {"sukhwan", "baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby"};
    int N;
    cin >> N;
    if (N%14 == 3 || N%14 == 7 || N%14 == 11) {
        if (N/14 >= 3) {
            cout << "tu+ru*" << N/14+2;
        }
        else {
            cout << s[N%14];
            for (int i=0;i<N/14;++i) {
                cout << "ru";
            }
        }
    }
    else if (N%14 == 4 || N%14 == 8 || N%14 == 12) {
        if (N/14 >= 4) {
            cout << "tu+ru*" << N/14+1;
        }
        else {
            cout << s[N%14];
            for (int i=0;i<N/14;++i) {
                cout << "ru";
            }
        }
    }
    else {
        cout << s[N%14];
    }
}