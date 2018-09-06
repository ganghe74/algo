#include <iostream>
#include <string>
using namespace std;
int main() {
	string S;
	getline(cin, S);
	for (char &n : S) {
		if ('a' <= n && n <= 'm') printf("%c",n+13);
		else if ('n' <= n && n <= 'z') printf("%c",n-13);
		else if ('A' <= n && n <= 'M') printf("%c",n+13);
		else if ('N' <= n && n <= 'Z') printf("%c",n-13);
		else cout << n;
	}
}
