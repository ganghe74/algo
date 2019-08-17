#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
    vector<string> same = {"Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};
    int T, a, b;
    cin >> T;
    for (int tc=1;tc<=T;++tc) {
        cin >> a >> b;
        if (a < b) swap(a,b);
        cout << "Case " << tc << ": ";
        if (a == 6 && b == 5) cout << "Sheesh Beesh\n";
        else if (a == b) cout << same[a-1] << '\n';
        else cout <<s[a-1] << " " << s[b-1] << '\n';
    }
}