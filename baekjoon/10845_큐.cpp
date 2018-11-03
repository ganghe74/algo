#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	queue<int> Q;
	int N;
	string what;
	cin >> N;
	while (N--) {
		cin >> what;
		if (what == "push") {
			int x; 
			cin >> x;
			Q.push(x);
		}
		else if (what == "pop") {
			if (Q.empty()){
				cout << -1 << endl;
				continue;
			}
			else {
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		else if (what == "size") {
			cout << Q.size() << endl;
		}
		else if (what == "empty") {
			cout << Q.empty() << endl;
		}
		else if (what == "front") {
			if (Q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << Q.front() << endl;
			}
		}
		else if (what == "back") {
			if (Q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << Q.back() << endl;
			}
		}
	}
}
