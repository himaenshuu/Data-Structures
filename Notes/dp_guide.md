# Dynamic Programming (DP) Guide

## 🎯 When to Use DP? - Key Indicators

Use Dynamic Programming when you identify:

### 1. **Optimization Problems**
- Finding minimum/maximum (cost, path, sum, ways)
- "What is the best way to..."
- **Keywords**: `optimal`, `minimize`, `maximize`, `best`, `least`, `most`, `shortest`, `longest`

### 2. **Counting Problems**
- "How many ways to..."
- "Count the number of..."
- **Keywords**: `count`, `number of ways`, `total ways`, `distinct ways`, `combinations`

### 3. **Decision Making**
- At each step, you have choices (take/not take, left/right, use/skip)
- Each choice affects future possibilities
- **Keywords**: `choose`, `select`, `pick`, `include/exclude`, `decision`

### 4. **Overlapping Subproblems**
- Solving the same smaller problem multiple times
- Example: In Fibonacci, `f(5)` needs `f(4)` and `f(3)`, but `f(4)` also needs `f(3)`
- If you're solving recursively and seeing repeated calls → DP candidate
- **Keywords**: `recursive`, `repeated`, `subproblems`

### 5. **Optimal Substructure**
- Solution to problem can be built from solutions of subproblems
- "If I knew the answer for n-1, can I find answer for n?"
- **Keywords**: `depends on previous`, `build from smaller`, `subproblem solutions`

---

## 🧠 Early Intuition Checklist

Ask yourself these questions:

✅ Can I break this into **smaller versions** of the same problem?  
✅ Am I solving the **same subproblem** multiple times?  
✅ Does the problem involve **choices** at each step?  
✅ Am I looking for **optimal/count/possible** answers?  
✅ Keywords: "maximum", "minimum", "count ways", "longest", "shortest"

**If 3+ are YES → Consider DP!**

---

## 🔄 Recursion (Memoization) vs Tabulation

### **Memoization (Top-Down)**
```
✓ Start from main problem → break into subproblems
✓ Use recursion + cache (dp array/map)
✓ Easier to think and code initially
✓ Only computes needed subproblems
```

**When to Use:**
- Natural recursive structure is clear
- Not all subproblems need to be solved
- Complex state dependencies
- Easier to convert from brute force recursion

**Code Pattern:**
```cpp
int solve(int n, vector<int>& dp) {
    if (base_case) return value;
    if (dp[n] != -1) return dp[n];
    return dp[n] = /* recursive calls */;
}
```

---

### **Tabulation (Bottom-Up)**
```
✓ Start from base case → build up to main problem
✓ Use iteration + dp array
✓ Better space/time optimization
✓ No recursion overhead (stack space)
```

**When to Use:**
- All subproblems must be solved anyway
- Need better space optimization
- Avoiding recursion depth limits
- Production/interview optimization phase

**Code Pattern:**
```cpp
vector<int> dp(n+1);
dp[0] = base_case;
for (int i = 1; i <= n; i++) {
    dp[i] = /* compute from dp[i-1], dp[i-2], etc. */;
}
return dp[n];
```

---

### **Comparison Table**

| Aspect | Memoization | Tabulation |
|--------|-------------|------------|
| Approach | Top-Down | Bottom-Up |
| Implementation | Recursion + Cache | Iteration + Array |
| Ease of Coding | Easier to think | Requires clear order |
| Space Complexity | O(n) + recursion stack | O(n) only |
| Time Complexity | Similar | Similar |
| Subproblems Solved | Only needed ones | All subproblems |

---

## 🏆 Famous DP Problems

### **Linear DP (1D)**
- Climbing Stairs
- House Robber
- Fibonacci Numbers
- Decode Ways
- Maximum Subarray (Kadane's)
- Longest Increasing Subsequence (LIS)
- Coin Change (minimum coins)
- Jump Game I & II

### **2D DP (Grid/Matrix)**
- Unique Paths
- Minimum Path Sum
- Longest Common Subsequence (LCS)
- Edit Distance
- Matrix Chain Multiplication
- Egg Dropping Problem
- Wildcard/Regex Matching

### **Knapsack Family**
- 0/1 Knapsack
- Unbounded Knapsack
- Subset Sum
- Partition Equal Subset Sum
- Target Sum

### **String DP**
- Longest Palindromic Subsequence
- Longest Palindromic Substring
- Palindrome Partitioning
- String Interleaving
- Distinct Subsequences

### **Tree DP**
- House Robber III
- Binary Tree Maximum Path Sum
- Diameter of Binary Tree

### **State Machine DP**
- Best Time to Buy and Sell Stock (all variants)
- Paint House
- Paint Fence

### **Interval DP**
- Burst Balloons
- Remove Boxes
- Minimum Cost Tree From Leaf Values

### **Bitmask DP**
- Traveling Salesman Problem (TSP)
- Assignment Problem
- Maximum Students Taking Exam

---

## 🎨 DP Problem Patterns

### **Pattern 1: Linear Sequence**
```
Current state depends on previous states
dp[i] = f(dp[i-1], dp[i-2], ...)
Example: Climbing Stairs, Fibonacci
```

### **Pattern 2: Choice Making**
```
At each position, make optimal choice
dp[i] = max/min(choice1, choice2, ...)
Example: House Robber, 0/1 Knapsack
```

### **Pattern 3: Grid Paths**
```
2D grid, find paths/costs
dp[i][j] = f(dp[i-1][j], dp[i][j-1])
Example: Unique Paths, Min Path Sum
```

### **Pattern 4: String Matching**
```
Compare two strings
dp[i][j] = match between s1[0...i] and s2[0...j]
Example: LCS, Edit Distance
```

### **Pattern 5: Partition/Subset**
```
Can we achieve target using array elements?
dp[sum] = possible or not
Example: Subset Sum, Partition Equal
```

---

## 💡 Quick Tips

1. **Start with Recursion**: Write brute force first, then add memoization
2. **Identify States**: What variables uniquely define a subproblem?
3. **Define Transitions**: How does one state lead to another?
4. **Base Cases**: What are the simplest inputs?
5. **Space Optimization**: Can you reduce dimensions? (rolling array technique)

---

## 🚀 Problem Solving Steps

1. **Identify** if it's a DP problem (overlapping + optimal substructure)
2. **Define** the state: What does `dp[i]` or `dp[i][j]` represent?
3. **Write** the recurrence relation
4. **Code** memoization first (easier)
5. **Optimize** to tabulation if needed
6. **Optimize** space if possible

---

## 📚 Companies That Love DP

**FAANG & Top Tech:**
- Google, Meta, Amazon, Apple, Microsoft
- Goldman Sachs, Morgan Stanley, JPMorgan
- Bloomberg, Adobe, Uber, Netflix

**Interview Frequency:** Very High ⭐⭐⭐⭐⭐

---

Happy Coding! 🎉
