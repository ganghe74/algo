#include <bits/stdc++.h>
using namespace std;
using lint = long long;
 
int T, TRY;
int X;
 
lint query_submit(lint Q) {
    TRY--;
    printf("? %lld\n", Q);
    puts("");
    fflush(stdout);
    lint ret;
    scanf("%lld", &ret);
    return ret;
}
 
vector<lint> querys = {614889782588491410, 38655288426304091, 22125549654501673, 316773187163046517, 9879251463499721, 39049078408188253, 108538288030848139, 309619196508457007, 796229312542859009, 4064625951224869, 6860596063872959, 10626236358872441, 17092564102090369, 30150641449095443, 43889293834596251, 60888412234461547, 83850965748659689, 122610116602749401, 174123625045688707, 244629182107482857, 331523275336187063, 433432014951605099};
vector<int> primes;
bool sieve[2000];
 
int main() {
    for (int i=2; i<2000; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j=2; i*j<2000; ++j)
                sieve[i*j] = 1;
        }
    }
    scanf("%d", &T);
    while (T--) {
        TRY = 22;
        int qnum = 0;
        vector<int> dnums;
        while (TRY > 0) {
            lint d = query_submit(querys[qnum++]);
            vector<int> divisors;
            for (int p : primes)
                if (d % p == 0)
                    divisors.push_back(p);
            for (int p : divisors) {
                if (TRY > 0) {
                    lint q = 1;
                    while (q * p <= 1e9) q *= p;
                    d = query_submit(q);
                    int cnt = 0;
                    while (d > 1) {
                        d /= p;
                        cnt++;
                    }
                    dnums.push_back(cnt);
                }
                else {
                    dnums.push_back(1);
                }
            }
        }
        lint ans = 1;
        for (int q : dnums) ans *= (q+1);
        ans = max(ans*2, ans+7);
        printf("! %lld\n", ans);
        fflush(stdout);
    }
}
