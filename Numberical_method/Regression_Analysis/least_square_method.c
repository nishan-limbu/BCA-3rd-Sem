#include <stdio.h>

// Function for calculating the coefficients of the best-fit line using the least squares method
void calculateBestFitLine(float x[], float y[], int n, float* slope, float* intercept) {
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // Calculating the required summations
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculating the slope (m) and intercept (c) of the best-fit line
    *slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    *intercept = (sumY - *slope * sumX) / n;
}

int main() {
    float slope, intercept;
    int i, terms;

    // taking values of x and y from the users 
    printf("\nEnter the numbers of terms: \n");
    scanf("%d", &terms);

    float x[terms], y[terms] ;
    int n = sizeof(x) / sizeof(x[0]);

    printf("\nEnter the value of x:\n");
    for(i=0; i<terms; i++)
    {
        printf("[%d] = ", i);
        scanf("%f", &x[i]);
    }
    printf("\nEnter the value of y:\n");
    for(i=0; i<terms; i++)
    {
        printf("[%d] = ", i);
        scanf("%f", &y[i]);
    }
    
    // Calculating the coefficients of the best-fit line
    calculateBestFitLine(x, y, n, &slope, &intercept);

    // Printing the equation of the best-fit line
    printf("\nRegression equation on y on x:");
    printf("\nSum_Y = N x a + b X Sun_X  -------------eqn(i)");
    printf("\nSum_XY = Sum_X x a + b X Sun_(X*X)  -------------eqn(ii)\n");

    printf("\nSolving equations (i) and (ii), we get");
    printf("\n x = %.4f\ty = %.4f", intercept, slope);

    printf("\nTherefore, the required equation of the best-fit line is: y = %.2f + %.2fx\n", intercept, slope);
    
    return 0;
}
