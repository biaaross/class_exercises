# CyberCore OS Process Scheduler Simulation

A mock operating system process scheduler simulation written in C++. This project demonstrates advanced Object-Oriented Programming (OOP) architectures, custom generic containers with continuous memory management, run-time polymorphism, and persistent log output generation.

---

## 🛠 Features

* **Abstract Process Interface:** Built upon `BaseProcess`, establishing a blueprint layout tracking shared process metadata (`processId`, `name`, `priority`).
* **Run-time Polymorphism:** Implements specialized derived variants representing distinct process boundaries:
  * `SystemProcess`: High-priority infrastructure kernels.
  * `UserProcess`: Traditional consumer software layers monitoring dynamic heap metrics (`memoryUsage`).
  * `BackgroundProcess`: Non-blocking daemon scripts and service synchronization loops.
* **Generic Scheduler Vector Engine:** Powered by a customized template container framework (`ProcessManager<T>`) designed to handle pointer lists (`T**`) natively without relying on `std::vector`.
* **Predictive Boundary Reallocations:** Employs an array-doubling mechanism when capacity thresholds are breached, cleanly sliding existing dynamic elements without losing contextual references.
* **System Log Serialization:** Features automated status dumping mechanics (`saveLog`) utilizing structured standard output file streams (`std::ofstream`).

---

## 🏗 System Architecture & Class Hierarchy

The project emphasizes clean file structure isolation across architectural boundaries:

* **`BaseProcess.hpp` / `.cpp`:** The root abstract class enclosing identification criteria and standard execution definitions. Features a critical reporting destructor wrapper.
* **Derived Components (`SystemProcess`, `UserProcess`, `BackgroundProcess`):** Concrete classes overriding polymorphic behaviors (`execute()` and `getStatus()`) to reflect specialized execution models.
* **`ProcessManager.hpp`:** A template-driven job manager class executing pointer array reallocations, memory-safe shifts on item removals (`deleteItem`), and global pipeline execution calls.
* **`main.cpp`:** Actively mounts the testing loop—spawning distinct process workloads, tracking capacity expansions, auditing item shift removals, and emitting structural diagnostics.

### Structural Inheritance & Management Layout
```text
               ┌───────────────────────────┐
               │        BaseProcess        │ (Abstract Base)
               └─────────────┬─────────────┘
                             │
         ┌───────────────────┼───────────────────┐
         ▼                   ▼                   ▼
┌─────────────────┐ ┌─────────────────┐ ┌───────────────────┐
│  SystemProcess  │ │   UserProcess   │ │ BackgroundProcess │ (Concrete Derived)
└────────┬────────┘ └────────┬────────┘ └─────────┬─────────┘
         │                   │                    │
         └───────────────────┼────────────────────┘
                             │ Managed via Pointers (BaseProcess*)
                             ▼
               ┌───────────────────────────┐
               │     ProcessManager<T>     │ (Custom Template Container)
               └───────────────────────────┘