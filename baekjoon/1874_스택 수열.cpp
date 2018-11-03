#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int main() {
	string answer = "";
	stack<int> simul;
	vector<int> sequence;
	int x, n;
	cin >> n;
	while (n--) {
		cin >> x;
		sequence.push_back(x);
	}
	n++;
	for (int i=0;i<sequence.size();i++) {
		if (sequence[i] > n) {
			while (sequence[i] > n) {
				++n;
				simul.push(n);
				answer += "+\n";
			}
			simul.pop();
			answer += "-\n";
		}
		else {
			if (sequence[i] != simul.top()) {
				answer = "NO";
				break;
			}
			else {
				simul.pop();
				answer += "-\n";
			}
		}
	}
	cout << answer;
}
