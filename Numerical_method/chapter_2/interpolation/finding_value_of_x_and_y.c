#include <stdio.h>

int main() {
    float a0, a1;
    
    // Prompt the user to enter the equations
    printf("Enter the first equation (in the form of 'x + y = c'): ");
    float x1, y1, c1;
    scanf("%f", &x1);
    scanf("%f", &y1);
    scanf("%f", &c1);
    
    printf("Enter the second equation (in the form of 'x + y = c'): ");
    float x2, y2, c2;
    scanf("%f", &x2);
    scanf("%f", &y2);
    scanf("%f", &c2);
    
    // Solving the equations using substitution method
    
    // Solving Equation 1 for x
    // x = (c1 - y) / a1
    
    // Substituting x in Equation 2
    // (c1 - y) / a1 + y = c2
    // (c1 - y) + a1 * y = c2 * a1
    // c1 - y + a1 * y = c2 * a1
    // c1 = (c2 * a1) + (a1-1) * y
    // y = (c1 - c2 * a1) / (a1-1)
    
    // y = (c1 - c2 * a1) / (a1-1);
    // x = (c1 - y) / a1;
    
    a1 = (c2*x1-x2*c1)/(x1*y2-x2*y1);
    a0 = (c1-y1*a1)/x1;

    printf("a0 = %f\n", a0);
    printf("a1 = %f\n", a1);
    
    float x= 16;
    float vx = a0+a1*x;
    printf("\nvelocity at x=16 is %f\n\n", vx);
    return 0;
}
