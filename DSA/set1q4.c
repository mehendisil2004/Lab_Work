#include <stdio.h>

// Function to calculate power using Exponentiation by Squaring
int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exponent is odd
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

// Function to evaluate the polynomial
int evaluatePolynomial(int coeff[], int exp[], int n, int x) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += coeff[i] * power(x, exp[i]);
    }
    return result;
}

int main() {
    int n, x;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    int coeff[n], exp[n];

    printf("Enter the coefficients and exponents:\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &coeff[i]);
        printf("Exponent: ");
        scanf("%d", &exp[i]);
    }

    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = evaluatePolynomial(coeff, exp, n, x);

    printf("The value of the polynomial at x = %d is %d\n", x, result);

    return 0;
}
