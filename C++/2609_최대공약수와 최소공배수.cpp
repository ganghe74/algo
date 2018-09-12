#include <iostream>
using namespace std;
int gcd(int x, int y) {
	if (y==0) return x;
	return gcd(y, x%y); 
}
int lcm(int x, int y) {
	return x/gcd(x,y)*y;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a,b) << endl << lcm(a,b);
}
