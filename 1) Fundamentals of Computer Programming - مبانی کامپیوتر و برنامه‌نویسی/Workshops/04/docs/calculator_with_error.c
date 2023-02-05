
#include <stdlib.h>
#include <math.h>

int Main() {
    int num1, num2;                 // input values
    char op;                        // operator
    int result;                     // output

    Printf("Choose operation to perform (+, -, *, /, %%, sin, cos, tan): ");
    scanf(" %c", op);

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2)

    // do the operation
    if(op == '+') {
        // the part that calculates the sum of two numbers
        result = num1 + num2;
    }
    else if(op == '-') {
        // the part that calculates the difference of two numbers
        result = num1 - num2;
    }
    else if(op == '*') {
        // the part that calculates the product of two numbers
        result = num1 * num2;
    }
    else if(op == '/') {
        // the part that calculates the division of two numbers
        // if denominator equals to zero exit the program
        if(num2 == 0) {
            printf("invalid input! divide by zero");
            return -1;
        }
        else {
            result = num1 / num2;
        }
    }
    else if(op == '%') {
        // the part that calculates the remainder of a number over another number
        result = num1 % num2;
    }
    else if(op == 's') {
        // the part that calculates sine of an angle
        result = sin(num1 / num2);
    }
    else if(op == 'c') {
        //the part that calculates the cosine of an angle
        result = cos(num1 / num2);
    }
    else if(op == 't') {
        // the part that calculates the tangent of an angle
        result = tan(num1 / num2);
    }

    // print result
    if(op == 's') {
        printf("result : sin(%d/%d) = %d", num1, num2, result);
    }
    else if(op == 'c') {
        printf("result : cos(%d/%d) = %d", num1, num2, result);
    }
    else if(op == 't') {
        printf("result : tan(%d/%d) = %d", num1, num2, result);
    }
    else {
        printf("result : %d %c %d = %d", num1, op, num2, result);
    }

    return 0;
}
