# Chapter 2: Array-Based Lists

## Summary of Running Times

| Structure         | get(i)/set(i,x) | add(i,x)/remove(i) |
| ----------------- | --------------- | ------------------ |
| ArrayStack        | O(1)            | O(n−i)             |
| ArrayDeque        | O(1)            | O(min{i,n−i})      |
| DualArrayDeque    | O(1)            | O(min{i,n−i})      |
| RootishArrayStack | O(1)            | O(n−i)             |

## Advantages and Limitations

Data structures that work by storing data in a single array have many advantages
and limitations in common:

1. Arrays offer constant time access to any value in the array. This is what
   allows get(i) and set(i, x) to run in constant time (O(1)).
2. Arrays are not very dynamic. Adding or removing an element near the middle of
   the list requires shifting elements. This is why the operations add(i, x) and
   remove(i) have running times that depend on n and i.
3. Arrays cannot expand or shrink. When the number of elements exceeds the size
   of the backing array, a new array must be created and the data from the old
   array copied into it. This is an expensive operation.

Due to point 3, the running times in the table above do not include the cost
associated with growing or shrinking the backing array. Although the cost is
expensive for individual operations, the total cost of growing and shrinking is
amortized over m operations.

---

## 2.1 | ArrayStack: Fast Stack Operations Using an Array

- Implements the List interface using a backing array.

  - Implementing a List interface requires that the data structure implements the
    following operations:
    - get(i)
    - set(i, x)
    - add(i, x)
    - remove(i)

- At most times, a is larger than strictly necessary, so an integer n is used to
  keep track of the number of elements actually stored in a. In this way, the
  list elements are stored in a[0], ..., a[n-1], and at all times a.length >= n.

### Theorem

- Implements the List interface.

- Ignoring the cost of calls to resize, an ArrayStack supports:

  - get(i) and set(i, x) in O(1) time per operation; and
  - add(i, x) and remove(i) in O(1 + n - i) time per operation

- Furthermore, if we start with an empty ArrayStack, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  cost per resize operation (amortized analysis).

### Proof

### Two Cases in Which Resize Occurs

1. During an add operation, the array is full (n = a.length).

   - Call to resize() will copy n values.
   - Assuming the array was half full (n/2) last time resize was called, we know
     that at least n/2 add operations have occurred before the call to resize().

2. During a remove operation, the array is 1/3 full (n = a.length/3).

   - Call to resize() will copy n values.
   - Assuming the array is 1/3 full, subracting 1/3 from 1/2 (the number of n/2
     remove operations), we know that there were 1/6 (a.length / 6) values
     removed.
   - Therefore, at least n/2 remove operations occurred before the call to
     resize().

### Calculations

- To calculate the amortized cost of resize():

  - The total number of items copied: N = n_1 + n_2 + ...
  - The total number of add/remove operations: m >= {n_1}/2 + {n_2}/2 + ...
    - or: m >= N/2

- This means at least half the number of items copied by calls to resize, or,
  the total number of items copied by calls to resize is at most twice the
  number of add/remove operations (at most 2m / O(m)).

- Since all of the work done by resize is bounded by the number of items copied,
  we conclude that the total time spent in calls to resize is O(m).

- Stack operations push(x) and pop() can be implemented as add(n, x) and
  remove(n-1), respectively, in O(1) amortized time.

---

## 2.2 | FastArrayStack: An Optimized ArrayStack

- Same as ArrayStack above but uses the more efficient C++ standard library
  function `std::copy(a0, a1, b)` for copying operations.

- Although the function does not asymptotically decrease the running time, it
  can stil be a worthwhile optimization.

---

## 2.3 | ArrayQueue: An Array-Based Queue

- Implements the (FIFO) Queue interface using a backing array.

- Allows for efficient addition to one end of the sequence and removal from
  the other end.

  - `n` is the number of elements in the data structure.
  - `j` is the head of the Queue.
  - `j + n - 1` is the (implicit) tail of the Queue.
  - All of the values in between the head and tail are represented by modulo
    a.length (the elements wrap around the ends as necessary).

