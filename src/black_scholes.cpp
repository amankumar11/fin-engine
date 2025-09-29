#include "black_scholes.hpp"
#include <cmath>

// Standard normal cumulative distribution
double norm_cdf(double x) {
    return 0.5 * std::erfc(-x * M_SQRT1_2);
}

// Black-Scholes European Call
double black_scholes_call(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
}

// Black-Scholes European Put
double black_scholes_put(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
}
