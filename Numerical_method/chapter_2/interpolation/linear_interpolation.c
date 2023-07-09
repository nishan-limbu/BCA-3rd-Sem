#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, num;
    
    float t;
    printf("Enter the total number(n):");
    scanf("%d",&n);

    float time[n], velocity[n], diff[n], diff_in_ascending[n];
    
    printf("Enter the time(t):\n");
    for(int i=0; i<n; i++)
    {
        printf("Time[%d]: ",i+1);
        scanf("%f", &time[i]);
    }
    printf("Enter the corresponding velocities (m/s):\n");
    for(int i=0; i<n; i++)
    {
        printf("\nVelocity[%d]: ",i+1);
        scanf("%f", &velocity[i]);
    }

    printf("Enter the time (t) to find the velocity: \n");
    scanf("%f", &t);

    printf("Enter the points (num): \n");
    scanf("%d", &num);

    for(int i=0;i<n;i++)
    {
        diff[i] = fabs(t-time[i]);
        diff_in_ascending[i] = diff[i];
        // printf("diff[%d] = %f", i, diff[i]);
    }

    for(int j=0; j<n; j++)
    {
        for(int k=j+1; k<n; k++)
        {
            if(diff_in_ascending[j] > diff[k])
            {
                float temp = diff_in_ascending[j];
                diff_in_ascending[j] = diff_in_ascending[k];
                diff_in_ascending[k] = temp;
            }
        }
    }

    // printf("\nAscending order: \n");
    // for(int i=0;i<n;i++)
    // {
    //     printf("\ndiff_in_ascending[%d] = %f\n", i, diff_in_ascending[i]);
    // }

    int a, b;
    for(int i=0;i<num;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(diff_in_ascending[i] == diff[j])
            {
                
                printf("diff[%d]= %f\tand\tvelocity[%d]=%f\n", j, time[j], j, velocity[j]);             
            }

        }
    }
    
    float a1 = (velocity[1]*1-1*velocity[0])/(1*time[1]-1*time[0]);
    float a0 = (velocity[0]-time[0]*a1)/1.00;

    printf("a0 = %f\n", a0);
    printf("a1 = %f\n", a1);
    
    float x= 0.95;
    float vx = a0+a1*x;
    printf("\nvelocity at x=16 is %f\n\n", vx);

     return 0;
}