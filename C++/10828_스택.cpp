#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	int N;
	string what;
	int x = 0;
	stack<int> s;
	cin >> N;
	while (N--) {
		cin >> what;
		if (what == "push") {
			cin >> x;
			s.push(x);
		}
		else if (what == "pop") {
			if (!s.empty()){
				cout << s.top() << endl;
				s.pop();
			}
			else{
				cout << -1 << endl;
			}
		}
		else if (what == "size") {
			cout << s.size() << endl;
		}
		else if (what == "empty") {
			if (s.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (what == "top") {
			if (s.empty()) cout << -1 << endl;
			else cout << s.top() << endl;
		}
	}
}
