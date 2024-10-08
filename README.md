# C++ Standard Template Library (STL)

This library provides custom implementations of various common data structures including Singly Linear Linked List, Singly Circular Linked List, Doubly Linear Linked List, Doubly Circular Linked List, Stack, and Queue. Each data structure comes with a comprehensive set of functions to manipulate and access the data.

## Contents

### Singly Linear Linked List

A singly linear linked list is a collection of nodes where each node contains data and a pointer to the next node in the sequence.

#### Functions

- **InsertFirst**: Insert a node at the beginning.
- **InsertLast**: Insert a node at the end.
- **InsertAtPos**: Insert a node at a specified position.
- **DeleteFirst**: Remove the first node.
- **DeleteLast**: Remove the last node.
- **DeleteAtPos**: Remove a node from a specified position.
- **Display**: Display the contents of the list.
- **Count**: Count the number of nodes in the list.

### Singly Circular Linked List

A singly circular linked list is similar to a singly linear linked list, except the last node points back to the first node, forming a circle.

#### Functions

- **InsertFirst**: Insert a node at the beginning.
- **InsertLast**: Insert a node at the end.
- **InsertAtPos**: Insert a node at a specified position.
- **DeleteFirst**: Remove the first node.
- **DeleteLast**: Remove the last node.
- **DeleteAtPos**: Remove a node from a specified position.
- **Display**: Display the contents of the list.
- **Count**: Count the number of nodes in the list.

### Doubly Linear Linked List

A doubly linear linked list is a collection of nodes where each node contains data, a pointer to the next node, and a pointer to the previous node.

#### Functions

- **InsertFirst**: Insert a node at the beginning.
- **InsertLast**: Insert a node at the end.
- **InsertAtPos**: Insert a node at a specified position.
- **DeleteFirst**: Remove the first node.
- **DeleteLast**: Remove the last node.
- **DeleteAtPos**: Remove a node from a specified position.
- **Display**: Display the contents of the list.
- **Count**: Count the number of nodes in the list.

### Doubly Circular Linked List

A doubly circular linked list is similar to a doubly linear linked list, except the last node's next pointer points back to the first node and the first node's previous pointer points back to the last node.

#### Functions

- **InsertFirst**: Insert a node at the beginning.
- **InsertLast**: Insert a node at the end.
- **InsertAtPos**: Insert a node at a specified position.
- **DeleteFirst**: Remove the first node.
- **DeleteLast**: Remove the last node.
- **DeleteAtPos**: Remove a node from a specified position.
- **Display**: Display the contents of the list.
- **Count**: Count the number of nodes in the list.

### Stack

A stack is a Last In First Out (LIFO) data structure where elements are added and removed from the same end.

#### Functions

- **Push**: Add an element to the top of the stack.
- **Pop**: Remove the top element from the stack.
- **IsEmpty**: Check if the stack is empty.
- **Display**: Display the contents of the stack.
- **Count**: Count the number of elements in the stack.

### Queue

A queue is a First In First Out (FIFO) data structure where elements are added at the back and removed from the front.

#### Functions

- **Enqueue**: Add an element to the back of the queue.
- **Dequeue**: Remove an element from the front of the queue.
- **IsEmpty**: Check if the queue is empty.
- **Display**: Display the contents of the queue.
- **Count**: Count the number of elements in the queue.

- ### Sorting Algorithms

#### Bubble Sort

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

##### Functions

- **BubbleSort**: Sort the elements in ascending order using Bubble Sort.

#### Selection Sort

Selection Sort is a simple sorting algorithm that divides the input list into two parts: the sublist of items already sorted and the sublist of items remaining to be sorted.

##### Functions

- **SelectionSort**: Sort the elements in ascending order using Selection Sort.

#### Insertion Sort

Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time.

##### Functions

- **InsertionSort**: Sort the elements in ascending order using Insertion Sort.
- 
## Algorithms Implemented

### Linear Search

Linear Search is the simplest search algorithm. It checks each element in the list sequentially until the desired element is found or the list ends.

- **Time Complexity**: O(n)
- **STL Function Used**: `std::find`

### Bidirectional Search

Bidirectional Search operates by simultaneously searching forward from the start of the list and backward from the end. This technique can be more efficient for large datasets compared to linear search but is less commonly used due to its complexity.

- **Time Complexity**: O(n) (best case can be faster if the target is near the ends)
- **Custom Implementation**: A custom function that combines forward and backward searches.

### Binary Search

Binary Search is a highly efficient algorithm for finding an element in a sorted list. It repeatedly divides the search interval in half, eliminating half of the remaining elements with each step.

- **Time Complexity**: O(log n)
- **STL Function Used**: `std::binary_search`, `std::lower_bound`, `std::upper_bound`

