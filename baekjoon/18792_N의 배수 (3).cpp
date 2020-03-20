#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

namespace io {
	constexpr int IS=1<<22, OS=1<<20;
	char I[IS],*J=I,O[OS+16],*K=O;
	void daer(){if(J>=I+IS-16){char*p=I;do*p++=*J++;while(J!=I+IS);read(0,p,I+IS-p);J=I;}};
	int getu(){daer();int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;};
	void flush(){write(1,O,K-O);K=O;}
	void putu(int n){char s[8],*p=s;do*p++=n%10|48;while(n/=10);do*K++=*--p;while(p!=s);*K++=32;if(K>=O+OS)flush();}
	struct f{f(){read(0,I,IS);}~f(){flush();}}flu;
};
using namespace io;

int N, x, cnt[50000];
bitset<50000> s[50000];
vector<int> a;
vector<pair<int,int>> ab;

void trace(int i, int k) {
    if (!i) {
        putu(ab[i].first);
        return;
    }
    if (s[i-1][(k-ab[i].first+N)%N]) {
        putu(ab[i].first);
        trace(i-1, (k-ab[i].first+N)%N);
    }
    else {
        putu(ab[i].second);
        trace(i-1, (k-ab[i].second+N)%N);
    }
}

bitset<50000> rotate_shift_l(bitset<50000> &bs, int amt) {
    bitset<50000> ret;
    ret |= bs << amt;
    ret |= bs >> (N-amt);
    return ret;
}

int main() {
    N = getu();
    for (int i=0;i<2*N-1;++i) {
        x = getu();
        if (++cnt[x] >= N) {
            for (int i=0;i<N;++i) putu(x);
            flush();
            return 0;
        }
        a.push_back(x);
    }

    x = a[0];
    cnt[x]--;
    s[0][x] = 1;
    ab.push_back({x, x});

    priority_queue<pair<int,int>> pq;
    for (int i=0;i<N;++i)
        if (cnt[i]) pq.push({cnt[i], i});

    for (int i=1;i<N;++i) {
        auto [cnt_ai, ai] = pq.top(); pq.pop();
        auto [cnt_bi, bi] = pq.top(); pq.pop();

        if (cnt_ai > 1) pq.push({cnt_ai-1, ai});
        if (cnt_bi > 1) pq.push({cnt_bi-1, bi});

        ab.push_back({ai, bi});

        s[i] = rotate_shift_l(s[i-1], ai) | rotate_shift_l(s[i-1], bi);
    }

    trace(N-1, 0);
    flush();
}
