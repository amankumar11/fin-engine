#include "monte_carlo.hpp"
#include <random>
#include <cmath>

double monte_carlo_call(double S, double K, double r, double sigma, double T, int num_sims) {
    std::mt19937_64 rng(42);  // fixed seed for reproducibility
    std::normal_distribution<double> norm(0.0, 1.0);

    double payoff_sum = 0.0;
    for (int i = 0; i < num_sims; i++) {
        double Z = norm(rng);
        double ST = S * std::exp((r - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * Z);
        payoff_sum += std::max(ST - K, 0.0);
    }

    return std::exp(-r * T) * (payoff_sum / num_sims);
}