- Elements are removed (using remove()) in the same order they are added (using
  add(x))

### Theorem

- Implements the (FIFO) Queue interface.

- Ignoring the cost of calls to resize, an ArrayQueue supports:

  - add(x) and remove() in O(1) time per operation

- Furthermore, beginning with an empty ArrayQueue, performing any sequence of m
  add(x) and remove() operations results in a total of O(m) time cost per resize
  operation (amortized analysis).

### Calculations

- Using modular arithmetic, array queue simulates an infinite array as
  i % a.length always gives a value in the range 0, ..., a.length - 1.

  - `a === r (mod n)` can be written as `a = k * n + r` (where r is remainder).
  - Solving this equation, `a - r = k * n` or `n / (a - r)` (meaning `a - r` is
    a multiple of n).

- Array a is treated like a circular array in which indices larger than
  a.length - 1 "wrap around" to the beginning of the array.

---

## 2.4 | ArrayDequeue: Fast Deque Operations Using an Array

- Implements the full List interface by using the same circular array technique
  used to represent an ArrayQueue:

  - get(i) | return a[j+i % a.length]
  - set(i, x) | a[j+i % a.length] = x
  - add(i, x) | Check if resize() needed, if i < n/2 shift elements left,
    otherwise shift elements right, then set the index to x and increment n.
  - remove(i) |

- Allows for fast / efficient addition and removal at both ends.

  - `n` is the number of elements in the data structure.
  - `j` is the head of the Queue.
  - `j + n - 1` is the (implicit) tail of the Queue.
  - All of the values in between the head and tail are represented by modulo
    a.length (the elements wrap around the ends as necessary).

### Theorem

- Implements the List interface.

- Ignoring the cost of calls to resize, an ArrayDequeue supports:

  - get(i) and set(i, x) in O(1) time per operation; and
  - add(i, x) and remove(i) in O(1 + min{i, n - i}) time per operation

- Furthermore, beginning with an empty ArrayDequeue, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  cost per resize operation (amortized analysis).

---

## 2.5 | DualArrayDequeue: Building a Deque from Two Stacks

- Achieves the same performance bounds as an ArrayDequeue by using two
  ArrayStacks.

- Represents a List using two ArrayStacks. As an ArrayStack is fast when its
  operations modify elements near the end, a DualArrayDequeue places two
  ArrayStacks back-to-back so that operations are fast on either end.

- Balancing the two ArrayStacks ensures that, unless there are fewer than 2
  elements, both front and back each contain at least n/4 elements.

  - If this condition is not met (there are less than n/4 elements in one of
    the arrays and more than 3n/4 in the other), balance() moves elements
    between the two arrays so that front and back each contain as close to n/2
    elements as is possible (accounting for odd values of n).

### Theorem

- Implements the List interface.

- Ignoring the cost of calls to resize() and balance(), an ArrayDequeue
  supports:

  - get(i) and set(i, x) in O(1) time per operation; and
  - add(i, x) and remove(i) in O(1 + min{i, n - i}) time per operation

- Furthermore, beginning with an empty DualArrayDequeue, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  spent during all calls to resize() and balance().

### Calculations

- The potential of a DualArrayDequeue is the difference between the size of the
  front array and the back array:

  - $$\phi = |front.size() - back.size()|$$

- If the ArrayStacks are balanced, the potential is no more than 1 (0 for an
  even number of n elements, 1 for an odd number of n elements).

- If the ArrayStacks are not balanced (less than n/4 elements in one and greater
  than 3n/4 elements in the other), then the potential is at least n/2
  ($$\phi > 2$$).

