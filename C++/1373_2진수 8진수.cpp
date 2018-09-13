#include <iostream>
#include <string> 
using namespace std;
int main() {
	int temp;
	string answer = "";
	string n;
	cin >> n;
	if (n.size() % 3 == 1) n = "00" + n;
	else if (n.size() % 3 == 2) n = "0" + n;
	for (int i=0;i<n.size();i+=3) {
		temp = stoi(n.substr(i,1)) * 4;
		temp += stoi(n.substr(i+1,1)) * 2;
		temp += stoi(n.substr(i+2,1));
		answer += to_string(temp);
	}
	cout << answer;
}
