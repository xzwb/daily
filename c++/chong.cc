#include <iostream>
#include <string>

/* double Try(double a, double b) 
{
    return a > b ? a : b;
}

float Try(float a, float b)
{
    return a > b ? b : a;
} */

float Try(float a, float b)
{
    return a > b ? b : a;
}

double Try(double a, double b) 
{
    return a > b ? a : b;
}


int main()
{
    std::cout << Try(1.0, 2.0) << std::endl;
}

/**
 *  结论:重载函数时如果有小数被看成double；
 */
