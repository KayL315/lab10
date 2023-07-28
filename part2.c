/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void linearProbing(int* table, int value, int size) {
    int key = value % size;
    int i = 1;
    while (table[key] != -1) {
        key = (key + 1) % size;
        i++;
    }
    table[key] = value;
}

void quadraticProbing(int* table, int value, int size) {
    int key = value % size;
    int i = 1;
    while (table[key] != -1) {
        key = (key + i * i) % size;
        i++;
    }
    table[key] = value;
}

// double hashing
void doubleHashing(int* table, int value, int size) {
    int h1 = value % size;
    int h2 = 7 - (value % 7);
    int key = h1;
    int i = 0;
    while (table[key] != -1) {
        key = (h1 + i * h2) % size;
        i++;
    }
    table[key] = value;
}

int main() {
    int probeSize, numValues, probeType;
    printf("Enter the probe size: ");
    scanf("%d", &probeSize);

    int* probeTable = (int*)malloc(probeSize * sizeof(int));
    for (int i = 0; i < probeSize; i++) {
        probeTable[i] = -1; 
    }

    printf("Enter the number of values: ");
    scanf("%d", &numValues);

    printf("Choose the type (1 - Linear Probing, 2 - Quadratic Probing, 3 - Double Hashing): ");
    scanf("%d", &probeType);

    printf("Enter %d values:\n", numValues);
    for (int i = 0; i < numValues; i++) {
        int value;
        scanf("%d", &value);

        switch (probeType) {
            case 1:
                linearProbing(probeTable, value, probeSize);
                break;
            case 2:
                quadraticProbing(probeTable, value, probeSize);
                break;
            case 3:
                doubleHashing(probeTable, value, probeSize);
                break;
            default:
                printf("Invalid probing type\n");
                break;
        }
    }

    printf("The table using ");
    switch (probeType) {
        case 1:
            printf("Linear Probing");
            break;
        case 2:
            printf("Quadratic Probing");
            break;
        case 3:
            printf("Double Hashing");
            break;
        default:
            printf("Wrong type");
            break;
    }
    printf(":\n");

    for (int i = 0; i < probeSize; i++) {
        printf("Slot[%d] -> %d\n", i, probeTable[i]);
    }

    // Free the memory
    free(probeTable);

    return 0;
}

