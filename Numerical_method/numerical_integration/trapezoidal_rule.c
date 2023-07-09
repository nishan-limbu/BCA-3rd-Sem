//c program of finding the value of given integral using trapezoidal rule.
#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, h, rem=0, I=0;
    int i, size;
    float x[50], y[50];

    printf("Enter starting number (a):\n");
    scanf("%f", &a);
    printf("Enter ending number (b):\n");
    scanf("%f", &b);

    printf("Enter the size (n):\n");
    scanf("%d", &size);

    //finding the difference or h:
    h = (b-a)/size;

    for(i=a; i<=(size+1); i++)
    {
        x[i] = i*h;
        // y[i] = sqrt(1+i*i);
        y[i] = sqrt(1+x[i]*x[i]);

    }
    
    printf("\nThe values of x and y are given below:\n");
    for(i=a; i<=(size+1); i++)
    {
        printf("x[%d] = %.4f\t", i, x[i]);
        printf("y[%d] = %.4f\n", i, y[i]);

    }

    //formula to find I using trapezoidal rule:

    //finding the total sum of all remaining
    for(i=a+1; i<=size;i++)
    {
        rem +=  y[i];
    }
    // printf("\nrem = %.4f", rem);
    int first=a;
    int last = b;
    I = h*((y[first]+y[last])+2*rem)/2;
    printf("\nBy using trapezoidal rule, we get");
    printf("\nI = h [(y0+yn) + 2*(Sum of remaining y(x)] / 2\nI = %.4f", I);
    printf("\n\nHence, the value of given integral is %.4f.\n\n", I);

    return 0;
}