
#include <stdio.h>

#define MAX 10

int n, m;

int Allocation[MAX][MAX];
int Max[MAX][MAX];
int Need[MAX][MAX];
int Available[MAX];

void calculateNeed() {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

int safetyAlgorithm() {

    int Work[MAX];
    int Finish[MAX];
    int SafeSequence[MAX];

    int i, j, k;

    for(i = 0; i < m; i++)
        Work[i] = Available[i];

    for(i = 0; i < n; i++)
        Finish[i] = 0;

    int count = 0;

    while(count < n) {

        int found = 0;

        for(i = 0; i < n; i++) {

            if(Finish[i] == 0) {

                for(j = 0; j < m; j++) {

                    if(Need[i][j] > Work[j])
                        break;
                }

                if(j == m) {

                    for(k = 0; k < m; k++)
                        Work[k] += Allocation[i][k];

                    SafeSequence[count++] = i;
                    Finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n) {

        printf("\nSYSTEM IS IN SAFE STATE\n");

        printf("Safe Sequence: ");

        for(i = 0; i < n; i++) {

            printf("P%d", SafeSequence[i]);

            if(i != n - 1)
                printf(" -> ");
        }

        printf("\n");

        return 1;
    }

    else {

        printf("\nSYSTEM IS IN UNSAFE STATE\n");
        return 0;
    }
}

void resourceRequest() {

    int process;
    int Request[MAX];

    int i;

    printf("\nEnter Process Number: ");
    scanf("%d", &process);

    printf("Enter Request Vector:\n");

    for(i = 0; i < m; i++)
        scanf("%d", &Request[i]);

    for(i = 0; i < m; i++) {

        if(Request[i] > Need[process][i]) {

            printf("\nERROR: Process exceeded maximum claim.\n");
            return;
        }
    }

    for(i = 0; i < m; i++) {

        if(Request[i] > Available[i]) {

            printf("\nResources not available. Process must wait.\n");
            return;
        }
    }
    for(i = 0; i < m; i++) {

        Available[i] -= Request[i];
        Allocation[process][i] += Request[i];
        Need[process][i] -= Request[i];
    }

    printf("\nChecking for Safe State...\n");

    if(safetyAlgorithm()) {

        printf("\nRequest CAN be granted.\n");
    }

    else {

        for(i = 0; i < m; i++) {

            Available[i] += Request[i];
            Allocation[process][i] -= Request[i];
            Need[process][i] += Request[i];
        }

        printf("\nRequest CANNOT be granted.");
        printf("\nSystem restored to previous state.\n");
    }
}

int main() {

    int i, j;
    int choice;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Number of Resource Types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");

    for(i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
    }

    calculateNeed();

    do {

        printf("\n=======================");
        printf("\n1. Safety Algorithm");
        printf("\n2. Resource Request");
        printf("\n3. Exit");
        printf("\n=======================");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                safetyAlgorithm();
                break;

            case 2:
                resourceRequest();
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid Choice\n");
        }

    } while(choice != 3);

    return 0;
}
