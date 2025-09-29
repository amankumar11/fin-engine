#include <iostream>
#include "black_scholes.hpp"
#include "greeks.hpp"
#include "monte_carlo.hpp"

int main() {
    double S, K, r, sigma, T;
    int choice;

    std::cout << "=== Quant Finance CLI ===" << std::endl;
    std::cout << "Enter Spot Price (S): ";
    std::cin >> S;
    std::cout << "Enter Strike Price (K): ";
    std::cin >> K;
    std::cout << "Enter Risk-free Rate (r): ";
    std::cin >> r;
    std::cout << "Enter Volatility (sigma): ";
    std::cin >> sigma;
    std::cout << "Enter Time to Maturity (T in years): ";
    std::cin >> T;

    std::cout << "\nChoose Operation:" << std::endl;
    std::cout << "1. Black-Scholes Pricing" << std::endl;
    std::cout << "2. Greeks" << std::endl;
    std::cout << "3. Monte Carlo Simulation" << std::endl;
    std::cout << "4. All of the above" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1 || choice == 4) {
        std::cout << "\n=== Black-Scholes ===" << std::endl;
        std::cout << "Call Price: " << black_scholes_call(S, K, r, sigma, T) << std::endl;
        std::cout << "Put Price:  " << black_scholes_put(S, K, r, sigma, T) << std::endl;
    }

    if (choice == 2 || choice == 4) {
        std::cout << "\n=== Greeks ===" << std::endl;
        std::cout << "Delta (Call): " << delta_call(S, K, r, sigma, T) << std::endl;
        std::cout << "Delta (Put):  " << delta_put(S, K, r, sigma, T) << std::endl;
        std::cout << "Gamma:        " << gamma(S, K, r, sigma, T) << std::endl;
        std::cout << "Vega:         " << vega(S, K, r, sigma, T) << std::endl;
        std::cout << "Theta (Call): " << theta_call(S, K, r, sigma, T) << std::endl;
        std::cout << "Rho (Call):   " << rho_call(S, K, r, sigma, T) << std::endl;
    }

    if (choice == 3 || choice == 4) {
        std::cout << "\n=== Monte Carlo Simulation ===" << std::endl;
        int num_sims;
        std::cout << "Enter number of simulations: ";
        std::cin >> num_sims;
        std::cout << "MC Call Price: " << monte_carlo_call(S, K, r, sigma, T, num_sims) << std::endl;
    }

    return 0;
}
