#include <stdio.h>

#define MAX 10

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX]; // Global array to store elements
int n, pos; // Global variables for number of elements and position

int main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("\nEnter the correct choice!\n");
        }
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
    return 0;
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    if (n == 0) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }
    printf("\nEnter the position you want to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("\nInvalid position!\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;
    printf("\nThe elements after deletion:\n");
    display();
}

void search() {
    if (n == 0) {
        printf("\nList is empty.\n");
        return;
    }
    int e, found = 0;
    printf("\nEnter the element to search: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Element %d found at position %d.\n", e, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the list.\n", e);
    }
}

void insert() {
    if (n == MAX) {
        printf("\nList is full. Cannot insert.\n");
        return;
    }
    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("\nInvalid position!\n");
        return;
    }
    printf("\nEnter the element to insert: ");
    scanf("%d", &b[pos]);
    n++;
    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    if (n == 0) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nThe elements in the list are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

