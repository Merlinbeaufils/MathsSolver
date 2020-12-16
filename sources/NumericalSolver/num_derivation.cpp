#include "num_derivation.hpp"


double derivative(double f(double), double a){
    // numerical value of the derivative at point a
    return ((f(a+1e-10)-f(a-1e-10))/(2e-10) * 100000.0)/100000.0;
};
