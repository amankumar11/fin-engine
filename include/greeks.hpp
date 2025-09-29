#ifndef GREEKS_HPP
#define GREEKS_HPP

double delta_call(double S, double K, double r, double sigma, double T);
double delta_put(double S, double K, double r, double sigma, double T);
double gamma(double S, double K, double r, double sigma, double T);
double vega(double S, double K, double r, double sigma, double T);
double theta_call(double S, double K, double r, double sigma, double T);
double rho_call(double S, double K, double r, double sigma, double T);

#endif
