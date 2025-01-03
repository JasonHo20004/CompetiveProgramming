# This problem was asked by Amazon.

# Implement a stack API using only a heap. A stack implements the following methods:

# push(item), which adds an element to the stack
# pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)
# Recall that a heap has the following operations:

# push(item), which adds a new key to the heap
# pop(), which removes and returns the max value of the heap

import heapq

class StackUsingHeap:
    def __init__(self):
        self.heap = [] # Create heap to store elements
        self.timestamp = 0  # Timestamp to track the order of elements
    
    def push(self, item):
        self.timestamp += 1
        heapq.heappush(self.heap,(-self.timestamp, item))
    
    def pop(self):
        if not self.heap:
            raise IndexError("pop from an empty stack")
        
        _, value = heapq.heappop(self.heap)
        return value
    
    def __repr__(self):
        return str([item for _, item in sorted(self.heap, reverse=True)])
    
stack = StackUsingHeap()
stack.push(10)
stack.push(20)
stack.push(8)

print("Stack after push: ", stack)
print("Popped item: ", stack.pop())
print("Stack after pop:", stack)