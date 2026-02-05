# How to Calculate Time Complexity (Big-O)

This note explains how to estimate the **time complexity** of a function from **basic → advanced**, with practical **tips & tricks**.

---

## 0) What time complexity means

- **Time complexity** describes how the runtime grows as input size $n$ grows.
- We typically report **worst-case** Big-O: $O(\cdot)$.
- Think: “If I double $n$, how does work grow?”

### Big-O quick rules

- Ignore constants: $O(2n) \rightarrow O(n)$
- Keep the dominant term: $O(n^2 + n) \rightarrow O(n^2)$
- Different inputs matter: $O(nm)$ is not the same as $O(n^2)$ unless $m = n$.

---

## 1) Common complexities (memorize)

- **$O(1)$**: constant work (single access, a few arithmetic ops)
- **$O(\log n)$**: repeatedly halving/doubling (binary search)
- **$O(n)$**: one pass
- **$O(n \log n)$**: divide & conquer / efficient sorting
- **$O(n^2)$**: nested loops over $n$
- **$O(2^n)$**: subset generation / brute-force recursion
- **$O(n!)$**: permutations / brute-force arrangements

---

## 2) Basic method (works for most code)

### Step A: Identify the input size(s)

- For arrays/strings: $n = \text{length}$
- For matrices: $n = \text{rows}$, $m = \text{cols}$ (often report $O(nm)$)
- For graphs: $V = \#vertices$, $E = \#edges$

### Step B: Count the “dominant operations”

Dominant operations are the ones inside the deepest loops / most repeated parts.

### Step C: Add, multiply, and simplify

- **Sequential blocks add**: `block1 + block2` → $O(a) + O(b) = O(a+b)$ → simplify to dominant.
- **Nested blocks multiply**: inner runs fully for each outer iteration.

---

## 3) Iteration: from easy to tricky

### 3.1 Single loop

```cpp
for (int i = 0; i < n; i++) {
    // O(1)
}
```

Time: **$O(n)$**

### 3.2 Nested loops

```cpp
for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
    ;
```

Time: **$O(n^2)$**

### 3.3 Triangular loops (still $O(n^2)$)

```cpp
for (int i = 0; i < n; i++)
  for (int j = 0; j < i; j++)
    ;
```

Work: $1 + 2 + \dots + (n-1) = \frac{n(n-1)}{2}$ → **$O(n^2)$**

### 3.4 Two independent loops (add)

```cpp
for (int i = 0; i < n; i++) ;
for (int j = 0; j < m; j++) ;
```

Time: **$O(n + m)$**

### 3.5 Loop variable changes by factor (log)

```cpp
for (int i = 1; i < n; i *= 2) ;
```

Time: **$O(\log n)$** (doubling)

```cpp
for (int i = n; i > 0; i /= 2) ;
```

Time: **$O(\log n)$** (halving)

### 3.6 Mixed loops: $n \log n$

```cpp
for (int i = 0; i < n; i++)
  for (int j = 1; j < n; j *= 2)
    ;
```

Time: **$O(n \log n)$**

### 3.7 Loops where the pointer only moves forward (two pointers)

```cpp
int i = 0, j = 0;
while (i < n && j < n) {
    if (condition) i++;
    else j++;
}
```

Even though there are two “moving indices”, each moves at most $n$ times → **$O(n)$**.

---

## 4) Conditionals and early returns

```cpp
if (x) {
  // O(n)
} else {
  // O(n^2)
}
```

Worst-case time: **$O(n^2)$**.

If a function sometimes returns early, Big-O still typically reports worst-case unless asked for average/best-case.

---

## 5) Recursion: how to analyze

### 5.1 Recognize the recurrence

Try to express runtime as:

$$
T(n) = a\,T(n/b) + f(n)
$$

or

$$
T(n) = T(n-1) + f(n)
$$

### 5.2 Common recursion patterns

**(A) One call reducing by 1**

```cpp
f(n) { return f(n-1) + O(1); }
```

