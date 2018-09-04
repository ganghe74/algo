#include <iostream>
using namespace std;
int main() {
	int N, temp, sum;
	sum = 0;
	scanf("%d", &N);
	while (N--){
		scanf("%1d", &temp);
		sum += temp;
	}
	printf("%d", sum);
}
