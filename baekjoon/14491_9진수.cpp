#include <iostream>
#include <stack>
using namespace std;
int main() {
	int T;
	cin >> T;
	stack<int> answer;
	while (T>8) {
		answer.push(T%9);
		T = T/9;
	}
	answer.push(T);
	while(!answer.empty()) {
		cout << answer.top();
		answer.pop();
	}
}
