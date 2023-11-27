
#include "../headers/libft.h"

double  generate_random(double min, double max)
{
    double random;

    random = (double)rand() / RAND_MAX;
    return (min + random * (max - min));
}