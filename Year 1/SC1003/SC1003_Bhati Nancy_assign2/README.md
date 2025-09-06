# SC1003 Assignment 2: Implementation of MACD trend reversal trading system


## Overview
Assignment Overview and Specification; <br>
https://entuedu-my.sharepoint.com/:b:/g/personal/nancy001_e_ntu_edu_sg/ER7XJ2IbV0lKmsqnQNjzzJsBbr9X6Je5YS2Oo9HWDX0J0A?e=0cViLb

This project implements a **trading system based on the Moving Average Convergence Divergence (MACD) indicator**.  
MACD is a momentum oscillator that measures the relationship between two moving averages of a security’s price.  
It provides signals for **trend strength** and potential **trend reversals**, widely used by traders for buy/sell decisions.

The project demonstrates how to:
- Load and clean stock market datasets
- Compute financial metrics such as returns, drawdowns, and peaks
- Calculate MACD, signal line, and histogram values
- Backtest a trading strategy based on MACD crossovers
- Visualize price data and technical indicators
---

## Submissions
Assignment Report : <br>
https://entuedu-my.sharepoint.com/:w:/g/personal/nancy001_e_ntu_edu_sg/EVulysPrIwFCowkCa2lI4aMBqio8QS_qIn5AGHwIfn-UYw?e=aSnxeP

Assigmnet Source Code and Result: <br>
https://entuedu-my.sharepoint.com/:u:/g/personal/nancy001_e_ntu_edu_sg/EcGGm7CCXpJKhZGTcfq5XrIBso2n7FaWV8Yw2-bHfs9jpA?e=8UyfJh

---
## Concepts
- **EMA (Exponential Moving Average):**
  - **SEMA:** Shorter-term EMA (12 days)
  - **LEMA:** Longer-term EMA (26 days)
- **Signal Line:** 9-day EMA of the MACD values
- **MACD Line:** Difference between 12-day and 26-day EMA
- **Histogram:** Difference between MACD and Signal line

**Interpretation:**
- **Bullish Signal:** MACD crosses above the signal line → Buy  
- **Bearish Signal:** MACD crosses below the signal line → Sell  
- Histogram bars indicate trend strength (larger bars = stronger trend).

---

## Features
- Import and preprocess multiple financial datasets (CAC40, SPY, FTSE100).
- Interactive dataset selection for flexibility.
- Calculation of:
  - Benchmark returns and balances
  - Drawdowns and cumulative returns
  - MACD, signal line, histogram
- Buy/Sell signal generation based on MACD crossover.
- Backtesting system to compare:
  - Benchmark performance
  - System performance
- Visualization of:
  - Stock closing prices
  - MACD and Signal Line
  - Histogram (trend strength)
  - Equity curves for benchmark vs. trading system
- Performance metrics:
  - CAGR (Compound Annual Growth Rate)
  - Worst Drawdown
  - Total returns
---

## Supporting Datasets
Here, are the supporting datasets <br>
https://entuedu-my.sharepoint.com/:u:/g/personal/nancy001_e_ntu_edu_sg/EeqCBYEEPNBLhHHw3RSNEE8BWNrpVRhmSdb4wBJaFxgTsw?e=i6trOm


## Technical Details
- **Language:** Python  
- **Libraries Used:**  
  - `pandas`, `numpy` (data analysis)  
  - `matplotlib`, `seaborn` (visualization)  
  - `datetime` (date/time handling)  


