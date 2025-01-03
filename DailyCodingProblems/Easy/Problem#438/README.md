# Stack Implementation Using a Heap

This project implements a **stack** data structure using a **heap**. The stack operates on a Last-In-First-Out (LIFO) principle, while a heap operates on a maximum or minimum priority principle. To bridge this difference, we use timestamps to track the order of elements pushed onto the stack and leverage the heap's properties for efficient stack operations.

---

## Problem Statement
A stack implements the following methods:

1. **`push(item)`**: Adds an element to the stack.
2. **`pop()`**: Removes and returns the most recently added element (or raises an error if the stack is empty).

We are tasked to implement the stack behavior using only a heap, which natively provides:

1. **`push(item)`**: Adds a new key to the heap.
2. **`pop()`**: Removes and returns the max (or min) value of the heap.

---

## Solution Approach
To mimic a stack's LIFO behavior using a heap, we:

1. **Use a Max Heap:**
   - Python's `heapq` provides a min-heap by default. To simulate a max-heap, we store negative priorities.

2. **Assign Timestamps:**
   - A `timestamp` counter is used to track the order of elements pushed onto the stack. The most recently added element (highest timestamp) is prioritized.

3. **Heap Elements:**
   - Each element is stored as a tuple: `(-timestamp, value)`. The negative timestamp ensures that the most recent element is always at the top of the heap.

---

## Explanation of Key Methods

### `push(item)`
- Increments the `timestamp` to ensure each element has a unique priority.
- Adds a tuple `(-timestamp, item)` to the heap, with the negative timestamp ensuring max-heap behavior.

### `pop()`
- Removes and returns the element with the highest timestamp (i.e., the most recently added element).
- If the heap is empty, raises an `IndexError`.

### `__repr__()`
- Provides a human-readable representation of the stack, showing its contents in order of insertion (latest at the end).

---

## Complexity Analysis

1. **`push` Operation:**
   - Time complexity: **O(log n)**, where `n` is the number of elements in the stack. This is the cost of adding an element to the heap.

2. **`pop` Operation:**
   - Time complexity: **O(log n)**, as it involves removing the max element from the heap.

3. **Space Complexity:**
   - **O(n)**, for storing `n` elements in the heap.

---

## Edge Cases

1. **Empty Stack:**
   - Calling `pop` on an empty stack raises an `IndexError`.

2. **Order Preservation:**
   - The stack correctly returns elements in LIFO order regardless of the number of operations performed.

---

## Conclusion
This implementation demonstrates how to combine the properties of a heap and a timestamp to emulate stack behavior. It efficiently handles stack operations with logarithmic time complexity, making it a practical and scalable solution.

Feel free to experiment with the code and adapt it to your needs!
