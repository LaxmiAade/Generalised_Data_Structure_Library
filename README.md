# Generalised Data Structure Library — C++ Template Project

![C++](https://img.shields.io/badge/C++-17-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Type](https://img.shields.io/badge/Type-Data%20Structure%20Library-purple)
![Approach](https://img.shields.io/badge/Approach-Generic%20Templates-yellow)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen)

A comprehensive, generic data structure library implemented in C++ using templates. It provides ready-to-use implementations of all major linked list variants, Stack, and Queue — each supporting full insertion, deletion, display, and counting operations across any data type.

---

## Problem Statement

Understanding and implementing core data structures from scratch is fundamental to computer science and software engineering. This library provides clean, well-documented, generic implementations of six essential data structures — Singly Linear, Singly Circular, Doubly Linear, Doubly Circular Linked Lists, Stack, and Queue — all written in a single header-style C++ file using templates, making them reusable with any data type.

---

## Project Structure

```
Generalised_Data_Structure_Library/
│
├── GeneralisedDataStructureLibrary.cpp     # Main file — all data structures + demo in main()
└── README.md
```

---

## Data Structures Implemented

| Type | Node Class | Functionality Class | Status |
|------|-----------|---------------------|--------|
| Singly Linear Linked List | `SinglyLLLnode<T>` | `SinglyLLL<T>` | ✅ Done |
| Singly Circular Linked List | `SinglyCLLnode<T>` | `SinglyCLL<T>` | ✅ Done |
| Doubly Linear Linked List | `DoublyLLLnode<T>` | `DoublyLLL<T>` | ✅ Done |
| Doubly Circular Linked List | `DoublyCLLnode<T>` | `DoublyCLL<T>` | ✅ Done |
| Stack | `Stacknode<T>` | `Stack<T>` | ✅ Done |
| Queue | `Queuenode<T>` | `Queue<T>` | ✅ Done |

---

## Key Features

| Feature | Description |
|---------|-------------|
| Generic Templates | All data structures work with any data type (`int`, `char`, `double`, etc.) |
| Insert at First | Insert a new node at the beginning of the structure |
| Insert at Last | Insert a new node at the end of the structure |
| Insert at Position | Insert a node at any valid position with boundary checks |
| Delete at First | Remove the first node from the structure |
| Delete at Last | Remove the last node from the structure |
| Delete at Position | Remove a node from any valid position with boundary checks |
| Display | Print all elements in a structured, readable format |
| Count | Return the total number of nodes currently in the structure |
| Stack Push / Pop / Peep | LIFO insertion, removal, and top-element peek without removal |
| Queue Enqueue / Dequeue | FIFO insertion and removal |
| Circular Linking | Circular variants maintain `last->next = first` integrity after every operation |
| Doubly Linking | Doubly variants maintain both `next` and `prev` pointer linkage |

---

## Functions Overview

### Singly Linear Linked List — `SinglyLLL<T>`

| Function | Input | Output | Description |
|----------|-------|--------|-------------|
| `InsertFirst(T)` | Data | Nothing | Inserts node at the first position |
| `InsertLast(T)` | Data | Nothing | Inserts node at the last position |
| `InsertAtPos(T, int)` | Data, Position | Nothing | Inserts node at a given position |
| `DeleteFirst()` | None | Nothing | Deletes the first node |
| `DeleteLast()` | None | Nothing | Deletes the last node |
| `DeleteAtPos(int)` | Position | Nothing | Deletes node at a given position |
| `Display()` | None | Prints list | Displays all nodes in `| data |-> NULL` format |
| `Count()` | None | Integer | Returns total node count |

### Singly Circular Linked List — `SinglyCLL<T>`

| Function | Input | Output | Description |
|----------|-------|--------|-------------|
| `InsertFirst(T)` | Data | Nothing | Inserts node at first position, updates `last->next` |
| `InsertLast(T)` | Data | Nothing | Inserts node at last position, maintains circular link |
| `InsertAtPos(T, int)` | Data, Position | Nothing | Inserts at given position |
| `DeleteFirst()` | None | Nothing | Deletes first node, re-links `last->next` to new first |
| `DeleteLast()` | None | Nothing | Deletes last node, re-links new last to first |
| `DeleteAtPos(int)` | Position | Nothing | Deletes node at given position |
| `Display()` | None | Prints list | Displays all nodes using count-based loop |
| `Count()` | None | Integer | Returns total node count |

### Doubly Linear Linked List — `DoublyLLL<T>`

| Function | Input | Output | Description |
|----------|-------|--------|-------------|
| `InsertFirst(T)` | Data | Nothing | Inserts at first, updates `prev` of old first |
| `InsertLast(T)` | Data | Nothing | Traverses to end, links `prev` of new node |
| `InsertAtPos(T, int)` | Data, Position | Nothing | Inserts at position, updates both `next` and `prev` |
| `DeleteFirst()` | None | Nothing | Deletes first node, sets new first's `prev` to NULL |
| `DeleteLast()` | None | Nothing | Traverses to second-last, sets its `next` to NULL |
| `DeleteAtPos(int)` | Position | Nothing | Deletes at position with proper re-linking |
| `Display()` | None | Prints list | Displays as `NULL<=> | data |<=> NULL` |
| `Count()` | None | Integer | Returns total node count |

### Doubly Circular Linked List — `DoublyCLL<T>`

| Function | Input | Output | Description |
|----------|-------|--------|-------------|
| `InsertFirst(T)` | Data | Nothing | Inserts at first, updates `last->next` and `first->prev` |
| `InsertLast(T)` | Data | Nothing | Inserts at last, maintains both circular `next` and `prev` |
| `InsertAtPos(T, int)` | Data, Position | Nothing | Inserts at position, updates all four surrounding links |
| `DeleteFirst()` | None | Nothing | Deletes first, re-links new first's `prev` to last |
| `DeleteLast()` | None | Nothing | Deletes last, re-links new last's `next` to first |
| `DeleteAtPos(int)` | Position | Nothing | Deletes at position, properly re-links neighbours |
| `Display()` | None | Prints list | Displays all nodes using count-based loop |
| `Count()` | None | Integer | Returns total node count |

### Stack — `Stack<T>`

| Function | Input | Output | Description |
|----------|-------|--------|-------------|
| `push(T)` | Data | Nothing | Inserts node at top using LIFO principle |
| `pop()` | None | Data (T) | Removes and returns top node's data |
| `peep()` | None | Data (T) | Returns top node's data without removing it |
| `Display()` | None | Prints stack | Displays all elements from top to bottom |
| `Count()` | None | Integer | Returns total element count |

### Queue — `Queue<T>`

| Function | Input | Output | Description |
|----------|-------|--------|-------------|
| `enqueue(T)` | Data | Nothing | Inserts node at rear using FIFO principle |
| `dequeue()` | None | Data (T) | Removes and returns front node's data |
| `Display()` | None | Prints queue | Displays all elements from front to rear |
| `Count()` | None | Integer | Returns total element count |

---

## How It Works — Step by Step

**Step 1 — Node Creation**
Each data structure has a dedicated node class (e.g., `SinglyLLLnode<T>`) that holds the data and the required pointers (`next` for singly, `next` + `prev` for doubly). The constructor initialises data and sets all pointers to `NULL`.

**Step 2 — Structure Initialisation**
Each data structure class is created by calling its default constructor, which sets `first` (and `last` where applicable) to `NULL` and `iCount` to 0.

**Step 3 — Insertion**
Nodes are inserted at the first position, last position, or any valid middle position. Boundary validation is performed, and `iCount` is incremented after every successful insertion.

**Step 4 — Deletion**
Nodes are deleted from the first position, last position, or any valid middle position. Boundary validation is performed, the target node is freed using `delete`, and `iCount` is decremented.

**Step 5 — Display and Count**
All elements are traversed and printed in a structured format. The total node count is returned from the maintained `iCount` variable.

---

## Demo — What `main()` Demonstrates

Each data structure is demonstrated in `main()` with the following sequence of operations:

| Step | Operation | Detail |
|------|-----------|--------|
| 1 | `InsertFirst` | Insert 3 elements at the front |
| 2 | `Display` + `Count` | Print list and node count |
| 3 | `InsertLast` | Insert 3 elements at the rear |
| 4 | `Display` + `Count` | Print updated list |
| 5 | `DeleteFirst` | Remove the first node |
| 6 | `Display` + `Count` | Print updated list |
| 7 | `DeleteLast` | Remove the last node |
| 8 | `Display` + `Count` | Print updated list |
| 9 | `InsertAtPos` | Insert a value at position 4 |
| 10 | `Display` + `Count` | Print updated list |
| 11 | `DeleteAtPos` | Delete node at position 4 |
| 12 | `Display` + `Count` | Print final list |

The Stack additionally demonstrates `push`, `peep`, and `pop`. The Queue demonstrates `enqueue` and `dequeue`.

---

## Data Types Used in Demo

| Data Structure | Data Type Used |
|---------------|---------------|
| Singly Linear Linked List | `int` |
| Singly Circular Linked List | `int` |
| Doubly Linear Linked List | `char` |
| Doubly Circular Linked List | `int` |
| Stack | `char` |
| Queue | `double` |

---

## How to Compile and Run

**Requirements:** Any C++ compiler supporting C++11 or later (g++, clang++, MSVC)

```bash
# Compile
g++ GeneralisedDataStructureLibrary.cpp -o DSLibrary

# Run
./DSLibrary
```

On Windows:
```bash
g++ GeneralisedDataStructureLibrary.cpp -o DSLibrary.exe
DSLibrary.exe
```

---

## Key Concepts Covered

- C++ Templates for Generic Programming
- Singly and Doubly Linked List Node Structure
- Linear vs Circular Linked List Pointer Management
- Boundary Validation for Position-Based Operations
- LIFO Principle — Stack Push, Pop, and Peep
- FIFO Principle — Queue Enqueue and Dequeue
- Dynamic Memory Allocation and Deallocation (`new` / `delete`)
- `prev` and `next` Pointer Maintenance in Doubly Variants
- Circular Link Integrity (`last->next = first`, `first->prev = last`)
- `iCount` Tracking for O(1) Count Operations
- `#pragma pack(1)` for Memory Alignment
- Constructor-Based Initialisation

---

## Author

**Laxmi Rahul Rathod**

Built as a C++ Data Structures project to understand the internal mechanics of linked lists, stacks, and queues — covering node-level pointer manipulation, generic programming with templates, and clean modular class design.
