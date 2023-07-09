//finding the value of y(x) by using Newton Divided Difference of Quadratic Interpolation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a, n, num;
    float x_value;
    float y_x=0, b0=0, b1=0, b2=0;

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
    
    //value of a is 3
    b0 = y[a-2];
    b1 = (y[a-1] - y[a-2]) / (x[a-1]-x[a-2]);
    b2 = (((y[a]-y[a-1])/(x[a]-x[a-1])) - ((y[a-1]-y[a-2])/(x[a-1]-x[a-2]))) / (x[a]-x[a-2]);
    y_x = b0 + b1 * (x_value-x[a-2]) + b2 * (x_value-x[a-2]) * (x_value-x[a-1]) ;

    printf("\nWe know that,\n\ty(x) = b0 + b1 X (x-x0) + b2 X (x-x0)(x-x1)");
    printf("\nHere,\nx0 = %f\tx1 = %f\tx2 = %f\nb0 = y(x0) = y[%f] = %f", x[a-2], x[a-1], x[a], x[a-2], y[a-2]);
    printf("\nb1 =  %f", b1);
    printf("\nb2 =  %f", b2);

    printf("\nHence, the value of y at x=%f is %f.\n\n", x_value, y_x);

    return 0;
}