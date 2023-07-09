#include <stdio.h>

int main() {
    float a0, a1, a2;
    
    // Prompt the user to enter the equations
    // printf("Enter the first equation (in the form of 'x + y = c'): \n");
    // float x1, y1, z1, c1;
    // scanf("%f", &x1);
    // scanf("%f", &y1);
    // scanf("%f", &z1);
    // scanf("%f", &c1);
    
    // printf("Enter the second equation (in the form of 'x + y = c'): \n");
    // float x2, y2, z2, c2;
    // scanf("%f", &x2);
    // scanf("%f", &y2);
    // scanf("%f", &z2);
    // scanf("%f", &c2);

    // printf("Enter the third equation (in the form of 'x + y = c'): \n");
    // float x3, y3, z3, c3;
    // scanf("%f", &x3);
    // scanf("%f", &y3);
    // scanf("%f", &z3);
    // scanf("%f", &c3);
    
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
    
    // a2 = (c3-x3*((c1-(y1*a1)-(z1*z1*a2))/x1) - y3*(((c2-x2*((((c1-y1*a1)-(z1*z1*a2))/x1)-(z2*z2*a2)))/y2)))/(z3*z3);
    // a1 = (c2-x2*((((c1-y1*a1)-(z1*z1*a2))/x1)-(z2*z2*a2)))/y2;
    // a0 = (c1-(y1*a1)-(z1*z1*a2))/x1;


    float x1=1, y1=10, z1=100, c1=227.04;
    float x2=1, y2=15, z2=225, c2=362.78;
    float x3=1, y3=20, z3=400, c3=517.35;
    a2 = (c3*(y2-y1)-c1*(y2-y1)+y1*(c2-c1)-y3*(c2-c1))/(y3*(z1*z1-z2*z2)+z2*z2*(y2-y1)-z1*z1*(y2-y1)-y1*(z1*z1-z2*z2));
    a1 = (c2-c1+a2*(z1*z1-z2*z2))/(y2-y1);
    a0 = c1-y1*a1-z1*z1*a2;

    

    printf("a0 = %f\n", a0);
    printf("a1 = %f\n", a1);
    printf("a2 = %f\n", a2);
    
    float x= 16;
    float vx = a0+a1*x+a2*x*x;
    printf("\nvelocity at x=%f is %f\n\n", x, vx);

    

    return 0;
}
