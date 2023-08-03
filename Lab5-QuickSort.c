#include<stdio.h>
#include<time.h>
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Use the first element as the pivot
    int i = low;
    int j = high + 1;
    int temp;

    while (1) 
    {
        do
        {
            i++;
        }while (arr[i] <= pivot && i <= high);

        do
        {
            j--;
        }while (arr[j] > pivot && j >= low);

        if (i >= j) {
            break;
        }

        // Swap arr[i] and arr[j]
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Swap arr[low] (pivot) and arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pidx = partition(arr, low, high);
        quickSort(arr, low, pidx - 1);
        quickSort(arr, pidx + 1, high);
    }
}

int main() {
    int n;
    clock_t st,et;
    double ts;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    st=clock();
    quickSort(arr, 0, n - 1);
    et=clock();
    ts=(double)((et-st)/CLOCKS_PER_SEC);
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken for quick sort:%f\n",ts);
    return 0;
}