- Observation:

  - A call to an add or remove operation that does not trigger a call to
    balance() can increase the potential by at most 1.

  - Immediately after a call to balance() that shift the elements, the potential
    is at most 1, since:

    - $$ \phi_0 = |[n/2]-[n/2]| \leq 1 $$

  - Considering a situation where immediately before a call to balance(), the
    call is occurring because $$ 3\*front.size() < back.size() $$. Notice that
    in this case,

    - $$
        \begin{aligned}
            n = front.size() + back.size() < back.size()/3 + back.size()
              = \frac{4}{3} back.size()
        \end{aligned}
      $$

  - Furthermore, the potential at this point in time is,

    - $$
        \begin{aligned}
            \phi_1 = back.size() - front.size() > back.size() - back.size()/3
                   = \frac{2}{3} back.size() > \frac{2}{3} * \frac{3}{4}n
                   = n/2
        \end{aligned}
      $$

  - Therefore, the number of calls to add or remove since the last call to
    balance() is at least $$ \phi_1 - \phi_0 > \frac{n}{2} - 1 $$.

---

## 2.6 | RootishArrayStack: A Space-Efficient Array Stack

- Addresses the problem of wasted space by storing n elements in O(sqrt(n))
  arrays where at most O(sqrt(n)) array locations are unused at any time.

- As all the remaining array locations are used to store data, these data
  structures waste at most O(sqrt(n)) space when storing n elements.

- This data structure stores its elements in a list of r arrays called `blocks`
  that are numbered [0, 1, ..., r - 1]. Block b contains b + 1 elements.

  - b = index of the subarray A that contains index i.
  - j = index in A of the element at list index i.
    = $$ \frac{i - b(b - 1)}{2} $$

- When performing a check for a call to shrink() when removing an element, we
  only call shrink() if there is greater than 1 empty array.

  - If we attempt to call shrink() when there is exactly 1 empty array, we will
    end up with a **thrashing** problem. Each call to add and remove will take
    sqrt(n) time instead constant time because we have to continuously allocate
    and deallocate the array.

### Quadractic Equation Calculation (i2b)

- The first b+1 lists contain: $$ \frac{(b+1)(b+2)}{2} $$ elements. We want the
  smallest b such that: $$ \frac{(b+1)(b+2)}{2} \geq i+1 $$.

  - This is a quadratic equation in the variable b.
  - It can be written as: $$ b^2 + 3b - 2i = 0 $$.
       $$ b = \frac{3 + \sqrt(9 + 8i)}{2} $$
  - We use the `ceil()` function to truncate the decimals on the index value.

### Theorem

- Has the same performance (at least asymptotically) as ArrayStack, but uses
  only sqrt(n) wasted space.

- Ignoring the cost of calls to grow() and shrink(), an ArrayDequeue
  supports:

  - get(i) and set(i, x) in O(n - i) time per operation; and
  - add(i, x) and remove(i) in O(n - i) ime per operation

- Furthermore, beginning with an empty RootishArrayStack, performing any sequence
  of m add(i, x) and remove(i) operations results in a total of O(m) time
  spent during all calls to grow() and shrink().

- After a call to grow() or shrink(), the final block is completely empty and
  all other blocks are completely full. Another call to grow() or shrink() will
  not happen until at least r - 1 elements are added or removed.

- Therefore, even if grow() or shrink() take O(r) time, this cost can be
  amortized over at least one r - 1 add(i, x) or remove(i) operations, so that
  the amortized cost of grow() and shrink() is O(1) per operation.

### Theorem on why sqrt(n) is the lower bound

- Any data structure that supports any type of add operation must use \Ohm(sqrt(n))
  (some constant(sqrt(n)) wasted space.

### Proof

- Take a data structure and add n elements to it.

- Case 1: The data structure uses more than sqrt(n) arrays means it uses more
  than sqrt(n) pointers.

- Case 2: The data structure uses at most sqrt(n) arrays means at least one
  array has size at least n/k. As $$ n/k \geq n/sqrt(n) \geq sqrt(n) $$.

  - This means that when this array was allocated, it was sqrt(n) wasted
    space.
