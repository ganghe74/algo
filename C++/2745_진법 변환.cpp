#include <iostream>
#include <string>
using namespace std;
int main() {
	string N;
	int B, answer;
	answer = 0;
	cin >> N >> B;
	for (int i=0;i<N.size();++i) {
		if ('0' <= N[i] && N[i] <= '9') answer = answer * B + stoi(N.substr(i,1));
		else answer = answer * B + N[i]-'A'+10;
	}
	cout << answer;                                       
}               
