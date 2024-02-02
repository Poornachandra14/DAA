#include <stdio.h>

#define MAX 10

void subsetSum(int set[], int n, int target, int subset[], int subsetSize, int sum, int k) {
    if (sum == target) {
        printf("Subset found: { ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    for (int i = k; i < n; i++) {
        subset[subsetSize] = set[i];
        subsetSum(set, n, target, subset, subsetSize + 1, sum + set[i], i + 1);
    }
}

int main() {
    int n, target;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[MAX];

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int subset[MAX];
    subsetSum(set, n, target, subset, 0, 0, 0);

    return 0;
}
