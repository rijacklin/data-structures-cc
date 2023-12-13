# Chapter 2: Array-Based Lists

### 2.1 | ArrayStack: Fast Stack Operations Using an Array

- Implements the List interface using a backing array.
  Ignoring the cost of calls to resize, an ArrayStack supports:

  - get(i) and set(i, x) in O(1) time per operation; and
  - add(i, x) and remove(i) in O(1 + n - i) time per operation

- Further, beginning with an empty ArrayStack, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  cost per resize operation (amortized analysis).

- Stack operations push(x) and pop() can be implemented as add(n, x) and
  remove(n -1), respectively, in O(1) amortized time.

### 2.2 | FastArrayStack: An Optimized ArrayStack

- Implements the List interface using a backing array.
  Ignoring the cost of calls to resize, an ArrayStack supports:

  - get(i) and set(i, x) in O(1) time per operation; and
  - add(i, x) and remove(i) in O(1 + n - i) time per operation

- Further, beginning with an empty ArrayStack, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  cost per resize operation (amortized analysis).

- Stack operations push(x) and pop() can be implemented as add(n, x) and
  remove(n -1), respectively, in O(1) amortized time.

### 2.3 | ArrayQueue: An Array-Based Queue

- Implements the (FIFO) Queue interface using a backing array.
  Allows for efficient addition to one end of the sequence and removal from
  the other end.

- Elements are removed (using remove()) in the same order they are added (using
  add(x))

- Ignoring the cost of calls to resize, an ArrayStack supports:

  - add(x) and remove() in O(1) time per operation

- Further, beginning with an empty ArrayQueue, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  cost per resize operation (amortized analysis).

- Using modular arithmetic, array queue simulates an infinite array as
  i % a.length always gives a value in the range 0, ..., a.length - 1.

- Array a is treated like a circular array in which indices larger than
  a.length - 1 "wrap around" to the beginning of the array.

### 2.4 | ArrayDequeue: Fast Deque Operations Using an Array

- Implements the List interface by using the same circular array technique
  used to represent an ArrayQueue.

- Allows for efficient addition and removal at both ends.

- Ignoring the cost of calls to resize, an ArrayDequeue supports:

  - get(i) and set(i, x) in O(1) time per operation; and
  - add(i, x) and remove(i) in O(1 + min{i, n - i}) time per operation

- Further, beginning with an empty ArrayDequeue, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  cost per resize operation (amortized analysis).

### 2.5 | DualArrayDequeue: Building a Deque from Two Stacks

- Achieves the same performance bounds as an ArrayDequeue by using two
  ArrayStacks.

- Represents a List using two ArrayStacks. As an ArrayStack is fast when its
  operations modify elements near the end, a DualArrayDequeue places two
  ArrayStacks back-to-back so that operations are fast on either end.

- Ignoring the cost of calls to resize() and balance(), an ArrayDequeue
  supports:

  - get(i) and set(i, x) in O(1) time per operation; and
  - add(i, x) and remove(i) in O(1 + min{i, n - i}) time per operation

- Further, beginning with an empty DualArrayDequeue, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  spent during all calls to resize() and balance().

### 2.6 | RootishArrayStack: A Space-Efficient Array Stack

- Addresses the problem of wasted space by storing n elements in O(sqrt(n))
  arrays where at most O(sqrt(n)) array locations are unused at any time.

- As all the remaining array locations are used to store data, these data
  structures waste at most O(sqrt(n)) space when storing n elements.

- This data structure stores its elements in a list of r arrays called `blocks`
  that are numbered [0, 1, ..., r - 1]. Block b contains b + 1 elements.

- Ignoring the cost of calls to grow() and shrink(), an ArrayDequeue
  supports:

  - get(i) and set(i, x) in O(n - i) time per operation; and
  - add(i, x) and remove(i) in O(n - i) ime per operation

- Further, beginning with an empty RootishArrayStack, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  spent during all calls to grow() and shrink().

- After a call to grow() or shrink(), the final block is completely empty and
  all other blocks are completely full. Another call to grow() or shrink() will
  not happen until at least r - 1 elements are added or removed.

- Therefore, even if grow() or shrink() take O(r) time, this cost can be
  amortized over at least one r - 1 add(i, x) or remove(i) operations, so that
  the amortized cost of grow() and shrink() is O(1) per operation.
