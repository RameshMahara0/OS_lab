#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    int sum = 0;

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of left diagonal = %d\n", sum);

    return 0;
}
