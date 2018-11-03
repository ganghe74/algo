#include <iostream>
using namespace std;
int main() {
	int N, i = 2;
	cin >> N;
	while (N != 1) {
		if (N % i == 0) {
			cout << i << endl;
			N = N / i;
		}
		else i+=1;
	}
}
