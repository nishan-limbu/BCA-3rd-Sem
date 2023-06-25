//finding the value of y(x) by using Newton Divided Difference of Linear Interpolation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a, n, num;
    float x_value;
    float y_x=0, b0=0, b1=0;

    //taking total number, value of x and y as well as the value of x to find the f(x) as inputs from the users
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
        if(x_value==x[i] || x_value<x[i])
        {
            a=i;
            break;
        }
    }

    //value of a is 2
    b0 = y[a];
    b1 = (y[a+1] - y[a]) / (x[a+1]-x[a]);
    y_x = b0 + b1 * (x_value-x[a]);

    printf("\nWe know that,\n\ty(x) = b0 + b1 X (x-x0)");
    printf("\nHere,\nx0 = %f\tx1 = %f\nb0 = y(x0) = y[%f] = %f", x[a], x[a+1], x[a], y[a+1]);
    printf("\nHere,\nb1 = (y(x1) - y(x0)) / (x1-x0) \n  = (y(%f) - y(%f)) / (%f-%f) \n  = y[%f] = %f", x[a+1], x[a], x[a+1], x[a], x[a], y[a+1]);

    printf("\nHence, the value of y at x=%f is %f.\n\n", x_value, y_x);

    return 0;
}