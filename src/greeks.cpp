#include "black_scholes.hpp"
#include "greeks.hpp"
#include <cmath>

// Standard normal PDF
static double norm_pdf(double x) {
    return (1.0 / std::sqrt(2 * M_PI)) * std::exp(-0.5 * x * x);
}

double delta_call(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return norm_cdf(d1);
}

double delta_put(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return norm_cdf(d1) - 1.0;
}

double gamma(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return norm_pdf(d1) / (S * sigma * std::sqrt(T));
}

double vega(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return S * norm_pdf(d1) * std::sqrt(T);
}

double theta_call(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    double term1 = -(S * norm_pdf(d1) * sigma) / (2 * std::sqrt(T));
    double term2 = -r * K * std::exp(-r * T) * norm_cdf(d2);
    return term1 + term2;
}

double rho_call(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return K * T * std::exp(-r * T) * norm_cdf(d2);
}
