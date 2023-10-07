#include <stdio.h>
#include <math.h>

double equation(double first_num, double second_num, char operator); // Change the return type

int main()
{
    double first_num;
    double second_num;
    char operator;
    double sum;

    printf("\t\t\tWelcome to my Calculator App\n\n");
    printf("Enter First Number: ");
    scanf("%lf", &first_num);

    printf("Enter Operator (+, -, /, *, s): ");
    scanf(" %c", &operator); // Note the space before %c to consume any leading whitespace

    // Use a do-while loop to ensure a valid operator is entered
    while (operator!= '+' && operator!= '-' && operator!= '/' && operator!= '*' && operator!= 's')
    {
        printf("Please enter a correct operator! (+, -, /, *, s): ");
        scanf(" %c", &operator);
    }

    if (operator== 's')
    {
        // Square root operation only requires one input
        sum = equation(first_num, 0, operator); // Remove the NULL argument
    }
    else
    {
        printf("Enter Second Number: ");
        scanf("%lf", &second_num);

        sum = equation(first_num, second_num, operator); // Remove the NULL argument
    }

    printf("Result: %.2lf\n", sum);

    return 0;
}

double equation(double first_num, double second_num, char operator) // Change the return type
{
    switch (operator)
    {
    case '+':
        return first_num + second_num;
    case '-':
        return first_num - second_num;
    case '/':
        if (second_num != 0) // Check for division by zero
            return first_num / second_num;
        else
        {
            printf("Error: Division by zero\n");
            return 0.0; // Return a default value (you can choose another value if needed)
        }
    case '*':
        return first_num * second_num;
    case 's':
        return sqrt(first_num);
    default:
        printf("Invalid operator\n");
        return 0.0; // Return a default value for invalid operator
    }
}
