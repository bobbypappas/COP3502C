#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

// Definition of Moors's function: f(n) = k / (h^(sqrt(n)))
float fn(float n, int k, int h)
{
    double result, total, sqrtn;

    sqrtn = sqrt(n);
    result = pow(h, sqrtn);
    total = n + (k/result);

    return (float) total;
}
// Utilizes ternary search to find the minimum
float ternarySearch(float min, float max, int k, int h)
{
    float mid1, mid2;
    float fn1, fn2;
    float midpoint;

    // finds each quadrant
    mid1 = min + ((max - min) / 3);
    mid2 = max - ((max - min) / 3);

    // finding y values at mid1/mid2
    fn1 = fn(mid1, k, h);
    fn2 = fn(mid2, k, h);

    //searches for minimum and breaks out once mid1 == mid2
    while (1)
    {
        if (fn1 < fn2)
        {
            min = mid1;
            mid1 = min + (max - min) / 3;
            fn1 = fn(mid1, k, h);
        }
        else if (fn1 > fn2)
        {
            max = mid2;
            mid2 = max - (max - min) / 3;
            fn2 = fn(mid2, k, h);
        }
        else if (((double) mid1 == (double) mid2))
            break;

    }

    midpoint = max;
    return midpoint;
}

int main()
{
    // Range to search [0, FLT_MAX]
    float min = 0;
    float max = FLT_MAX;
    float h;
    int k, i , j;
    float yearsRequired = 0;

    // Getting iteration values
    scanf("%d", &j);
    for (i = 0; i < j; i++)
    {
        // Getting h and k variables
        scanf("%d", &k);
        scanf("%f", &h);
        yearsRequired = ternarySearch(min, max, k, h);
        printf("%.6f", yearsRequired);
    }

    return 0;
}
