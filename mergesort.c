#include <stdio.h>
#include <time.h>
#include <stdlib.h> /* To recognize exit function when compiling with gcc */

void split(int[], int, int);
void combine(int[], int, int, int);

void main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;
    while(1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for(i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                split(a, 0, n - 1);
                end = clock();
                printf("\nSorted array is: ");
                for(i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                break;

            case 2:
                n = 500;
                while(n <= 14500) {
                    for(i = 0; i < n; i++) {
                        // a[i] = random(1000); // Using the correct way to populate the array
                        a[i] = n - i; // Reverse order to maximize sorting time
                    }
                    start = clock();
                    split(a, 0, n - 1);
                    // Dummy loop to create delay
                    for(j = 0; j < 500000; j++) {
                        temp = 38 / 600;
                    }
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                    n = n + 1000;
                }
                break;

            case 3:
                exit(0);
        }
        getchar(); // Consume the newline character left in the input buffer
    }
}

void split(int a[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        split(a, low, mid);  // Recursively sort the left half
        split(a, mid + 1, high); // Recursively sort the right half
        combine(a, low, mid, high); // Merge the two halves
    }
}

void combine(int a[], int low, int mid, int high) {
    int c[15000], i, j, k;
    i = k = low;
    j = mid + 1;

    // Merging the two halves
    while(i <= mid && j <= high) {
        if(a[i] < a[j]) {
            c[k] = a[i];
            ++k;
            ++i;
        } else {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }

    // Copying the remaining elements from the left half
    if(i > mid) {
        while(j <= high) {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }

    // Copying the remaining elements from the right half
    if(j > high) {
        while(i <= mid) {
            c[k] = a[i];
            ++k;
            ++i;
        }
    }

    // Copying the merged array back to the original array
    for(i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
