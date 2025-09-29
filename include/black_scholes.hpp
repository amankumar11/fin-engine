#ifndef BLACK_SCHOLES_HPP
#define BLACK_SCHOLES_HPP

double norm_cdf(double x);
double black_scholes_call(double S, double K, double r, double sigma, double T);
double black_scholes_put(double S, double K, double r, double sigma, double T);

#endif
