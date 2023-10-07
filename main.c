#include <stdio.h>

void equation(double first_num, double second_num, char operator, double * result);

int main()
{
    double first_num;
    double second_num;
    char operator;
    double sum;

    printf("\t\t\tWelcome to my Calculator App\n\n");
    printf("Enter First Number: ");
    scanf("%lf", &first_num);

    printf("Enter Operator (+, -, /, *): ");
    scanf(" %c", &operator); // Note the space before %c to consume any leading whitespace

    // Use a do-while loop to ensure a valid operator is entered
    while (operator!= '+' && operator!= '-' && operator!= '/' && operator!= '*')
    {
        printf("Please enter a correct operator! (+, -, /, *): ");
        scanf(" %c", &operator);
    }

    printf("Enter Second Number: ");
    scanf("%lf", &second_num);

    equation(first_num, second_num, operator, & sum);

    printf("Result: %.2lf\n", sum);

    return 0;
}

void equation(double first_num, double second_num, char operator, double * result)
{
    switch (operator)
    {
    case '+':
        *result = first_num + second_num;
        break;
    case '-':
        *result = first_num - second_num;
        break;
    case '/':
        if (second_num != 0) // Check for division by zero
            *result = first_num / second_num;
        else
            printf("Error: Division by zero\n");
        break;
    case '*':
        *result = first_num * second_num;
        break;
    default:
        printf("Invalid operator\n");
        break;
    }
}
