# Greedy vs Dynamic Programming - When to Use Each

## Quick Decision Tree

```
Does the problem ask for:
│
├─ MAXIMUM/MINIMUM count or value?
│  └─ Can you make LOCAL optimal choice → GLOBAL optimal?
│     ├─ YES → Try GREEDY first
│     └─ NO → Try DP
│
├─ OPTIMAL SUBSTRUCTURE (optimal solution contains optimal subsolutions)?
│  └─ YES → DP is likely
│
└─ OVERLAPPING SUBPROBLEMS (same subproblems solved multiple times)?
   └─ YES → DP is likely
```

---

## GREEDY - Use When:

### ✅ Green Flags for Greedy:

1. **"Maximize/Minimize count"** - Assign, select, or schedule items
2. **Greedy Choice Property** - Making the best local choice leads to global optimum
3. **No "regret" later** - Once you make a choice, you never need to undo it
4. **Simple sorting works** - Sort by some criteria and pick greedily

### 📌 Classic Greedy Problems:

| Problem                                                                                | Approach                                          |
| -------------------------------------------------------------------------------------- | ------------------------------------------------- |
| **Assign Cookies**                                                               | Sort both arrays, match smallest with smallest    |
| **Activity Selection**                                                           | Sort by end time, pick earliest ending activities |
| **Jump Game**                                                                    | Greedy jump to farthest reachable position        |
| **Gas Station**                                                                  | Greedy try each starting point                    |
| **Interval Scheduling**                                                          | Sort by end time, pick non-overlapping            |
| **Coin Change <br />(when all the consecutive <br />possible coins are given)** | Greedy pick largest coin first                    |
| **Meeting Rooms**                                                                | Sort by start/end time                            |

---

## DYNAMIC PROGRAMMING - Use When:

### ✅ Green Flags for DP:

1. **"Find max/min/count of ways"** - with dependencies on previous states
2. **Optimal Substructure** - Best solution uses best solutions of subproblems
3. **Overlapping Subproblems** - Same calculations repeat
4. **Order matters** - Previous decisions affect future choices
5. **"Can you do this?" questions** - True/false with dependencies

### 📌 Classic DP Problems:

| Problem                                  | Why DP?                                           |
| ---------------------------------------- | ------------------------------------------------- |
| **Coin Change (exact amount)**     | Must try ALL combinations of coins                |
| **Fibonacci**                      | fib(n) = fib(n-1) + fib(n-2) (overlapping)        |
| **0/1 Knapsack**                   | Each item's inclusion depends on capacity         |
| **Longest Increasing Subsequence** | Best LIS ending at i depends on previous elements |
| **House Robber**                   | Rob(i) = max(Rob(i-1), Rob(i-2) + house[i])       |
| **Word Break**                     | Can word[0..i] be formed from dictionary?         |
| **Edit Distance**                  | Matching characters affects future choices        |

---

## Side-by-Side Comparison

| Aspect                | Greedy                  | DP                             |
| --------------------- | ----------------------- | ------------------------------ |
| **Decision**    | Make best choice NOW    | Try ALL choices, remember best |
| **Reconsider?** | Never                   | Yes (memoization)              |
| **Time**        | O(n log n) usually      | O(n²) or worse                |
| **Space**       | O(1) usually            | O(n) for memoization           |
| **Correctness** | ⚠️ Risky, needs proof | ✅ Usually safe                |

---

## Real Examples

### ❌ Why Coin Change Can't Be Greedy:

```
coins = [3, 4], amount = 6
Greedy: Pick 4 first → 4 + 3 = 7 (FAIL)
DP: Try both → 3 + 3 = 6 (SUCCESS)
```

### ✅ Why Assign Cookies IS Greedy:

```
g = [1,2,3], s = [1,1,3]
Greedy works: Match smallest greed with smallest cookie
  - Child 1 (g=1) gets cookie 1 ✓
  - Child 2 (g=2) gets cookie 2 ✗
  - Child 3 (g=3) gets cookie 3 ✓
  Result: 2 satisfied children (OPTIMAL)
```

---

## How to Decide in an Interview

1. **Read the problem carefully**

   - "Find minimum operations" → Usually DP
   - "Maximize selection" → Usually Greedy
2. **Try Greedy first** (it's easier)

   - Sort the input
   - Make obvious local choices
   - Does it work on examples?
3. **If Greedy fails**, switch to DP

   - Define state: `dp[i]` = best solution for i
   - Write recurrence: `dp[i] = f(dp[i-1], dp[i-2], ...)`
   - Use memoization or tabulation
4. **Test edge cases**

   - Single element
   - All same values
   - Reversed order

---

## Time Complexity Comparison

### Greedy Problems

- **Assign Cookies**: O(n log n + m log m)
- **Activity Selection**: O(n log n)
- **Jump Game**: O(n)

### DP Problems

- **Fibonacci**: O(n) with memoization
- **0/1 Knapsack**: O(n × W) where W is capacity
- **Longest Increasing Subsequence**: O(n²) or O(n log n)
- **Edit Distance**: O(m × n) where m, n are string lengths

---

## Key Takeaways

| When                                                             | Use This         |
| ---------------------------------------------------------------- | ---------------- |
| Need to**select** items to maximize/minimize something     | **Greedy** |
| Need to**count** ways or find **optimal dependency** | **DP**     |
| Problem has**greedy choice property**                      | **Greedy** |
| Problem can be**divided into overlapping subproblems**     | **DP**     |
| Solution builds on**previous decisions**                   | **DP**     |
| **Sorting helps** and order doesn't change optimality      | **Greedy** |

---

## Problem Solving Strategy

```
START
  │
  ├─ Can I use sorting to make greedy choices?
  │  └─ YES → Try greedy approach first
  │  
  ├─ Does problem ask "count all possibilities"?
  │  └─ YES → Likely DP
  │
  ├─ Does current choice affect future choices?
  │  └─ YES → DP needed
  │
  └─ Is there optimal substructure?
     └─ YES → DP is the way
```

---

## Common Mistakes

### ❌ Mistake 1: Using Greedy When DP is Needed

- **Example**: Coin Change problem
- **Fix**: Check if greedy works on all test cases first

### ❌ Mistake 2: Using DP When Greedy is Sufficient

- **Example**: Activity Selection
- **Fix**: Look for greedy choice property

### ❌ Mistake 3: Wrong Loop Condition (Common Bug)

```cpp
// WRONG
for (int i = 0; i < v2.size(), j < value.size(); i++)
//                            ^ comma instead of &&

// CORRECT
for (int i = 0; i < v2.size() && j < value.size(); i++)
//                            ^ use && for AND condition
```

The comma operator evaluates the left side, discards it, and uses the right side. This causes incorrect loop behavior.

---

## References

- LeetCode Problem Tags: Greedy, Dynamic Programming
- GeeksforGeeks: Greedy Algorithm
- LeetCode Editorial Solutions
