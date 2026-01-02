## Frequency- and SNR-Based Benchmarking of Wearable Respiration Sensors

## Overview
This repository documents the **experimental setup and data acquisition workflow** used to benchmark a **lab-developed wearable breathing sensor** against **five industrial accelerometers** using a **single Arduino-based platform**. All sensors were recorded **simultaneously under identical conditions**, enabling a fair and controlled comparison of respiration-related signal quality.

While the analysis and benchmarking were performed in MATLAB, this repository intentionally includes **only the Arduino acquisition code** used to interface with each accelerometer. MATLAB scripts and raw data are excluded.

---

## Sensors Used
The following industrial accelerometers were evaluated alongside the lab-developed breathing sensor:

- **ADXL1002** – High-frequency, low-noise single-axis accelerometer  
- **ADXL335** – Low-power, 3-axis analog accelerometer  
- **ADXL345** – Digital 3-axis accelerometer (I²C/SPI)  
- **ADXL362** – Ultra-low-power digital accelerometer  
- **MPU6050** – 6-axis IMU (accelerometer + gyroscope)

-Due to logic-level mismatches between the Arduino (5 V) and certain digital sensors (3.3 V), a logic level shifter was required for the ADXL345 and ADXL362 accelerometers. The remaining sensors were either analog devices or included onboard level shifting.

-Each accelerometer has a dedicated Arduino sketch in this repository for individual testing and validation.

---

## Hardware Configuration
- All accelerometers and the lab-developed breathing sensor were mounted on a **single wearable belt**
- All signals were acquired using **one Arduino**, ensuring:
  - identical motion conditions
  - synchronized data capture
  - consistent sensor placement
- One sensor module (digital I/O) required a **logic level shifter** due to a voltage mismatch between the sensor and Arduino I/O levels

---

## Data Acquisition
- Sensor data were collected simultaneously using the CoolTerm serial data acquisition application
- All sensor outputs were streamed over serial communication and logged for offline analysis
- Using a single acquisition platform ensured synchronized sampling and minimized timing offsets and environmental variability between sensors

---

### MATLAB processing steps included:
- Time alignment and resampling of all sensor signals
- Because different sensors output different units and ranges, normalization is applied before comparison:
- **Z-score normalization** (for analysis):  
  `z(t) = (x(t) − μ) / σ`
- **Min–max normalization** (for visualization):  
  `x_norm(t) = (x(t) − x_min) / (x_max − x_min)`
- Signal normalization to account for differing units and ranges
- Time-domain and frequency-domain analysis
- Comparison of respiration-related signal content
- Evaluation of signal quality, sensitivity, and consistency across sensors

---

## Snap-Fit Arduino Enclosure Design

A custom snap-fit Arduino enclosure was designed to securely house the data acquisition hardware used in this project. The enclosure was modeled in FreeCAD and fabricated using Bambu Lab 3D printing with OrcaSlicer.

### Design Features
- Snap-fit mechanism designed to eliminate the need for screws or fasteners
- Precise alignment for USB and power port cutouts to allow cable access without removing the enclosure
- Compact form factor suitable for wearable or benchtop use
- Designed for quick assembly and disassembly during testing

## Iterative Development
Multiple design iterations were required to refine snap tolerances and achieve a tight, secure fit without excessive insertion force. Each iteration was evaluated for mechanical retention, ease of use, and print reliability.

## Fabrication Details
- **CAD software:** FreeCAD  
- **Slicer:** OrcaSlicer  
- **3D printer:** Bambu Lab (FDM)  
- **Material:** PLA  
- **Nozzle diameter:** 0.4 mm  
- **Layer height:** 0.2 mm

## Final Print: 

![3D Print Job 1](./_figures/3D%20Print%20Job%20%231.jpg)

![3D Print Job 2](./_figures/3D%20Print%20Job%20%232.jpg)



This enclosure improved hardware robustness during testing and enabled repeatable sensor experiments without exposed wiring or loose connections.


## Design Notes 
- Each Arduino sketch was developed and tested independently
- Sensor selection spans analog and digital devices with varying noise floors and bandwidths
- Raw experimental data and analysis scripts are excluded

---

## Final Product  

![Final Product](./_figures/Final%20Product.png)


---

## Author
Masa Damdoum
- Electrical Engineering (Co-op)
- University of Windsor

---

## Disclaimer
This repository is intended for academic and research documentation purposes. Raw experimental data and analysis scripts are not included.


