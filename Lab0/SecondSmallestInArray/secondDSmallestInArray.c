#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = INT_MAX, secondSmallest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    if (secondSmallest == INT_MAX)
        printf("There is no second smallest element.\n");
    else
        printf("Second smallest element is: %d\n", secondSmallest);

    return 0;
}
