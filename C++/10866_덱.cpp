#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
	deque<int> dq;
	string what;
	int N;
	cin >> N;
	while (N--) {
		cin >> what;
		if (what == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (what == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (what == "pop_front") {
			if (dq.empty()) cout << -1 << endl;
			else {
			cout << dq.front() << endl;
			dq.pop_front();
			}
		}
		else if (what == "pop_back") {
			if (dq.empty()) cout << -1 << endl;
			else {
			cout << dq.back() << endl;
			dq.pop_back();
			}
		}
		else if (what == "size") {
			cout << dq.size() << endl;
		}
		else if (what == "empty") {
			cout << dq.empty() << endl;
		}
		else if (what == "front") {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
			cout << dq.front() << endl;
			}
		}
		else if (what == "back") {
			if (dq.empty()) {
				cout << -1 << endl;
			}
			else {
			cout << dq.back() << endl;
			}
		}
	}
}
