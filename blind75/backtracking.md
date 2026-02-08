# Backtracking Guide

## 🎯 What is Backtracking?

**Backtracking** is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, one piece at a time. When a partial solution is found to be invalid, the algorithm **backtracks** (removes the last piece) and tries another path.

Think of it as: **"Try → Fail → Undo → Try Again"**

### Key Characteristics:
- **Recursive approach**: Explore all possibilities
- **Decision Tree**: Each decision branches into multiple choices
- **Pruning**: Abandon paths that cannot lead to a solution (optimization)
- **State restore**: Undo choices when backtracking

---

## 🧠 When to Use Backtracking?

Use backtracking when you need to:

### 1. **Explore All Possible Solutions**
- Generate all permutations/combinations
- Find all valid configurations
- Enumerate all paths

### 2. **Find One/Any Valid Solution**
- N-Queens problem
- Sudoku solver
- Maze solving

### 3. **Decision Problems with Constraints**
- At each step, you have multiple choices
- Some choices lead to invalid states
- Need to explore all valid paths

### 4. **Optimization with Constraints**
- Find the best solution among all valid ones
- Prune branches that cannot improve the current best

---

## 🔑 Keywords to Identify Backtracking Problems

Look for these keywords in problem statements:

✅ **"Find all..."** - all permutations, all combinations, all subsets  
✅ **"Generate all..."** - all solutions, all configurations  
✅ **"Count all ways..."** - enumerate possibilities  
✅ **"Is it possible to..."** - existence problems with constraints  
✅ **"Place/Arrange..."** - with constraints (N-Queens, Sudoku)  
✅ **"Valid arrangements"** - parentheses, board configurations  
✅ **"Solve"** - puzzles like Sudoku, crosswords  
✅ **"Partition"** - split into valid groups meeting conditions  
✅ **"Path finding"** - with obstacles/constraints  

**Red Flags for Backtracking:**
- Multiple choices at each step
- Need to explore all possibilities
- Constraints that invalidate certain paths
- Can't use greedy or DP easily

---

## 📋 Common Backtracking Problem Types

### **1. Subset Problems**
- Subsets / Power Set
- Combination Sum (I, II, III)
- Subset Sum
- Partition to K Equal Sum Subsets

### **2. Permutation Problems**
- Permutations (with/without duplicates)
- Next Permutation
- Permutation Sequence
- Letter Case Permutation

### **3. Combination Problems**
- Combinations
- Combination Sum (I, II, III, IV)
- Phone Number Letter Combinations
- Generate Parentheses

### **4. Grid/Board Problems**
- N-Queens (I, II)
- Sudoku Solver
- Word Search (I, II)
- Rat in a Maze
- Knight's Tour

### **5. Partition Problems**
- Palindrome Partitioning
- Partition to K Equal Sum Subsets
- Matchsticks to Square

### **6. String Problems**
- Letter Combinations of Phone Number
- Generate Parentheses
- Restore IP Addresses
- Word Break II
- Palindrome Partitioning

### **7. Graph/Path Problems**
- All Paths from Source to Target
- Unique Paths with Obstacles
- Word Ladder II
- Expression Add Operators

### **8. Game/Puzzle Solving**
- Sudoku Solver
- N-Queens
- Crossword Puzzle
- Tic-Tac-Toe variants

---

## 🏗️ Backtracking Template

### Basic Template (Choice-based):
```cpp
void backtrack(state, choices, result) {
    // Base case: valid solution found
    if (is_solution(state)) {
        result.add(state);
        return;
    }
    
    // Iterate through all choices
    for (choice in choices) {
        // Prune: skip invalid choices
        if (!is_valid(choice, state)) continue;
        
        // Make choice
        state.add(choice);
        
        // Recurse
        backtrack(state, choices, result);
        
        // Undo choice (backtrack)
        state.remove(choice);
    }
}
```

### Extended Template (With Pruning):
```cpp
void backtrack(state, start, target, result) {
    // Base case
    if (meets_condition(state, target)) {
        result.add(state);
        return;
    }
    
    // Pruning: early termination
    if (exceeds_limit(state, target)) return;
    
    // Explore choices
    for (int i = start; i < choices.size(); i++) {
        // Skip duplicates (if needed)
        if (i > start && choices[i] == choices[i-1]) continue;
        
        // Make choice
        state.push_back(choices[i]);
        
        // Recurse (i or i+1 depending on reuse)
        backtrack(state, i, target, result);  // i for reuse, i+1 for no reuse
        
        // Backtrack
        state.pop_back();
    }
}
```

---

## 🎨 Backtracking Patterns

### **Pattern 1: Subsets (Include/Exclude)**
```
Each element: include or exclude
Time: O(2^n)
Example: Subsets, Combination Sum
```

### **Pattern 2: Permutations (Arrange Elements)**
```
Try each element at each position
Time: O(n!)
Example: Permutations, N-Queens
```

