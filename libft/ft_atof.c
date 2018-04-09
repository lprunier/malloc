#include "libft.h"

double lp_atof(char* num)
 {
     if (!num || !*num)
         return 0; 
     double integerPart = 0;
     double fractionPart = 0;
     int divisorForFraction = 1;
     int sign = 1;
     int inFraction = 0;
     if (*num == '-')
     {
         ++num;
         sign = -1;
     }
     else if (*num == '+')
     {
         ++num;
     }
     while (*num != '\0')
     {
         if (*num >= '0' && *num <= '9')
         {
             if (inFraction)
             {
                 fractionPart = fractionPart*10 + (*num - '0');
                 divisorForFraction *= 10;
             }
             else
             {
                 integerPart = integerPart*10 + (*num - '0');
             }
         }
         else if (*num == '.')
         {
             if (inFraction)
                 return sign * (integerPart + fractionPart/divisorForFraction);
             else
                 inFraction = 1;
         }
         else
         {
             return sign * (integerPart + fractionPart/divisorForFraction);
         }
         ++num;
     }
     return sign * (integerPart + fractionPart/divisorForFraction);
 }