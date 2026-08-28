# C Programming — Relearning From the Low Level

> A collection of C programs I'm building while revisiting C, memory management, pointers, data structures, and low-level programming concepts.

I'm using this repository to move beyond simply *writing C syntax* and understand what is actually happening with **memory, pointers, arrays, dynamic allocation, and data structures**.

The programs start simple and gradually become more memory-oriented.

---

## 🧭 Learning Progress

| Topic                        | Status |
| :--------------------------- | :----: |
| 🧮 Calculator                |    ✅   |
| 🔢 Number Analyzer           |    ✅   |
| 🔄 String Reverse            |    ✅   |
| 👉 Pointer Swap              |    ✅   |
| 📏 `strlen()` implementation |    ✅   |
| 📦 `memcpy()` implementation |    ✅   |
| 📈 Dynamic Array             |    ✅   |
| 📚 Stack                     |    ✅   |
| 🧵 Dynamic String            |    ✅   |

> **Current focus:** Understanding dynamic memory and building small data structures without relying on high-level abstractions.

---

## 🧠 What I'm Practicing

This repository is mainly about getting comfortable with:

* Pointers and pointer arithmetic
* Stack vs heap memory
* `malloc()`, `realloc()` and `free()`
* Arrays and dynamically allocated memory
* C strings and the `'\0'` terminator
* Command-line arguments
* Implementing standard-library concepts myself
* Basic data structures
* Memory ownership and lifetime
* Thinking about programs at a lower level

---

# 📂 Programs

## 🧮 Calculator

A simple command-line calculator supporting basic arithmetic operations.

### Example

```bash
gcc calc.c -o calc
./calc 24 + 12
```

```text
The result is: 36
```

---

## 🔢 Number Analyzer

Takes numbers through command-line arguments and calculates:

* Count
* Minimum
* Maximum
* Average

It also introduces processing `argv` and converting strings into integers.

### Example

```bash
gcc numAnalyzer.c -o numAnalyzer
./numAnalyzer 1 2 3 4 5
```

```text
Count: 5
Minimum: 1
Maximum: 5
Average: 3.00
```

---

## 🔄 String Reverse

A simple string-reversal implementation using character manipulation and indexing.

```bash
gcc strngReverse.c -o strngReverse
./strngReverse "Hello World"
```

---

## 👉 Pointer Swap

A small exercise focused on understanding pointers by swapping values through memory addresses.

---

## 📏 Implementing `strlen()`

Instead of directly using the standard `strlen()`, I implemented a simple version to understand how C determines the length of a null-terminated string.

### What this taught me

A C string doesn't store its length by default.

Instead, the program walks through memory until it encounters:

```c
'\0'
```

---

## 📦 Implementing `memcpy()`

I implemented a simplified version of `memcpy()` to understand how raw bytes can be copied from one memory location to another.

The important part here was understanding why `memcpy()` requires a **size in bytes** rather than knowing the type of the data automatically.

### Example

```c
int a[] = {1, 25, 45, 88};
int b[4];

my_memcpy(&b, &a, sizeof(a));
```

This exercise helped me understand:

* Memory addresses
* Byte-level copying
* `sizeof`
* Pointer manipulation
* Why the size parameter matters

---

# 📈 Dynamic Array

A dynamically allocated integer array using heap memory.

Instead of fixing the array size at compile time, memory is allocated at runtime using:

```c
malloc()
```

and expanded when required using:

```c
realloc()
```

This was my first step toward understanding how dynamic data structures work underneath.

---

# 📚 Stack Implementation

A basic stack implemented using an array and a `top` index.

The core operations are:

```text
push()
pop()
peek()
```

This exercise connects C memory management with an actual data structure rather than treating arrays as isolated language features.

---

# 🧵 Dynamic String

This is currently one of the more interesting exercises in the repository.

The goal was simple:

> **Let the user enter a string of unknown length without asking for the length beforehand.**

Instead of doing something like:

```c
char buffer[10000];
```

the program starts with a small heap allocation and grows the buffer when necessary.

### The basic idea

```text
              getchar()
                  │
                  ▼
             character
                  │
                  ▼
                push()
                  │
                  ▼
          ┌───────────────┐
          │ Buffer full?  │
          └───────┬───────┘
              Yes │ No
                  │
          ┌───────▼───────┐
          │   realloc()   │
          │ grow capacity │
          └───────┬───────┘
                  │
                  ▼
            store character
                  │
                  ▼
              next input
```

### Memory Growth

The buffer starts with a small capacity:

```text
4 bytes
```

When it becomes full, the capacity is doubled:

```text
4 → 8 → 16 → 32 → 64 → ...
```

This avoids allocating an unnecessarily large buffer at the beginning while also avoiding a `realloc()` on every single character.

### Input Model

The program consumes the input character by character:

```c
while ((ch = getchar()) != '\n' && ch != EOF) {
    push(ch);
}
```

After the input is complete, the null terminator is added:

```c
stack[++top] = '\0';
```

So the resulting memory looks like:

```text
┌─────┬─────┬─────┬─────┬─────┬──────┐
│  h  │  e  │  l  │  l  │  o  │ '\0' │
└─────┴─────┴─────┴─────┴─────┴──────┘
   0     1     2     3     4      5
```

### The Problem

The interesting part wasn't simply learning how to call `realloc()`.

The real question was:

> **If I don't know the length of the input beforehand, when should I allocate more memory, and how do I continue writing into the newly allocated region?**

Thinking about the problem as a **stack + dynamic array** made the solution much easier to reason about.

---

# 🧩 What I'm Learning From These Exercises

The progression is intentional:

```text
Basic C
   ↓
Pointers
   ↓
Memory manipulation
   ↓
Dynamic allocation
   ↓
Data structures
   ↓
Dynamic memory + data structures
```

I'm trying to understand not just **how to write C**, but why things such as strings, arrays, buffers, and data structures work the way they do underneath.

---

## 🛠️ Build & Run

Most programs can be compiled with GCC.

For example:

```bash
gcc dynamicString.c -o dynamicString
./dynamicString
```

On Windows:

```bash
gcc dynamicString.c -o dynamicString
.\dynamicString.exe
```

---

## 🗺️ Roadmap

More low-level exercises will be added as I progress.

### Data Structures

* [ ] Linked List
* [ ] Queue
* [ ] Circular Queue
* [ ] Binary Search Tree
* [ ] Hash Table

### Memory & Systems

* [ ] Custom string utilities
* [ ] Better dynamic buffer
* [ ] File handling
* [ ] Binary file processing
* [ ] Memory allocator experiments

### Networking

* [ ] TCP client
* [ ] TCP server
* [ ] Simple HTTP client
* [ ] Basic socket experiments

### Later

The long-term goal is to move from small C exercises toward **actual systems programming projects**.

---

## 📌 Repository Philosophy

This isn't intended to be a collection of perfect or production-ready C libraries.

It's a record of my progression toward understanding **C, memory, data structures, and systems-level programming**.

Some implementations may be simple. Some may eventually be rewritten.

That's intentional.

> **Learn → Build → Break → Understand → Improve**

---

## 👨‍💻 About

**Debanjan**

Learning C by going closer to the machine — one memory allocation at a time.

[GitHub](https://github.com/Debanjan2007)