$T(n) = T(n-1) + O(1)$ → **$O(n)$**

**(B) Two calls reducing by 1 (Fibonacci-style)**

```cpp
f(n) { return f(n-1) + f(n-2); }
```

Exponential without memoization → roughly **$O(2^n)$**.

**(C) Divide and conquer**

```cpp
f(n) {
  f(n/2);
  f(n/2);
  // O(n)
}
```

$T(n) = 2T(n/2) + O(n)$ → **$O(n \log n)$**.

### 5.3 Master Theorem (quick reference)

For $T(n)=aT(n/b)+f(n)$ compare $f(n)$ with $n^{\log_b a}$:

- If $f(n) = O(n^{\log_b a - \epsilon})$ → $T(n)=\Theta(n^{\log_b a})$
- If $f(n) = \Theta(n^{\log_b a}\log^k n)$ → $T(n)=\Theta(n^{\log_b a}\log^{k+1} n)$
- If $f(n) = \Omega(n^{\log_b a + \epsilon})$ (regularity holds) → $T(n)=\Theta(f(n))$

Don’t stress memorizing all details—use it mainly for common forms like mergesort.

---

## 6) DP changes time complexity (important intuition)

Many exponential recursions become polynomial once you **memoize** overlapping subproblems.

Example idea:

- Without memoization: states repeat → exponential
- With memoization: each state computed once → `#states × transition_cost`

Rule of thumb:

- If your DP state is `dp[i]` for $i \in [0..n]$ and each transition is $O(1)$ → **$O(n)$**.
- If your DP state is `dp[i][j]` over an $n \times m$ grid and each transition is $O(1)$ → **$O(nm)$**.

---

## 7) Data structures: typical costs (Big-O)

These are common in complexity analysis:

- Array access by index: **$O(1)$**
- Unsorted array search: **$O(n)$**
- Sorted array binary search: **$O(\log n)$**
- Sorting (comparison-based): **$O(n \log n)$**
- `unordered_map`/hash table: average **$O(1)$**, worst **$O(n)$** (rare in practice)
- `map`/balanced BST: **$O(\log n)$** per insert/find
- Heap operations (priority queue push/pop): **$O(\log n)$**

---

## 8) Advanced topics

### 8.1 Amortized analysis (average over operations)

Some operations are expensive occasionally, but cheap on average.

- Example: dynamic array/vector push_back is **amortized $O(1)$**.

### 8.2 Average vs worst-case

- Worst-case is safest for interviews.
- Mention average-case if the problem explicitly asks or if hashing is involved.

### 8.3 Multiple parameters (don’t force everything into n)

- Matrix: $O(nm)$
- Graph traversals: BFS/DFS are **$O(V+E)$**

### 8.4 Output-sensitive complexity

If you must output $k$ items, runtime is at least **$\Omega(k)$**.

- Example: printing all subsets outputs $2^n$ subsets → cannot be faster than $\Omega(2^n)$.

---

## 9) Tips & tricks (high value in interviews)

- **Name your input sizes** first (`n`, `m`, `V`, `E`).
- **Count loops carefully**: nested = multiply, sequential = add.
- **Look for factor change** (`i*=2`, `i/=2`) → logs.
- **Two pointers** often collapses nested-looking logic into **$O(n)$**.
- **DP complexity = states × transitions** (say this out loud).
- **Recursion**: write the recurrence $T(n)$ and expand a few levels.
- **Stop at Big-O** unless asked for exact counts.
- **Don’t forget hidden costs**: sorting inside a loop, copying strings/vectors, map operations.
- If you see **brute force over subsets/permutations**, you’re in **$2^n$ / $n!$** territory.

---

## 10) Quick practice mini-check

1) `for (i=0..n)` with constant work → $O(n)$
2) nested `for (i=0..n) for (j=0..i)` → $O(n^2)$
3) `while (n>0) n/=2` → $O(\log n)$
4) recursion `T(n)=T(n-1)+n` → $O(n^2)$
5) DP with $n*m$ states and O(1) transition → $O(nm)$
