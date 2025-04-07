#include<stdio.h>
#include<time.h>
void swap(int *num1,int *num2){
int temp=*num1;
*num1=*num2;
*num2=temp;
}
int Partition(int array[],int low,int high)
{int pivot=array[low];
int i=low;
int j=high+1;
while(i<=j){
    if (array[i]<=pivot){
     i=i+1;}
    if (array[j]>=pivot){
        j=j-1;
    }
    swap(&array[i],&array[j]);
}
swap(&array[i],&array[j]);
swap(&array[j],&array[low]);
return j;
}

int QuickSort(int array[],int low,int high)
{
    if(low<high){
        int mid= Partition(array,low,high);
        QuickSort(array,low,mid-1);
        QuickSort(array,mid+1,high);
    }
}
int main()
{int a[15000], n, i, j, ch, temp;
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
                QuickSort(a, 0, n - 1);
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
                        a[i] = n - i;
                    }
                    start = clock();
                    QuickSort(a, 0, n - 1);
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
        getchar();
    }
}
