//c program of finding the value of given integral using simpson's 1/3 rule.
#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, h, odd, even, I=0;
    int i, size;

    printf("Enter starting number (a):\n");
    scanf("%f", &a);
    printf("Enter ending number (b):\n");
    scanf("%f", &b);

    printf("Enter the size (n):\n");
    scanf("%d", &size);

    float x[size], y[size];

    //finding the difference or h:
    h = (b-a)/size;

    for(i=a; i<=(size+1); i++)
    {
        x[i] = i*h;
        y[i] = sqrt(x[i]*x[i]+1);
    }
    
    for(i=a; i<=(size+1); i++)
    {
        printf("x[%d] = %.4f\t", i, x[i]);
        printf("y[%d] = %.4f\n", i, y[i]);

    }

    printf("\nThe values of x and y are given below:\n");
    for(i=0; i< size;i++)
    {
        if(2*i+1 <= size)
        {
            odd +=  y[2*i+1];
            printf("\nodd = y[%d]=%.4f",2*i+1, y[2*i+1]);

        }
        if((i!=0)&&(2*i <= size))
        {
            even += y[2*i];
            printf("\neven= y[%d] =%.4f", 2*i, y[2*i] );
        }
    }
    int first = a;
    int last = b;
    printf("\nsum_of_odd = %.4f\tsum_of_even = %.4f", odd, even);

    printf("\nI = h[(y0+yn) + 4 * Sum of odd) + 2 * Sum of even)s] /3");
    
    I = h*((y[first]+y[last])+4*odd+2*even)/3;
    printf("\nI = %.4f\n", I);
    printf("\n");


    return 0;
}