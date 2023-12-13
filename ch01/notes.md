# Chapter 1 Notes

## Data Structures

### Interface vs. Implementation

An **interface** describes what a data structure is doing (add, remove, resize,
etc.).

An **implementation** describes how the data structure does it.

### Set

- Unordered collection of distinct elements.
- Supported operations:
  - add(x)
  - remove(x)
  - contains(x)

### Sorted Set

- A Set in which the elements are stored in sorted order.
- Iteration works in sorted order
- Supported operations:
  - add(x)
  - remove(x)
  - contains(x)
  - first() - smallest item in Set
  - last() - largest item in Set

### List

- Order matters.
- Represents a sequence of elements indexed by integers.
  - [1, 2, ..., n-1]
- Supported operations:
  - get(i)
  - set(i, x)
  - add(i, x) - Elements are shifted right (indexes increase)
  - add(x) - Adds only to the end
  - remove(i) - Elements greater than i are shifted left (indexes decrease)

### Queue

- Supports two operations:
  - add(x)
  - remove() - Returns item based on queueing discipline
- Queuing disciplines:
  - FIFO (first-in-first-out)
  - LIFO (also called a Stack)
  - Priority Queue (Smallest element removed)

### Dequeue

- Short for "double-ended queue".
- Supports four operations:
  - addFirst(x)
  - addLast(x)
  - removeFirst()
  - removeLast()
- Think of `first` as furthest left (index 0) and `last` as furthest right
  (index n).

### Map

- Maps a set of keys (unique) onto values.
- Supports four operations:
  - get(k) - Returns the value associated with the key (k)
  - put(k, v) - Associates the value (v) with the key (k)
  - remove(k) - Removes the key (k) from the key set
  - containsKey(k) - Can be used as a guard (ex. check before get(k))

### Sorted Map

- A Map in which the key set is a sorted set.

## C++ STD Template Library Classes

### Queue

- FIFO
- [Reference](https://cplusplus.com/reference/queue/queue/)

### Deque

- Double-ended Queue
- [Reference](https://cplusplus.com/reference/deque/deque/)

### Stack

- LIFO
- [Reference](https://cplusplus.com/reference/stack/stack/)

### SSet

- Ordered Set
- [Reference](https://cplusplus.com/reference/set/set/)

### USSet

- Unordered Set
- [Reference](https://cplusplus.com/reference/unordered_set/unordered_set/)
