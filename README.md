# C++ Engine Deployment Guide
> **Status: Work in Progress**

To initialize the logic engine within the Ubuntu environment, the engineering team (me) utilizes a standardized deployment architecture featuring an isolated binary directory for optimal workspace hygiene.

---

## 1. AI-Assisted Development & Code Verification

All C++ code in this repository was written manually by the author.

LLMs were used as development and review tools rather than as replacements for implementation or understanding.

The general development workflow is:

**Human implementation → LLM review → Human verification → Final code**

Code may be reviewed by LLMs for:

* Potential bugs or edge cases
* C++ language correctness
* Code quality and readability
* Alternative implementations
* Performance considerations
* Modern C++ practices
* Potential undefined behavior
* Opportunities for improvement

The resulting suggestions are then manually reviewed and cross-checked by the author before being accepted.

Comments and documentation may also be created or refined with LLM assistance. Simple initial comments may be written by the author and subsequently reviewed or improved by an LLM, with final human verification.

### Human Understanding Requirement

LLM-generated suggestions are **not treated as authoritative**.

Particularly in languages such as C++, developers should understand what their code does before considering it ready for deployment.

This is especially important when dealing with concepts such as:

* Memory management
* Object lifetime
* Ownership
* References and pointers
* Copy and move semantics
* Constructors and destructors
* Undefined behavior
* Templates
* Iterators and ranges
* Concurrency
* Compilation and linking
* Runtime behavior

The objective is therefore not merely to produce code that compiles or passes a test.

The objective is to understand **what the code does, why it works, and what its relevant consequences are**.

Final responsibility for the code remains with the human author.

---

## 2. Compilation Protocols

The human-readable C++ source code must be translated into an executable binary using the GNU C++ compiler (`g++`).

We support two primary deployment methods.

### Method A: Manual Payload Routing (Direct CLI)

Utilize this for one-off scripts or quick experimentation.

Replace `<filename>` with the target source file:

```bash
g++ <filename>.cpp -o bin/<filename>
```

> **Architecture Note:** The `-o bin/<filename>` flag explicitly routes the compiled executable into the dedicated `bin/` directory. This isolates binaries from source code, preventing workspace clutter and keeping generated artifacts separated from version-controlled source files.

For additional diagnostics, compilation can be performed with warning flags:

```bash
g++ <filename>.cpp -Wall -Wextra -o bin/<filename>
```

---

### Method B: Automated Orchestration (Makefile)

For standardized builds and multi-file projects, utilize the automated `make` pipeline.

The repository Makefile enforces the configured C++ standard and compiler diagnostics.

```bash
make
```

The current build configuration uses ISO C++20 with additional compiler warnings enabled.

---

## 3. System Execution

Upon successful compilation, the generated executable can be launched directly from the Ubuntu environment.

Unix-based systems require the relative path to be explicitly specified when executing a binary located in the current workspace:

```bash
./bin/<filename>
```

A successful compilation confirms that the compiler accepted the program according to the configured language rules and diagnostics.

It does **not** guarantee that the program is free from:

* Logic errors
* Runtime errors
* Undefined behavior
* Incorrect assumptions
* Performance issues
* Incorrect output

Compilation is therefore only one stage of the verification process.

---

## 4. Workspace Maintenance — The Clean Routine

To ensure that stale binaries do not interfere with development, the environment can be fully purged.

This simulates a clean rebuild by removing generated binaries from the `bin/` directory.

```bash
make clean
```

A clean build can subsequently be performed with:

```bash
make clean
make
```

This ensures that the executable is generated from the current source tree rather than relying on previously generated artifacts.

---

## 5. Engineering Specifications

The current deployment profile utilizes the following architectural constraints:

| Component          | Specification      |
| ------------------ | ------------------ |
| **Language**       | C++                |
| **Standard**       | ISO C++20          |
| **Compiler**       | GNU C++ (`g++`)    |
| **Build System**   | GNU Make           |
| **Diagnostics**    | `-Wall`, `-Wextra` |
| **Binary Path**    | `./bin/`           |
| **Environment**    | Ubuntu             |
| **Source Control** | Git                |

---

## 6. Development Philosophy

This repository is primarily a learning and experimentation environment.

The goal is not simply to make programs work, but to understand the language and the underlying engineering concepts.

C++ provides a particularly good environment for this approach because relatively small pieces of code can expose important concepts involving:

* Compilation
* Linking
* Memory
* Object lifetime
* Value categories
* Ownership
* Resource management
* Abstraction
* Performance
* The standard library
* Hardware-level behavior

Newer language and standard-library features may also be used when appropriate.

Although the primary course material associated with this repository targets C++17, the repository itself uses **C++20** where useful.

For example, C++20 ranges and views may be used even when the underlying programming concept was originally introduced using older C++ syntax.

The purpose is to understand both the underlying concept and the modern way of expressing it.

---

## 7. Verification Principle

Before code is considered ready, the following principle applies:

> **If you cannot explain what the code does, you should not deploy it.**

AI assistance can accelerate development, identify potential problems, and provide alternative perspectives.

It does not replace understanding.

The final code should therefore be explainable by the human who wrote and accepted it.

---

## 8. Repository Intent

This repository is intended to serve as a public record of the author's progression through C++.

The exercises and implementations are made available so that other developers and learners can:

* Inspect the solutions
* Study alternative approaches
* Compare implementations
* Experiment with the code
* Use the repository as a learning reference

Feel free to take inspiration from the implementations, modify them, break them, improve them, and most importantly, **understand them**.

---

## 9. Course Context & C++20 Adaptation

This repository was originally built while following the highly acclaimed course **"Beginning C++ Programming - From Beginner to Beyond"** by Frank Mitropoulos. 

While the original course curriculum focuses heavily on foundational Modern C++ (C++14 and C++17) to match current industry standards, this repository deliberately pushes the boundaries by implementing **C++20** features, modern build systems (Makefiles), and advanced memory management techniques. 

The exercises contained here solve the instructor's challenges but often diverge into custom architectures, modular header-only designs, and modern C++ standard library utilities not covered in the base material.

---

## 10. Repository Structure

The workspace is organized chronologically by course sections, progressing from basic mechanics to advanced Object-Oriented Programming and STL features:

* `section_4` to `section_12`: Fundamentals (Arrays, Vectors, Pointers, Functions, and Memory Allocation).
* `section_13`: Object-Oriented Programming (Classes, Objects, Constructors).
* `section_14`: Operator Overloading.
* `section_15`: Inheritance and Polymorphism.
* `section_16`: Polymorphism (Virtual functions, Abstract classes).
* `section_17`: Smart Pointers (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`).
* `section_18`: Exception Handling (Custom classes, Stack Unwinding).
* `section_19`: I/O and Streams.

Each section contains its own isolated implementation files and, where applicable, custom Makefiles for binary orchestration.