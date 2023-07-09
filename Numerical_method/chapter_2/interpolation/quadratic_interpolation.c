#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i, n, v, num;
    
    float t;
    printf("Enter the total number(n):");
    scanf("%d",&n);

    float time[n], velocity[n];
    
    printf("Enter the time(t):\n");
    for(i=0; i<n; i++)
    {
        printf("Time[%d]: ",i);
        scanf("%f", &time[i]);
    }
    printf("Enter the corresponding velocities (m/s):\n");
    for(i=0; i<n; i++)
    {
        printf("\nVelocity[%d]: ",i);
        scanf("%f", &velocity[i]);
    }

    printf("Enter the time (t) to find the velocity: \n");
    scanf("%f", &t);

    
	//finding the greatest value among x and y when x = taken from user
    for(i=0;i<n;i++)
    {
        if(t==time[i] || t<time[i])
        {
            v=i;
            break;
        }
    }
    printf("v=%d ", v);
    int x = v-1;
    int y = v;
    int z = v+1;
    printf("x=%d,y=%d,z=%d", x,y,z);
	printf("\nThree nearest points are a=%f   b=%f    c=%f", time[x], time[y], time[z]);
  	float a = time[x];
  	float b = time[y];
  	float c = time[z];
	  
	float a2 = (b*velocity[z]-a*velocity[z]-b*velocity[x]+a*velocity[x]-c*velocity[y]+c*velocity[x])+(a*b*velocity[y]-a*b*velocity[x]-a*a*velocity[y]+a*a*velocity[x])/(b-a);
	float a1 = (velocity[y]-velocity[x]+a*a*a2-b*b*a2)/(b-1);
	float a0 = velocity[x]-a*a1-a*a*a2;
	printf("\n\na2 = %f", a2);
	printf("a1 = %f", a1);
	printf("a0 = %f", a0);
	float f_x = a0+a1*t+a2*t*t;
	printf("f_x = %f", f_x);

    return 0;
}


