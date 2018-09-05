#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	int N;
	string init;
	cin >> init;
	cin >> N;
	stack<char> left, right;
	for (int i=0;i<init.size();i++){
		left.push(init[i]);
	}
	char input;
	while (N--) {
		cin >> input;
		if (input == 'L') {
			if (left.size() == 0) continue;
			right.push(left.top());
			left.pop();
		}
		else if (input == 'D') {
			if (right.size() == 0) continue;
			left.push(right.top());
			right.pop();
		}
		else if (input == 'B') {
			if (left.size() == 0) continue;
			left.pop();
		}
		else {
			cin >> input;
			left.push(input);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
}
