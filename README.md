# Quant Finance Toolkit

A C++ project implementing **quantitative finance models**:

- Black–Scholes option pricing (Call & Put)
- Greeks (Delta, Gamma, Vega, Theta, Rho)
- Monte Carlo simulation for option pricing

---

## Project Structure

quant_finance/
│── CMakeLists.txt
│── include/
│ ├── black_scholes.hpp
│ ├── greeks.hpp
│ └── monte_carlo.hpp
│── src/
│ ├── main.cpp
│ ├── black_scholes.cpp
│ ├── greeks.cpp
│ └── monte_carlo.cpp

## Build Instructions

Make sure you have **CMake** and **g++ (or clang++)** installed.

```bash
# Clone repository
git clone https://github.com/yourusername/quant_finance.git
cd quant_finance

# Create build directory
mkdir build && cd build

# Run CMake & build
cmake ..
make

# Run Program
./quant_finance
```

## Example Run
``bash
=== Quant Finance CLI ===
Enter Spot Price (S): 100
Enter Strike Price (K): 100
Enter Risk-free Rate (r): 0.05
Enter Volatility (sigma): 0.2
Enter Time to Maturity (T in years): 1

Choose Operation:
1. Black-Scholes Pricing
2. Greeks
3. Monte Carlo Simulation
4. All of the above
Enter choice: 4

=== Black-Scholes ===
Call Price: 10.4506
Put Price: 5.5735

=== Greeks ===
Delta (Call): 0.6368
Delta (Put): -0.3632
Gamma: 0.0188
Vega: 37.524
Theta (Call): -6.414
Rho (Call): 53.23

=== Monte Carlo Simulation ===
Enter number of simulations: 100000
MC Call Price: 10.4712
```
