# Generic Order Matching Engine (C++)

This project implements a high-performance, memory-safe **Financial Order Matching Engine** in C++. It simulates a simplified core infrastructure of a modern financial exchange, capable of handling **Limit Orders** and **Market Orders**, matching them based on strict price-time priority rules, and maintaining a contiguous memory architecture.

The engine is built entirely from scratch **without using any Standard Template Library (STL) containers** (like `std::vector` or `std::list`), showcasing advanced manual dynamic memory management, generic programming, and object-oriented design principles.

---

## 🚀 Key Features

*   **Polymorphic Order Hierarchy:** Implements a strict encapsulation model utilizing an abstract base `Order` class with specialized `LimitOrder` and `MarketOrder` derivatives.
*   **Strongly Typed Safeguards:** Employs `enum class` restrictions for order sides (`BUY` / `SELL`) ensuring compile-time safety and preventing illegal state transitions.
*   **Custom Dynamic Array Implementation:** Features a template-based `MachineEngine` handling pointer-to-pointer (`T**`) arrays with custom `resize()` logic to scale runtime storage capacity dynamically.
*   **Contiguous Memory Squeezing:** Contains a custom memory compression algorithm (`cleanFilledOrders`) that purges fully executed orders and shifts active pointer elements to eliminate fragmentation.
*   **Deterministic Memory Lifecycle:** Zero memory leaks. All heap allocations are guaranteed to be cleaned up either dynamically upon execution or deterministically during engine destruction via robust destructors.
*   **Audit Trail & Reporting:** Provides polimorphic console streams and external file logging capabilities (`exportAuditTrail`) for systemic transparency.

---

## 📐 Architecture & OOP Principles

### 1. Encapsulation (Kapsülleme)
All raw member variables (IDs, Quantities, Prices) are isolated under `private` modifiers. Derived classes interact with base components through validated, exception-safe inspector/mutator methods (Getters/Setters), shielding data consistency from unauthorized modifications.

### 2. Polymorphism (Polimorfizm)
Runtime binding is established using virtual tables (`vtable`). Functions like `executeOrder()` and `getOrderDetails()` resolve behavior dynamically based on whether the target object is a Market or Limit order type.

### 3. Generic Programming (Templates)
The `MachineEngine<T>` class decouples the data management framework from specific asset schemas, preparing the engine for seamless cross-asset adaptability.

---

## 📁 File Structure

```text
├── Order.hpp            # Base Order specification & Enum Class
├── Order.cpp            # Base Order implementation & state validators
├── LimitOrder.hpp       # LimitOrder class definition
├── LimitOrder.cpp       # Limit-specific execution & string formatting
├── MarketOrder.hpp      # MarketOrder class definition
├── MarketOrder.cpp      # Market-specific execution rules
├── MachineEngine.hpp    # Template class for dynamic allocation & matching logic
└── main.cpp             # Simulation test harness