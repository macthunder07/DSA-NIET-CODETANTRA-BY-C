#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert node into linked list in descending order of exponent
struct Node* insertTerm(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->exp >= exp) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Display polynomial
void displayPoly(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    while (a != NULL && b != NULL) {
        if (a->exp > b->exp) {
            result = insertTerm(result, a->coeff, a->exp);
            a = a->next;
        } else if (a->exp < b->exp) {
            result = insertTerm(result, b->coeff, b->exp);
            b = b->next;
        } else {
            // Same exponent
            int sumCoeff = a->coeff + b->coeff;
            result = insertTerm(result, sumCoeff, a->exp);
            a = a->next;
            b = b->next;
        }
    }

    // Remaining terms
    while (a != NULL) {
        result = insertTerm(result, a->coeff, a->exp);
        a = a->next;
    }

    while (b != NULL) {
        result = insertTerm(result, b->coeff, b->exp);
        b = b->next;
    }

    return result;
}

int main() {
    int numTerms1, numTerms2;
    scanf("%d", &numTerms1);

    struct Node* poly1 = NULL;
    for (int i = 0; i < numTerms1; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        poly1 = insertTerm(poly1, coeff, exp);
    }

    scanf("%d", &numTerms2);
    struct Node* poly2 = NULL;
    for (int i = 0; i < numTerms2; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        poly2 = insertTerm(poly2, coeff, exp);
    }

    // Display input polynomials
    displayPoly(poly1);
    displayPoly(poly2);

    // Add polynomials
    struct Node* sumPoly = addPoly(poly1, poly2);
    displayPoly(sumPoly);

    return 0;
}
