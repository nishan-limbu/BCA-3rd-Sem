//c-program that demonstrate the romberg integraion

#include<stdio.h>
#include<math.h>

float integration_one(float, float, float, float, float x[10], float y[10]);
float new_integration(float, float);

int main()
{
    float a, b, h=0;
    int i;
    float x[10], y[10];

    printf("Enter starting number (a):\n");
    scanf("%f", &a);
    printf("Enter ending number (b):\n");
    scanf("%f", &b);

    //finding the difference (h) for (I1)
    int size1 = 2;
    float I1, rem1;;

    h = (b-a)/2;

    for(i=a; i<=(size1+1); i++)
    {
        x[i] = i*h;
        // y[i] = sqrt(1+i*i);
        y[i] = 1/(1+x[i]);

    }
    
    printf("\nThe values of x and y are given below:\n");
    for(i=a; i<=(size1); i++)
    {
        printf("x[%d] = %.4f\t", i, x[i]);
        printf("y[%d] = %.4f\n", i, y[i]);

    }

    I1 = integration_one(a, h, b, size1, x, y);
    printf("\nBy using trapezoidal rule, we get");
    printf("\nI1 = h [(y0+yn) + 2*(Sum of remaining y(x)] / 2\nI1 = %.4f", I1);


    //finding the difference (h) for (I2)
    int size2 = 4;
    float I2, rem2;

    h = (b-a)/4;

    for(i=a; i<=(size2+1); i++)
    {
        x[i] = i*h;
        // y[i] = sqrt(1+i*i);
        y[i] = 1/(1+x[i]);

    }
    
    printf("\nThe values of x and y are given below:\n");
    for(i=a; i<=(size2); i++)
    {
        printf("x[%d] = %.4f\t", i, x[i]);
        printf("y[%d] = %.4f\n", i, y[i]);

    }

    I2 = integration_one(a, h, b, size2, x, y);
    printf("\nBy using trapezoidal rule, we get");
    printf("\nI2 = h [(y0+yn) + 2*(Sum of remaining y(x)] / 2\nI2 = %.4f", I2);

    //finding the difference (h) for (I2)
    int size3 = 8;
    float I3, rem3;

    h = (b-a)/size3;

    for(i=a; i<=(size3+1); i++)
    {
        x[i] = i*h;
        // y[i] = sqrt(1+i*i);
        y[i] = 1/(1+x[i]);

    }
    
    printf("\nThe values of x and y are given below:\n");
    for(i=a; i<=(size3); i++)
    {
        printf("x[%d] = %.4f\t", i, x[i]);
        printf("y[%d] = %.4f\n", i, y[i]);

    }

    I3 = integration_one(a, h, b, size3, x, y);
    printf("\nBy using trapezoidal rule, we get");
    printf("\nI3 = h [(y0+yn) + 2*(Sum of remaining y(x)] / 2\nI3 = %.4f", I3);

    //finding (I1)new and (I2)new
    float I1_new = new_integration(I1, I2);
    float I2_new = new_integration(I2, I3);
    float I3_new = new_integration(I1_new, I2_new);


    printf("\n\nHence, \nI1_new = %.4f\nI2_new = %.4f\nI3_new = %.4f\n\n", I1_new, I2_new, I3_new);

    return 0;
}

float integration_one(float a, float h, float b, float size, float x[10], float y[10])
{
    float I;
    int i;
    float rem;

    //formula to find I using trapezoidal rule:
    //finding the total sum of all remaining
    for(i=a+1; i<size;i++)
    {
        rem +=  y[i];
    }
    
    // printf("\nrem = %.4f", rem);
    int first=a;
    int last = b;
    I = h*((y[first]+y[last])+2*rem)/2;
    return I;
    
}
float new_integration(float I1, float I2)
{
    float I_new = (4*I2 - I1)/3;
    return I_new;
}