### **Pattern 3: Combinations (Select K from N)**
```
Choose k elements from n, order doesn't matter
Time: O(C(n,k))
Example: Combinations, Phone Number
```

### **Pattern 4: Partition (Split into Groups)**
```
Divide array/string into valid parts
Example: Palindrome Partitioning, IP Addresses
```

### **Pattern 5: Grid Traversal (DFS with Backtracking)**
```
Explore grid paths, mark visited, unmark on backtrack
Example: Word Search, N-Queens
```

---

## 🚀 Optimization Techniques

### 1. **Pruning**
Stop exploring branches that cannot lead to valid solutions.
```cpp
if (current_sum > target) return;  // No point continuing
```

### 2. **Sorting**
Sort input to enable pruning and skip duplicates easily.
```cpp
sort(candidates.begin(), candidates.end());
```

### 3. **Early Termination**
Return immediately when a solution is found (if only one needed).

### 4. **Deduplication**
Skip duplicate elements to avoid redundant computations.
```cpp
if (i > start && nums[i] == nums[i-1]) continue;
```

### 5. **Memoization (Hybrid)**
Cache results of subproblems if they repeat (backtracking + DP).

---

## 📊 Time Complexity Analysis

| Problem Type | Time Complexity | Space Complexity |
|--------------|-----------------|------------------|
| Subsets | O(2^n) | O(n) recursion |
| Permutations | O(n!) | O(n) recursion |
| Combinations C(n,k) | O(C(n,k)) | O(k) recursion |
| N-Queens | O(n!) | O(n²) board |
| Sudoku | O(9^empty) | O(1) modify in-place |
| Word Search | O(m·n·4^L) | O(L) recursion |

---

## 💡 Backtracking vs Other Approaches

### **Backtracking vs Brute Force**
- Brute Force: Try ALL combinations (even invalid ones)
- Backtracking: Prune invalid paths early (smarter brute force)

### **Backtracking vs DP**
- DP: Overlapping subproblems + optimal substructure
- Backtracking: No overlapping subproblems (or rare)
- Use DP when: subproblems repeat often
- Use Backtracking when: need all solutions or path matters

### **Backtracking vs Greedy**
- Greedy: Make locally optimal choice
- Backtracking: Try all choices, undo if needed
- Use Greedy when: local optimum = global optimum
- Use Backtracking when: need to explore all options

---

## 🎯 Famous LeetCode Backtracking Problems

### **Easy:**
- Generate Parentheses (LC 22)
- Letter Case Permutation (LC 784)

### **Medium:**
- Subsets (LC 78) ⭐
- Subsets II (LC 90)
- Permutations (LC 46) ⭐
- Permutations II (LC 47)
- Combinations (LC 77)
- Combination Sum (LC 39) ⭐
- Combination Sum II (LC 40)
- Combination Sum III (LC 216)
- Phone Number Letter Combinations (LC 17) ⭐
- Palindrome Partitioning (LC 131)
- Word Search (LC 79) ⭐
- Restore IP Addresses (LC 93)
- Target Sum (LC 494)

### **Hard:**
- N-Queens (LC 51) ⭐
- N-Queens II (LC 52)
- Sudoku Solver (LC 37) ⭐
- Word Search II (LC 212)
- Expression Add Operators (LC 282)
- Remove Invalid Parentheses (LC 301)

---

## 📚 Companies That Love Backtracking

**FAANG & Top Tech:**
- Google, Amazon, Microsoft, Meta, Apple
- Bloomberg, Adobe, Uber
- Airbnb, Snapchat

**Interview Frequency:** High ⭐⭐⭐⭐

---

## 🔍 Quick Decision Tree

**Q: Does the problem ask for "all" solutions?**  
→ Yes → Likely Backtracking

**Q: Do you need to try multiple choices at each step?**  
→ Yes → Likely Backtracking

**Q: Are there constraints that invalidate certain paths?**  
→ Yes → Likely Backtracking with Pruning

**Q: Is it a puzzle/game solving problem?**  
→ Yes → Likely Backtracking

**Q: Can you use DP (overlapping subproblems)?**  
→ No → Consider Backtracking

---

## 💻 Implementation Tips

1. **Define your state clearly**: What info do you need at each step?
2. **Identify choices**: What are valid options at each step?
3. **Write base case first**: When is a solution complete?
4. **Add pruning**: What paths are guaranteed invalid?
5. **Remember to backtrack**: Undo changes before trying next choice
6. **Handle duplicates**: Sort + skip to avoid redundant work
7. **Test with small inputs**: Trace execution manually

---

## 🎓 Practice Strategy

1. **Start with**: Subsets → Combinations → Permutations
2. **Then try**: Combination Sum variants
3. **Challenge**: N-Queens → Sudoku Solver
4. **Master**: Word Search II, all path problems

---

Happy Backtracking! 🚀
