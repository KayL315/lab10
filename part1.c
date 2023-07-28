/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

// create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertChaining(struct Node** table, int value, int size) {
    int key = value % size;
    if (table[key] == NULL) {
        table[key] = createNode(value);
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = table[key];
        table[key] = newNode;
    }
}

void printChaining(struct Node** table, int size) {
    for (int i = 0; i < size; i++) {
        printf("Chain[%d] -> ", i);
        struct Node* currentNode = table[i];
        while (currentNode != NULL) {
            printf("%d -> ", currentNode->value);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int chainSize, numValues;
    printf("Enter the size of chain: ");
    scanf("%d", &chainSize);

    struct Node** chainTable = (struct Node**)malloc(chainSize * sizeof(struct Node*));
    for (int i = 0; i < chainSize; i++) {
        chainTable[i] = NULL;
    }

    printf("Enter the number of values: ");
    scanf("%d", &numValues);

    printf("Enter %d values:\n", numValues);
    for (int i = 0; i < numValues; i++) {
        int value;
        scanf("%d", &value);
        insertChaining(chainTable, value, chainSize);
    }

    printf("The table:\n");
    printChaining(chainTable, chainSize);

    // Free the memory
    for (int i = 0; i < chainSize; i++) {
        struct Node* currentNode = chainTable[i];
        while (currentNode != NULL) {
            struct Node* nextNode = currentNode->next;
            free(currentNode);
            currentNode = nextNode;
        }
    }
    free(chainTable);

    return 0;
}
