# Priority Queue in C++ (Short)

`priority_queue` is a container adaptor in C++ STL that always keeps the **highest-priority element** at the top.

## What It Does

- Insert elements with `push()`
- Remove top element with `pop()`
- Access top element with `top()`
- Typical use: where you repeatedly need largest/smallest quickly

## Default Initialization (Max Heap)

```cpp
priority_queue<int> pq;
```

- Largest element comes first (`top()` gives max)

## Min Heap Initialization

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

- <type,operator,comperator>
- Smallest element comes first (`top()` gives min)

## Tiny Example

```cpp
priority_queue<int> maxPQ;
maxPQ.push(10);
maxPQ.push(3);
maxPQ.push(25);
// maxPQ.top() == 25

priority_queue<int, vector<int>, greater<int>> minPQ;
minPQ.push(10);
minPQ.push(3);
minPQ.push(25);
// minPQ.top() == 3
```

## Time Complexity

- `push`: `O(log n)`
- `pop`: `O(log n)`
- `top`: `O(1)`
