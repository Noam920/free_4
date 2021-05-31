#include <stdio.h>

//Solution with a switch-statement - <opCode>
// specifies which operation to execute
float add(float a, float b) {
    return (a + b);
}

float sub(float a, float b) {
    return (a - b);
}

float div(float a, float b) {
    if (b != 0) {
        return (a / b);
    }
    return -1;
}

float mult(float a, float b) {
    return (a * b);
}

void Switch_With_Function_Pointer(float a, float b, float (*ptr2Func)(float, float)) {
    float result = ptr2Func(a, b); // call using function pointer
    printf("the results is: %f\n", result);

}

void Switch(float a, float b, char opCode) {
    float result;
// execute operation
    switch (opCode) {
        case '+' :
            result = add(a, b);
            break;
        case '-' :
            result = sub(a, b);
            break;
        case '*' :
            result = mult(a, b);
            break;
        case '/' :
            result = div(a, b);
            break;
    }
    printf("the results is: %f\n", result);
}

void operation(float (*fptr)(float, float)) {
    float x = 5.0, y = 2.0;
    printf("%f \n", fptr(x, y));
}

int main() {


//        Switch(2, 5, '+');
/* pointer to function 'add' */
//        Switch_With_Function_Pointer(2, 5, &add);
    operation(&add);
    operation(&sub);
    operation(&mult);
    operation(&div);
    return 0;
}
