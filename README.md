## Frequency- and SNR-Based Benchmarking of Wearable Respiration Sensors
# Wearable Respiration Sensor Benchmarking (Arduino + MATLAB)

## Overview
This repository documents and supports a benchmarking study comparing a lab-developed wearable breathing sensor against five commercial sensor modules. All sensors were mounted on a single wearable belt and recorded simultaneously under identical conditions using one Arduino to enable a fair comparison of respiration-related signal quality and consistency.

The workflow includes:
- Arduino-side multi-sensor data acquisition (simultaneous logging)
- MATLAB-side preprocessing and analysis (alignment, normalization, and metrics)

---

## Motivation
To expand our research, we evaluated the lab-developed breathing sensor against five commercial alternatives. Collecting all signals at the same time and under the same conditions reduces experimental bias and allows a direct comparison of:
- consistency across devices
- sensitivity to breathing motion
- signal quality for respiration detection

---

## Hardware Setup

### Sensors
- Lab-developed wearable breathing sensor
- Five commercial sensor modules (connected to the same Arduino)

### Mounting
- All sensors were mounted to a single wearable belt alongside the breathing sensor.
- Data was collected simultaneously to keep conditions identical across all devices.

### Wiring Notes (Important)
- All sensor modules were connected to **one Arduino**.
- **One** of the commercial sensor modules required a **logic level shifter** due to a logic-voltage mismatch (e.g., 3.3 V sensor with 5 V Arduino I/O).
  - **Module requiring level shifting:** `<<REPLACE WITH SENSOR NAME/MODEL>>`
  - **Bus/lines shifted (example):** SDA/SCL (I2C) or MOSI/MISO/SCK/CS (SPI) or a digital output pin

> Note: I’m not naming the module here because it depends on your exact sensor list and wiring; add the sensor name once confirmed in your hardware notes.

---

## Data Collection
- All sensors were sampled in the same session to ensure identical motion, placement, and timing conditions.
- Arduino output was logged via Serial (or a serial logging tool) and saved to file for analysis.

---

## Data Processing (MATLAB)
All signals follow the same pipeline to ensure a fair comparison.

### 1) Alignment / Resampling
- Signals are aligned to a common time base.
- If sensors have different sample rates, data is resampled to a shared rate (e.g., 100 Hz).

### 2) Normalization
Because different sensors output different units and ranges, normalization is applied before comparison:
- **Z-score normalization** (for analysis):  
  `z(t) = (x(t) − μ) / σ`
- **Min–max normalization** (for visualization):  
  `x_norm(t) = (x(t) − x_min) / (x_max − x_min)`

### 3) Metrics (examples)
The exact metrics depend on your analysis scripts, but commonly include:
- respiration-band signal strength (time domain)
- spectral content / PSD in the respiration band (frequency domain)
- SNR-like measures to quantify breathing signal strength vs noise
- consistency / repeatability across trials

---

## Repository Structure
```text
wearable-respiration-sensor-benchmark/
├─ arduino/
│  ├─ sensor_1.ino
│  ├─ sensor_2.ino
│  ├─ sensor_3.ino
│  ├─ sensor_4.ino
│  ├─ sensor_5.ino
│  └─ multi_sensor_logger.ino      # final combined sketch (recommended)
├─ matlab/
│  ├─ preprocess.m                 # alignment + filtering + normalization
│  ├─ compute_psd.m                # frequency-domain analysis
│  ├─ compute_metrics.m            # SNR/respiration metrics
│  └─ run_benchmark.m              # main script
├─ figures/
│  └─ (plots exported from MATLAB)
├─ data/                           # raw logs (excluded if confidential)
│  └─ README_DATA.md               # expected format + column definitions
└─ README.md
How to Run
Arduino (data acquisition)
Wire all sensor modules to the Arduino (use the logic level shifter for the specified module).

Upload the combined logging sketch (recommended: arduino/multi_sensor_logger.ino).

Open Serial Monitor / serial logger and save the output to a file (CSV preferred).

MATLAB (analysis)
Place the recorded log file(s) in data/ (or wherever your scripts expect).

Open MATLAB and set the current folder to matlab/.

Run:

matlab
Copy code
run_benchmark
Export figures to figures/.

What to Fill In (so this README is complete)
Replace <<REPLACE WITH SENSOR NAME/MODEL>> with the actual module that required the logic level shifter.

Add your actual data log format to data/README_DATA.md:

column names

units

sampling rate

which columns correspond to which sensor

Author
Masa Damdoum
Electrical Engineering (Co-op), University of Windsor

Disclaimer
Raw experimental data may be subject to confidentiality constraints and may not be included in this repository.

makefile
Copy code
