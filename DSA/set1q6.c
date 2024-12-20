#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void sum(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    reverse(num1);
    reverse(num2);

    int carry = 0;
    int i = 0;

    while (i < len1 || i < len2 || carry) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;

        i++;
    }

    result[i] = '\0';

    reverse(result);
}

int main() {
    char num1[1000], num2[1000], result[1001]; 

    printf("Enter the first large number: ");
    scanf("%s", num1);

    printf("Enter the second large number: ");
    scanf("%s", num2);

    sum(num1, num2, result);

    printf("The sum of the two large numbers is: %s\n", result);

    return 0;
}
