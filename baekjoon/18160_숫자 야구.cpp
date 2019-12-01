#include "NB.h"
#include <bits/stdc++.h>
using namespace std;

int len, s, b;
string num, guessed;
vector<string> all_nums, nums, nums_next;
bool c[10];
pair<int,int> pi;

void init_vector(int k) {
    if (k == len) {
        all_nums.push_back(num);
        return;
    }
    for (int i=0;i<10;++i) {
        if (!c[i]) {
            c[i] = true;
            num = num + to_string(i);
            init_vector(k+1);
            c[i] = false;
            num.pop_back();
        }
    }
}

void init(int T, int N) {
    len = N;
    init_vector(0);
}

void game() {
    nums = all_nums;
    while (true) {
        guessed = nums.back();
        tie(s, b) = guess(guessed);
        if (s == len) return;
        for (string &num : nums) {
            int s_cnt = 0, b_cnt = 0;
            for (int i=0;i<len;++i) {
                for (int j=0;j<len;++j) {
                    if (guessed[i] == num[j]) {
                        if (i == j) s_cnt++;
                        else b_cnt++;
                    }
                }
            }
            if (s == s_cnt && b == b_cnt) nums_next.push_back(num);
        }
        nums = nums_next;
        nums_next.clear();
    }
}