#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char S[102];
	int small, num, big, space, len; 
	small = num = big = space = 0;
	while (fgets(S,100,stdin)) {
		len = strlen(S);
		for (int i=0; i<len;i++) {
			if ('a' <= S[i] && S[i] <= 'z') small += 1;
			else if ('A' <= S[i] && S[i] <= 'Z') big += 1;
			else if ('0' <= S[i] && S[i] <= '9') num += 1;
			else if (S[i] == ' ') space += 1;
			else {
				printf("%d %d %d %d\n", small, big, num, space);
				small = num = big = space = 0;
			}
		}
	}
}
