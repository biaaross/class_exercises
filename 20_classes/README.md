# Network Traffic Engine Simulation

A lightweight C++ console application that simulates a network traffic management engine. The project demonstrates core Object-Oriented Programming (OOP) principles, including abstraction, polymorphism, encapsulation, memory management via custom dynamic arrays, file I/O operations, and C++ templates.

---

## 🛠 Features

* **Abstract Network Packet Interface:** Defined via `NetworkPacket` containing common properties like unique identifiers, sources, and payload sizes.
* **Polymorphism:** Utilizing virtual functions and pure virtual methods (`display()`) allowing for extendable custom packet types (e.g., `ConcretePacket`).
* **Generic Traffic Management:** A custom template class `TrafficEngine<T>` that manages dynamically allocated arrays of any packet type using a self-resizing pointer array.
* **Persistent File I/O:** Functionality to export active traffic logs to a textual report file (`saveReport`) and reconstruct packet instances from an existing report (`loadReport`).
* **Explicit Memory Lifecycle Management:** Safe tracking of dynamic data with fully defined rules for object destruction, safely avoiding memory leaks.

---

## 🏗 Project Architecture & Hierarchy

The codebase is organized into modular header and implementation files:

* **`NetworkPacket.hpp` / `NetworkPacket.cpp`**: The base abstract class. Encapsulates `packetId`, `sourceId`, and `payloadSize` with comprehensive validation checkers.
* **`TrafficEngine.hpp`**: A template-based wrapper handling an array of packet pointers (`T**`). It includes custom memory reallocation logics (`resize()`) and item management routines.
* **`main.cpp`**: The driver script that brings everything together by defining a specific implementation (`ConcretePacket`), running pipeline tests, writing state to disk, and re-reading it into a blank instance.

### Class Structure Diagram
```text
      ┌─────────────────────────────────┐
      │     NetworkPacket (Abstract)    │
      └────────────────┬────────────────┘
                       │
                       ▼
         ┌───────────────────────────┐
         │       ConcretePacket      │
         └─────────────┬─────────────┘
                       │ (Managed by pointers)
                       ▼
┌──────────────────────────────────────────────┐
│             TrafficEngine<T>                 │
│ ──────────────────────────────────────────── │
│  - T** TrafficList (Dynamic Pointer Array)   │
│  - int capacity                              │
│  - int count                                 │
└──────────────────────────────────────────────┘