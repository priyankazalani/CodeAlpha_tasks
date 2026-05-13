#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;

        printf("\nEnter first number  : ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number : ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            if (num2 == 0) {
                printf("\nError: Division by zero is not allowed!\n");
            } else {
                result = num1 / num2;
                printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;

        default:
            printf("\nError: Invalid operator! Use +, -, *, or /\n");
    }

    return 0;
}

