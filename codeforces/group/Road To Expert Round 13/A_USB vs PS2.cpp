#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, m;
    scanf("%d%d%d%d", &a, &b, &c, &m);
    vector<int> usb, ps2;
    while (m--) {
        int p;
        char s[5];
        scanf("%d %s", &p, s);
        if (s[0] == 'U') usb.push_back(p);
        else ps2.push_back(p);
    }
    sort(usb.begin(), usb.end(), greater<>());
    sort(ps2.begin(), ps2.end(), greater<>());
    long long com = 0, cost = 0;
    while (a > 0 && !usb.empty()) {
        com++;
        cost += usb[usb.size()-1];
        a--;
        usb.pop_back();
    }
    while (b > 0 && !ps2.empty()) {
        com++;
        cost += ps2[ps2.size()-1];
        b--;
        ps2.pop_back();
    }
    while (c > 0 && !usb.empty() && !ps2.empty()) {
        com++;
        c--;
        if (usb[usb.size()-1] < ps2[ps2.size()-1]) {
            cost += usb[usb.size()-1];
            usb.pop_back();
        }
        else {
            cost += ps2[ps2.size()-1];
            ps2.pop_back();
        }
    }
    while (c > 0 && !usb.empty()) {
        com++;
        cost += usb[usb.size()-1];
        c--;
        usb.pop_back();
    }
    while (c > 0 && !ps2.empty()) {
        com++;
        cost += ps2[ps2.size()-1];
        c--;
        ps2.pop_back();
    }
    printf("%lld %lld", com, cost);
}