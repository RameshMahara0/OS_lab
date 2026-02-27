#include <stdio.h>

int main() {
    int rows, cols;


    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int rowSum, colSum;


    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    printf("\nSum of each row:\n");
    for(int i = 0; i < rows; i++) {
        rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, rowSum);
    }


    printf("\nSum of each column:\n");
    for(int j = 0; j < cols; j++) {
        colSum = 0;
        for(int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Column %d sum = %d\n", j + 1, colSum);
    }

    return 0;
}
