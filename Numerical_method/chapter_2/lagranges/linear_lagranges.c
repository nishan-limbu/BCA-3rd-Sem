//finding the value of y(x) by using Lagrange's Quadratic Interpolation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a, n, num;
    float x_value;

    //taking all the necessary inputs from the users
    printf("Enter the total number(n):");
    scanf("%d",&n);

    float x[n], y[n];
    
    printf("Enter the value of X (X):\n");
    for(int i=0; i<n; i++)
    {
        printf("X-[%d]: ",i);
        scanf("%f", &x[i]);
    }
    printf("\nEnter the corresponding values of Y (Y):\n");
    for(int i=0; i<n; i++)
    {
        printf("Y-[%d]: ",i);
        scanf("%f", &y[i]);
    }

    printf("\nEnter X to find the function f(x): ");
    scanf("%f", &x_value);


    //finding the greatest value among x and y when x = taken from user
    for(int i=0;i<n;i++)
    {
        if(x_value==x[i] ||x_value<x[i])
        {
            a=i;
            break;
        }
    }

    //formulas to find the values of l_x0, l_x1, l_x2 and f_x
    float l_x0 = (x_value-x[a-1])/(x[a]-x[a-1]);
    float l_x1 = (x_value-x[a])/(x[a-1]-x[a]);
    float f_x = y[a-1]*l_x0 + y[a]*l_x1;

    //printing the actual mathematical solution to find the value of f(x) 
    printf("\n\nWhen x = %.4f,", x_value);
    printf("\ny(%.2f) = y(%d)Xl0(%d) + y(%d)Xl1(%d)\n", x_value, a-1, a-1, a, a);
    printf("        = %.3f X %.3f + %.3f X %.3f \n", y[a-1], l_x0, y[a], l_x1);
    printf("        = %.3f\n", f_x);

    printf("\nHence,the value of y(%.3f) is %.4f\n\n", x_value, f_x);

    return 0;
}