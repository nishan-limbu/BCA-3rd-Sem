#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, h, sum_of_3=0, total_sum=0, rem, I=0;
    int i, size;
    float first_term;

    printf("Enter starting number (a):");
    scanf("%f", &a);
    printf("Enter ending number (b):");
    scanf("%f", &b);

    printf("Enter the size (n):");
    scanf("%d", &size);

    float x[size], y[size];

    //finding the difference or h:
    h = (b-a)/size;

    for(i=a; i<=(size+1); i++)
    {
        x[i] = i*h+h;
        y[i] = x[i]*x[i]*x[i]+1;
    }
    printf("\nThe values of x and y are given below:\n");
    for(i=a; i<=(size+1); i++)
    {
        printf("x[%d] = %.4f\t", i, x[i]);
        printf("y[%d] = %.4f\n", i, y[i]);

    }


    for(i=a; i<=(size+1); i++)
    {
        if((i != a && i!=(a+1)) && i/3 ==0)
        {
            sum_of_3 += y[i]; //finding the sum of multiple of 3
            
        }
        total_sum += y[i];

    }
    // printf("\nSum of multiple of 3: %.4f", sum_of_3);
    // printf("\ntotal sum = %.4f", total_sum);

    
    int first = a; //assigning value of a whose data type is float into first as an integer
    int last = b; ////assigning value of b whose data type is float into last as an integer
    // printf("a=%d\tb=%d", first, last+1);
    rem = (total_sum - (sum_of_3 + y[first]+y[last+1])); //finding the sum of remaining


    I = 3*h*((y[first]+y[last+1])+2* sum_of_3+3*rem) / 8;
    
    printf("\nI = 3 * h * ((y0 + yn])+2 * sum_of_3 + 3 * rem) / 8")
    printf("\nI = %.4f\n\n", I);
    printf("\n");

    return 0;
}