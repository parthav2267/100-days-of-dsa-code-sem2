#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Term {
    int coeff;      
    int exp;        
    struct Term* next;
};
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}
void insertTerm(struct Term** poly, int coeff, int exp) {
    if (coeff == 0) return;  
    
    struct Term* newTerm = createTerm(coeff, exp);
        if (*poly == NULL || exp > (*poly)->exp) {
        newTerm->next = *poly;
        *poly = newTerm;
        return;
    }
        struct Term* current = *poly;
    struct Term* prev = NULL;
    
    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }
        if (current != NULL && current->exp == exp) {
        current->coeff += coeff;
        free(newTerm);
                if (current->coeff == 0) {
            if (prev == NULL) {
                *poly = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
        return;
    }
        newTerm->next = current;
    if (prev == NULL) {
        *poly = newTerm;
    } else {
        prev->next = newTerm;
    }
}
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    struct Term* current = poly;
    int firstTerm = 1;
    
    while (current != NULL) {
        if (current->coeff > 0 && !firstTerm) {
            printf(" + ");
        } else if (current->coeff < 0) {
            printf(" - ");
        }
                int absCoeff = abs(current->coeff);
        if (absCoeff != 1 || current->exp == 0) {
            printf("%d", absCoeff);
        } else if (absCoeff == 1 && current->exp > 0) {
        }
                if (current->exp > 0) {
            printf("x");
            if (current->exp > 1) {
                printf("^%d", current->exp);
            }
        }
        
        firstTerm = 0;
        current = current->next;
    }
    printf("\n");
}
int evaluatePolynomial(struct Term* poly, int x) {
    int result = 0;
    struct Term* current = poly;
    
    while (current != NULL) {
        result += current->coeff * pow(x, current->exp);
        current = current->next;
    }
    
    return result;
}
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* p1 = poly1;
    struct Term* p2 = poly2;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
        while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    
    return result;
}
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* p1 = poly1;
    
    while (p1 != NULL) {
        struct Term* p2 = poly2;
        while (p2 != NULL) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            insertTerm(&result, coeff, exp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    
    return result;
}
void freePolynomial(struct Term** poly) {
    struct Term* current = *poly;
    struct Term* temp;
    
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    
    *poly = NULL;
}
struct Term* readPolynomial() {
    struct Term* poly = NULL;
    int n, coeff, exp;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    
    return poly;
}

int main() {
    struct Term* poly = NULL;
    int n, coeff, exp;
        scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
        displayPolynomial(poly);
        printf("\n--- Additional Operations ---\n");
        int x = 2;
    int value = evaluatePolynomial(poly, x);
    printf("P(%d) = %d\n", x, value);
        freePolynomial(&poly);
    
    return 0;
}
