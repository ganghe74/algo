#include <iostream>
#include <string>
using namespace std;
string solve() {
	string answer = "";
	int n, plus, max, now, before;
	before = 0;
	plus = 0;
	max = 0;
	cin >> n;
	for (int i=0;i<n;i++) {
		cin >> now;
		if (now > before) {
			for (int j=0;j<now - max;j++) {
				answer += "+\n";
				plus += 1;
				if (plus > n) return "NO";
			}
			max = now;
			answer += "-\n";
		} else {
			answer += "-\n";
		}
		before = now;
	}
	return answer;
}
int main() {
	cout << solve();
}
