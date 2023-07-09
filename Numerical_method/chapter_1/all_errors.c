/*
    Program to implement Absolute Error, Relative Error and Percent Error 
*/

#include<stdio.h>
#include<stdlib.h>

// global variable declaration
float appro, num;
float absolute, relative, percent;

// funcitions declaration
void absolute_error(float, float);
void relative_error(float, float);
void percent_error(float, float);

int main()
{
    // local variable declaration
    int choose, i=1;

    // showing a menu-driven for different operations
    printf("Menu-driven:\n");
    printf("``````````````````\n");
    printf("1. Absoulte Error\n2. Relative Error\n3. Percent Error\n4. Exit\n");
    printf("\n```````````````````````````````\n");

    while(i<3)
    {
        printf("Choose any option: ");
        scanf("%d", &choose);
        printf("Enter any number (Actual Value): ");
        scanf("%f", &num);
        printf("Enter approximate value of that number (Approximate Value): ");
        scanf("%f", &appro);
        printf("\n```````````````````````````````\n");

        switch(choose)
        {
            case 1:
                absolute_error(num, appro); //calling a absolute_error() function
                break;
            case 2:
                relative_error(num, appro); //calling a relative_error() function
                break;
            case 3:
                percent_error(num, appro); //calling a percent_error() funcion
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option!!!");
                break;
        }
    }
    return 0;
}

// functions definitions
void absolute_error(float num, float appro)
{
    float actual=num;

    absolute = appro-actual;

    if(absolute<0)
    {
        printf("Absolute error = | Approximate value - Absolute value |");
        printf("\nAbsolute error = %f", (-1)*absolute);
        printf("\n```````````````````````````````");
        printf("\n");
    }
    else if(absolute>0)
    {
        printf("Absolute error = | Approximate value - Absolute value |");
        printf("\nAbsolute error = %f", absolute);
        printf("\n```````````````````````````````");
        printf("\n");
    }
}

void relative_error(float num, float appro)
{
    float actual=num;

    relative = (appro-actual)/actual;
    
    if(relative>0)
    {
        printf("Relative error = Absolute Value / Actual Value");
        printf("\nAbsolute error = %f", relative);
        printf("\n```````````````````````````````");
        printf("\n");
    }
    else if(relative<0)
    {
        printf("Relative error = Absolute Value / Actual Value");
        printf("\nAbsolute error = %f", (-1)*relative);
        printf("\n```````````````````````````````");
        printf("\n");
    }
}

void percent_error(float num, float appro)
{  
    float actual=num;

    relative = (appro-actual)/actual;
    
    if(relative<0)
    {
        printf("%f", (-1)*relative);
        printf("Percentage error = (Absolute Value / Actual Value) X 100 percentage");
        printf("Percent error = %f percentage", percent);
        printf("\n```````````````````````````````");
        printf("\n");
    }
    else if(relative>0)
    {
        printf("%f", (-1)*relative);
        printf("Percentage error = (Absolute Value / Actual Value) X 100 percentage");
        printf("Percent error = %f percentage", percent);
        printf("\n```````````````````````````````");
        printf("\n");
    }
}