#include <stdio.h>

int main() {
	int A, B;
	scanf("%d", &A);
	if (A == 6 || A == 9 || A == 12) {
		printf("%d", A / 3);
		return 0;
	}

	B = A / 5 * 5;
	A = A - B;

	while (B > 5) {
		if (A % 3 == 0) {
			break;
		}
		A += 5;
		B -= 5;
	}
	if (A % 3 != 0) printf("-1");
	else printf("%d", A / 3 + B / 5);

	return 0;
}