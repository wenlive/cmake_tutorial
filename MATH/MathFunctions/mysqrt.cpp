#include "MathFunctions.h"
#include <stdio.h>
#include "TutorialConfig.h"

#if defined HAVE_LOG && defined (HAVE_EXP)
#include <math.h>
#endif

double mysqrt(double x){
    fprintf(stdout,"using mysqrt");
    double result;
    
    // if we have both log and exp then use them
#if defined (HAVE_LOG) && defined (HAVE_EXP)
    result = exp(log(x)*0.5);
    fprintf(stdout,"using exp and log as sqrt");
#else // otherwise use an iterative approach
    result = x;
    // use the table to help find an initial value
    if (x >= 1 && x < 10) {
        result = sqrtTable[static_cast<int>(x)];
    }

    // 10次迭代
    for (int i = 0; i < 10; ++i) {
        result = 0.5 * (result + x / result);
        fprintf(stdout, "Computing sqrt of %g to be %g\n", x, result);
    }
#endif
    return result;
}