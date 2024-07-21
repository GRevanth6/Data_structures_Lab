#include <stdio.h>

// Define the structure for polynomial
struct poly {
    int coeff;  // Coefficient of the polynomial term
    int expo;   // Exponent of the polynomial term
};

// Function prototypes
int readPoly(struct poly p[]);
int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]);
void displayPoly(struct poly p[], int terms);

int main() {
    struct poly p1[10], p2[10], p3[20]; // Increased size of p3 to accommodate all terms
    int t1, t2, t3;

    // Read and display first polynomial
    t1 = readPoly(p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1, t1);

    // Read and display second polynomial
    t2 = readPoly(p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2, t2);

    // Add two polynomials and display resultant polynomial
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition: ");
    displayPoly(p3, t3);
    printf("\n");

    return 0;
}

int readPoly(struct poly p[]) {
    int t, i;
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &t);

    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the Exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return t;
}

int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
        }
        k++;
    }

    // For remaining terms in p1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // For remaining terms in p2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k; // Number of terms in resultant polynomial
}

void displayPoly(struct poly p[], int terms) {
    int i;

    if (terms == 0) {
        printf("0");
        return;
    }

    for (i = 0; i < terms - 1; i++) {
        if (p[i].coeff != 0) {
            printf("%d(x^%d) + ", p[i].coeff, p[i].expo);
        }
    }

    if (p[terms - 1].coeff != 0) {
        printf("%d(x^%d)", p[terms - 1].coeff, p[terms - 1].expo);
    }
}

