# Generic Sensor Data Management Engine

This repository contains a modular and generic data storage simulation written in C++. The project focuses on handling dynamic collections of sensor metrics through a custom template-based container, implementing resource management via RAII, and persisting dataset logs using traditional file streams.

---

## 🛠 Features

* **Data Encapsulation & Validation:** The `SensorData` entity encapsulates an alphanumeric sensor string alongside its corresponding high-precision Unix epoch timestamp (`long long`), backing up safe assignments via sanity boundary checks.
* **Template-Driven Dynamic Layout:** Features a fully generalized generic controller engine (`DataEngine<T>`) designed to handle generic pointer arrays (`T**`) without relying on the Standard Template Library (`std::vector`).
* **Automated Array Doubling:** Built-in predictive allocation logic (`resize`) duplicates heap boundaries internally whenever the tracking volume breaks out of current indexing footprints.
* **Persistent File Serialization:** Supports automated structured serialization. It exports state footprints out to space-separated text records (`saveToFile`) and cleanly parses streaming streams back into objects (`loadFromFile`).

---

## 🏗 System Architecture & File Layout

The codebase utilizes clean abstraction layer separations:

* **`Sensor.hpp` / Implementation:** Declares property fields (`SensorId`, `timestamp`), initialization vectors, explicit cleanups, validation checks, and diagnostic log rendering channels (`display()`).
* **`DataEngine.hpp`:** Core generic blueprint layout encapsulating container states (`T** dataArray`, `capacity`, `size`). Manages data addition, on-demand structural reallocation, boundaries checking, and robust file operations.
* **`main.cpp`:** Serves as the implementation driver runtime sequence. Provisions mockup sensors, tests runtime array allocations, serializes raw state files, and visualizes system output pipelines.

### Data Flow Layout Diagram
```text
  ┌───────────────────────┐
  │      SensorData       │◀── [Encapsulated Records]
  └───────────┬───────────┘
              │
              ▼ Passed by reference
  ┌───────────────────────┐
  │    DataEngine<T>      │◀── [Instantiates safe deep copies on Heap]
  └───────────┬───────────┘
              │
      ┌───────┴───────┐
      ▼               ▼
┌───────────┐   ┌───────────┐
│ veriler.t │   │  Console  │
│    xt     │   │  Outputs  │
└───────────┘   └───────────┘