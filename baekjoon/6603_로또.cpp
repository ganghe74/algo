#include <bits/stdc++.h>
using namespace std;
int main() {
    int size;
    scanf("%d", &size);
    while (size != 0) {
        vector<int> nums(size);
        vector<int> choice(size);
        for (int i=0;i<size;++i) scanf("%d", &nums[i]);
        for (int i=0;i<6;++i) choice[i] = true;
        do {
            for (int i=0;i<size;++i) {
                if (choice[i]) printf("%d ", nums[i]);
            }
            printf("\n");
        } while (prev_permutation(choice.begin(), choice.end()));
        printf("\n");
        scanf("%d", &size);
    }
}