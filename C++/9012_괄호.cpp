#include <iostream>
#include <string>
using namespace std;
string VPS(string ps){
	int count = 0;
	for (int i = 0;i<ps.size();i++){
		if (ps[i] == '(') {
			count += 1;
		}
		else {
			if (count > 0) {
				count -=1;
			}
			else {
				return "NO";
			}
		}
	}
	if (count == 0) return "YES";
	else return "NO";
}
int main() {
	int T;
	string x;
	cin >> T; 
	while (T--){
		cin >> x;
		cout << VPS(x) << endl;
	}
}
