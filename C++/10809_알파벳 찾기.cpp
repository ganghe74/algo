#include <iostream>
#include <string>
using namespace std;
int main() {
	string S;
	int answer[26];
	for (int i=0;i<26;i++) answer[i] = -1;
	cin >> S;
	for (int i = S.size()-1;i>=0;i--) {
		answer[S[i] - 'a'] = i;
	}
	for (auto &n : answer) {
		printf("%d ", n);
	}
}
