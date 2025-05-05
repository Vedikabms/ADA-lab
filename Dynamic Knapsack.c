#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    printf("\nDP matrix (rows: items, columns: capacities):\n");
    printf("    ");
    for (w = 0; w <= W; w++) {
        printf("%4d", w);
    }
    printf("\n");

    for (i = 0; i <= n; i++) {
        if (i == 0)
            printf("0:  ");
        else
            printf("%d:  ", i);
        for (w = 0; w <= W; w++) {
            printf("%4d", K[i][w]);
        }
        printf("\n");
    }

    int res = K[n][W];
    int capacity = W;
    printf("\nSelected items (index: weight, value):\n");
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i-1][capacity])
            continue;
        else {
            printf("Item %d: weight = %d, value = %d\n", i, wt[i-1], val[i-1]);
            res -= val[i-1];
            capacity -= wt[i-1];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    int max_value = knapsack(W, wt, val, n);
    printf("\nMaximum value in the knapsack = %d\n", max_value);

    return 0;
}
