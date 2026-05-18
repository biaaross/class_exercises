# CyberPulseEngine - Advanced Cyber Threat Log Manager

A high-performance, lightweight cyber security threat logging and analysis engine built entirely in modern C++. This project is designed as a **bare-metal memory management showcase**, implementing dynamic memory layouts, inheritance patterns, and generic template structures **without utilizing any STL containers** (such as `std::vector` or `std::list`).

## 🎯 Architectural Highlights

*   **Custom Memory Allocation Manager:** Leverages a `T**` (pointer-to-pointer) double-pointer array structure to manually handle contiguous heap allocations.
*   **Automated Resource Scaling:** Features a custom, low-level scaling algorithm (`resizePool`) that dynamically doubles memory capacity, relocates existing pointers, and ensures memory safety by zero-filling unallocated bounds with `nullptr`.
*   **Strict Encapsulation Principle:** Demonstrates proper Object-Oriented Design (OOD). Derived classes interact with base class private members strictly via public interfaces, enforcing input validation and preventing state corruption.
*   **Polymorphic Runtime Engine:** Utilizes an abstract base class with pure virtual functions to enable dynamic dispatch, executing localized threat analysis procedures at runtime.
*   **Forensic File Persistence:** Implements robust raw stream parsing (`std::ofstream`/`std::ifstream`) to dump transient log states as serialized files and dynamically rebuild them back into active heap objects during system recovery.
*   **Zero-Leak Guarantee:** Adheres strictly to RAII (Resource Acquisition Is Initialization) and the **Rule of Three**. Deletes deep pointers sequentially before freeing the root array descriptor, completely eliminating memory leaks.

---

## 📁 Repository Structure

*   `LogEntry.hpp` / `.cpp`: Abstract base configuration containing baseline network telemetry fields (Timestamp, Source IP, Threat Level).
*   `MaliciousActivity.hpp` / `.cpp`: Concrete derived entity tracking localized security anomalies (e.g., SQL Injection, DDoS, Brute Force).
*   `CyberPulseEngine.hpp`: Core templated management engine implementing raw pointer arrays, resizing, forensic dumps, and threat resolutions.
*   `main.cpp`: Automated simulation testing infrastructure triggering capacity thresholds, dynamic scaling, index shifting, and disk state recovery.

---

## 🛠️ Compilation and Execution

To compile the project natively via any modern C++ compiler (supporting C++11 or higher), navigate to the root directory and run:

```bash
# Compilation using GCC
g++ -O3 main.cpp LogEntry.cpp MaliciousActivity.cpp -o CyberPulseEngine

# Execution (Linux / macOS)
./CyberPulseEngine

# Execution (Windows)
CyberPulseEngine.exe