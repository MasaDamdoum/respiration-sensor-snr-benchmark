
## Overview
This repository contains MATLAB-based analysis tools for benchmarking a **lab-developed wearable breathing sensor** against **five commercial inertial sensors**. The evaluation focuses on respiration detection performance by comparing all sensor outputs to a **medical-grade spirometer**, treated as the gold standard.

The goal of this project is to assess whether a custom, non-commercial breathing sensor can achieve accuracy and reliability comparable to (or better than) existing commercial sensors for wearable respiration monitoring applications.

---

## Motivation
Wearable respiration monitoring is critical for applications in healthcare, rehabilitation, and human–machine interaction. While many commercial inertial sensors are available, they are not specifically optimized for respiration detection. This project investigates whether a **custom-designed breathing sensor** can provide improved sensitivity and signal quality when compared under controlled, standardized conditions.

Rather than comparing sensors directly to one another, this work evaluates **how closely each sensor matches the spirometer reference**, emphasizing accuracy, robustness, and signal fidelity.

---

## Experimental Setup
- **Sensors tested**
  - 5 commercial inertial sensors
  - 1 lab-developed breathing sensor
- **Reference device**
  - Medical-grade spirometer (gold standard)
- **Wearable configuration**
  - All sensors mounted on a wearable belt
- **Data acquisition**
  - Simultaneous recording via Arduino / serial monitor
  - Data exported and processed in MATLAB

---

## Data Processing Pipeline
All sensor signals undergo the same preprocessing and analysis workflow to ensure a fair comparison.

### 1. Signal Alignment
- All signals are resampled to a common sampling rate (e.g., 100 Hz)
- Signals are interpolated as needed to align time bases

### 2. Normalization
Because sensors report different physical quantities (e.g., acceleration in g or m/s², spirometer volume):
- **Z-score normalization** is used for statistical comparison  
  \[
  z(t) = \frac{x(t) - \mu}{\sigma}
  \]
- **Min–max normalization** is used for visualization  
  \[
  x_{norm}(t) = \frac{x(t) - x_{min}}{x_{max} - x_{min}}
  \]

---

## Comparison Methods
Each sensor is evaluated against the spirometer using multiple complementary metrics:

- **Respiratory frequency**
  - Extracted using FFT or peak interval analysis
- **Amplitude comparison**
  - Peak-to-peak measurements
  - Normalized Root Mean Square Error (NRMSE)
- **Statistical validation**
  - Paired t-tests comparing sensor-derived metrics to spirometer values
- **Waveform similarity**
  - Timing alignment, shape comparison, and signal-to-noise ratio (SNR)

This multi-metric approach ensures that both **quantitative accuracy** and **signal quality** are assessed.

---

## Project Structure

```text
respiration-sensor-snr-benchmark/
├─ code/
│  ├─ preprocess.m        % Signal alignment and normalization
│  ├─ compute_psd.m       % Frequency-domain analysis
│  ├─ compute_snr.m       % SNR and amplitude metrics
│  └─ run_benchmark.m    % Main analysis pipeline
├─ figures/
│  ├─ psd_comparison.png
│  ├─ snr_barplot.png
│  └─ example_breathing_signal.png
├─ results/
│  └─ summary_table.csv
├─ data/                 % Raw sensor data (excluded)
└─ README.md
```

## Design Notes
Raw experimental data are intentionally excluded

All analysis steps are modular and reusable

The pipeline is designed to scale to additional sensors or subjects

Methods are aligned with prior peer-reviewed respiration sensing studies


## Author
Masa Damdoum
Bachelor of Applied Science – Electrical Engineering (Co-op)
University of Windsor

## Disclaimer
This repository is intended for academic and research purposes. Raw experimental data may be subject to confidentiality constraints and are not included.
