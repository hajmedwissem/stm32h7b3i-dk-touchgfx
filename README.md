# Plant Irrigation Monitoring & Control System

> Real-time embedded control system built on STM32H7B3 — automating plant care through sensor-driven logic, a TouchGFX UI, and persistent Flash storage.

---

## Overview

This project monitors and controls the environment for plant growth using real-time sensor data. It automates pump and fan activation based on user-defined thresholds, reducing water consumption and eliminating the need for constant manual monitoring.

**Two operation modes:**
- **Automatic** — system activates/deactivates pump and fan based on live sensor readings and configurable thresholds
- **Manual** — user controls pump and fan independently directly from the touchscreen interface

**Monitored parameters:**
- Soil moisture
- Ambient humidity
- Dangerous gas levels — displayed as a real-time graph on the UI

All user configuration persists across power cycles via internal Flash storage — settings are restored automatically on restart.

---

## Key Technical Decisions & Trade-offs

| Decision | Reason | Result |
|---|---|---|
| ITCM/DTCM memory placement for critical-path code | CPU was spending too many cycles on time-sensitive tasks | **62% faster execution (2.6×)**, 156 bytes SRAM saved |
| FreeRTOS with queue/mutex/semaphore synchronization | Sensor acquisition, UI rendering, and control logic run as separate tasks — needed safe data sharing | Zero race conditions, stable multi-task operation under full load |
| Internal Flash for persistent storage | Avoids external EEPROM dependency, simplifies hardware, survives power loss | Settings restored automatically on every restart |
| 16-bit ADC (ADC1_INP0, ADC1_INP1) | Maximizes sensor resolution for accurate threshold detection | Precise moisture and humidity readings |
| Cppcheck static analysis before release | Catch reliability issues before hardware testing | 7 warnings identified and resolved |

---

## Performance Results

| Metric | Result |
|---|---|
| Critical-path execution time | **−62% (2.6× faster)** via ITCM/DTCM placement |
| SRAM consumption | **−156 bytes** through memory layout optimization |
| Static analysis warnings | **7 resolved** via Cppcheck before release |
| FreeRTOS stability | Stable operation across all tasks under peak sensor + UI load |

---

## Hardware & Stack

| Category | Details |
|---|---|
| MCU | STM32H7B3I-DK |
| UI Framework | TouchGFX |
| RTOS | FreeRTOS |
| Storage | Internal Flash |
| Sensors | 16-bit ADC (ADC1_INP0, ADC1_INP1) |
| IDE | STM32CubeIDE |
| Debugging | GDB, DWT cycle counters |
| Static Analysis | Cppcheck |

---

## Project Structure

```
├── Core/
│   ├── Src/          # Application logic, sensor handling, control tasks
│   └── Inc/          # Header files
├── TouchGFX/         # UI screens and assets
├── Drivers/          # STM32 HAL drivers
├── video&pictures/   # Real-world test results and demo footage
└── README.md
```

---

## Demo

See [`/video&pictures`](./video&pictures) for real-world test results including:
- Sensor response in automatic mode
- UI interaction and threshold configuration
- Pump and fan activation sequences

---

## Getting Started

1. Clone the repository
2. Open the project in **STM32CubeIDE**
3. Flash to a **STM32H7B3I-DK** board
4. Power on — previous settings load automatically from Flash

---

## Author

**Wissem Haj Mohamed** — Embedded Systems Engineer  
[github.com/hajmedwissem](https://github.com/hajmedwissem) | [linkedin.com/in/wissem-hadj-mohamed](https://linkedin.com/in/wissem-hadj-mohamed)
