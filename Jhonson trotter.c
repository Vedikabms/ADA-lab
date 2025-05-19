#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int dir;
} Element;

void printPermutation(Element *perm, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i].value);
    printf("\n");
}

int getMobile(Element *perm, int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        int next = i + perm[i].dir;

        if (next >= 0 && next < n && perm[i].value > perm[next].value) {
            if (perm[i].value > mobile) {
                mobile = perm[i].value;
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

void generatePermutations(int n) {
    Element *perm = (Element *)malloc(n * sizeof(Element));

    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int mobileIndex = getMobile(perm, n);
        if (mobileIndex == -1)
            break;

        int next = mobileIndex + perm[mobileIndex].dir;

        Element temp = perm[mobileIndex];
        perm[mobileIndex] = perm[next];
        perm[next] = temp;

        for (int i = 0; i < n; i++)
            if (perm[i].value > temp.value)
                perm[i].dir = -perm[i].dir;

        printPermutation(perm, n);
    }

    free(perm);
}

int main() {
    int n;
    printf("Enter number of elements to permute: ");
    scanf("%d", &n);

    generatePermutations(n);

    return 0;
}
