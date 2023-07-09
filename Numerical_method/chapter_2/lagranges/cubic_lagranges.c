//finding the value of y(x) by using lagrange's Cubic interpolation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a, n, num;
    float x_value;
    float f_x=0, l_x0=0, l_x1=0, l_x2=0, l_x3=0;

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
        if(x_value<x[2])
        {
            
            a=3;
        }
        else if(x_value==x[i] ||x_value<x[i])
        {
            a=i;
            break;
        }
    }

    printf("\na=%d\n", a);
    //formulas to find the values of l_x0, l_x1 and l_x2
    l_x0 = ((x_value-x[a-2])/(x[a-3]-x[a-2])) * ((x_value-x[a-1])/(x[a-3]-x[a-2])) * ((x_value-x[a])/(x[a-3]-x[a]));
    l_x1 = ((x_value-x[a-3])/(x[a-2]-x[a-3])) * ((x_value-x[a-1])/(x[a-2]-x[a-1])) * ((x_value-x[a])/(x[a-2]-x[a]));
    l_x2 = ((x_value-x[a-3])/(x[a-1]-x[a-3])) * ((x_value-x[a-2])/(x[a-1]-x[a-2])) * ((x_value-x[a])/(x[a-1]-x[a]));
    l_x3 = ((x_value-x[a-3])/(x[a]-x[a-3])) * ((x_value-x[a-2])/(x[a]-x[a-2])) * ((x_value-x[a-1])/(x[a]-x[a-1]));

    //finding the value of y(x) or f(x) at x=taken from users
    f_x = y[a-3]*l_x0 + y[a-2]*l_x1 + y[a-1]*l_x2 + y[a]*l_x3;

    //printing all the necessary values 
    printf("\nHere,\n");
    printf("x0 = %f", x[a-3]);
    printf("\ty(%d) = %f", a-3, y[a-3]);
    printf("\nx1 = %f", x[a-2]);
    printf("\ty(%d) = %f", a-2, y[a-2]);
    printf("\nx = %f", x[a-1]);
    printf("\ty(%d) = %f", a-1, y[a-1]);
     printf("\nx = %f", x[a]);
    printf("\ty(%d) = %f", a, y[a]);
    printf("\nl_x0= %.3f", l_x0);
    printf("\nl_x1= %.3f", l_x1);
    printf("\nl_x2= %.3f", l_x2);
    printf("\nl_x3= %.3f", l_x3);

    //printing the actual mathematical solution fo lagrabges's quadratic interpolation
    printf("\n\nWhen x = %.4f,", x_value);
    printf("\ny(%.2f) = y(%d) X l0(%d) + y(%d) X l0(%d) + y(%d) X l1(%d) + y(%d) X l1(%d)\n", x_value, a-3, a-3, a-2, a-2, a-1, a-1, a, a);
    printf("        = %.3f X %.3f + %.3f X %.3f + %.3f X %.3f + %.3f X %.3f \n", y[a-3], l_x0, y[a-2], l_x1, y[a-1], l_x2, y[a], l_x3);
    printf("        = %.3f\n", f_x);

    printf("\nHence,the value of y(%.3f) is %.4f\n\n", x_value, f_x);

    return 0;
}