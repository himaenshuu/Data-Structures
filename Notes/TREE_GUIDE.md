# Binary Tree & Tree Data Structure - Complete Guide

## 📚 What is a Tree?

A **Tree** is a hierarchical non-linear data structure consisting of:
- **Root**: Top node with no parent
- **Nodes**: Elements containing data and pointers to children
- **Edges**: Connections between nodes
- **Children**: Nodes directly connected below a node
- **Parent**: Node directly connected above
- **Leaf**: Node with no children
- **Subtree**: Tree formed by a node and its descendants

## 🌳 Tree Terminology

- **Height**: Longest path from node to leaf (leaf height = 0)
- **Depth/Level**: Distance from root (root depth = 0)
- **Degree**: Number of children a node has
- **Ancestor**: All nodes on path from node to root
- **Descendant**: All nodes in node's subtree

## 🏗️ Tree Node Structure

### Basic Binary Tree Node
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

### N-ary Tree Node
```cpp
struct Node {
    int val;
    vector<Node*> children;

    Node(int x) : val(x) {}
};
```

### Advanced Node (with parent pointer)
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};
```

## 🎯 Types of Trees

### 1. Binary Tree
Each node has **at most 2 children** (left and right)

**Properties**:
- Max nodes at level L: 2^L
- Max nodes in tree of height H: 2^(H+1) - 1
- Min height for N nodes: log₂(N+1) - 1

### 2. Binary Search Tree (BST)
**Properties**:
- Left subtree values < node value
- Right subtree values > node value
- No duplicate values (typically)
- Inorder traversal gives sorted order

**Operations**: O(log N) average, O(N) worst
```cpp
TreeNode* search(TreeNode* root, int key) {
    if(!root || root->val == key) return root;
    if(key < root->val) return search(root->left, key);
    return search(root->right, key);
}

TreeNode* insert(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
```

### 3. Complete Binary Tree
- All levels filled except possibly the last
- Last level filled from left to right
- Used in **Heaps**
- Can be stored in array: parent at i, children at 2i+1 and 2i+2

### 4. Full Binary Tree
Every node has **0 or 2 children** (no node has only 1 child)

### 5. Perfect Binary Tree
- All internal nodes have 2 children
- All leaves at same level
- Nodes = 2^(H+1) - 1

### 6. Balanced Binary Tree
**Height-balanced**: Height difference between left and right subtrees ≤ 1 for all nodes
- **AVL Tree**: Self-balancing BST (balance factor: -1, 0, 1)
- **Red-Black Tree**: Self-balancing with color property
- Ensures O(log N) operations

### 7. Degenerate/Skewed Tree
Every parent has only one child (essentially a linked list)
- Performance degrades to O(N)

## 🔄 Tree Traversal Techniques

### 1. Depth-First Search (DFS)

#### Inorder (Left → Root → Right)
```cpp
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```
**Use**: BST sorted order, expression evaluation

#### Preorder (Root → Left → Right)
```cpp
void preorder(TreeNode* root) {
    if(!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```
**Use**: Copy tree, prefix expression, serialize tree

#### Postorder (Left → Right → Root)
```cpp
void postorder(TreeNode* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```
**Use**: Delete tree, postfix expression, calculate subtree info

#### Iterative DFS
```cpp
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr || !st.empty()) {
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}
```

### 2. Breadth-First Search (BFS) - Level Order

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}
```

**Use**: Level-by-level processing, shortest path, find level

## 🎨 Common Tree Patterns

### Pattern 1: Tree Properties

**Height of Tree**:
```cpp
int height(TreeNode* root) {
    if(!root) return -1; // or 0 depending on definition
    return 1 + max(height(root->left), height(root->right));
}
```

**Diameter of Tree**:
```cpp
int diameterHelper(TreeNode* root, int& diameter) {
    if(!root) return 0;

    int left = diameterHelper(root->left, diameter);
    int right = diameterHelper(root->right, diameter);

    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}

int diameter(TreeNode* root) {
    int diameter = 0;
    diameterHelper(root, diameter);
    return diameter;
}
```

**Check if Balanced**:
```cpp
int checkHeight(TreeNode* root, bool& balanced) {
    if(!root) return 0;

    int left = checkHeight(root->left, balanced);
    int right = checkHeight(root->right, balanced);

    if(abs(left - right) > 1) balanced = false;

    return 1 + max(left, right);
}
```

### Pattern 2: Path Problems

**Root to Leaf Path Sum**:
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root) return false;

    if(!root->left && !root->right) {
        return root->val == targetSum;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}
```

**All Root to Leaf Paths**:
```cpp
void findPaths(TreeNode* root, vector<int>& path, vector<vector<int>>& result) {
    if(!root) return;

    path.push_back(root->val);

    if(!root->left && !root->right) {
        result.push_back(path);
    } else {
        findPaths(root->left, path, result);
        findPaths(root->right, path, result);
    }

    path.pop_back(); // Backtrack
}
```

**Lowest Common Ancestor (LCA)**:
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left && right) return root; // Found both in different subtrees
    return left ? left : right;
}
```

### Pattern 3: View Problems

**Right Side View**:
```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    if(root) q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if(i == size - 1) result.push_back(node->val); // Rightmost

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return result;
}
```

**Vertical Order Traversal**:
```cpp
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; // {col: {row: [values]}}
    queue<tuple<TreeNode*, int, int>> q; // {node, row, col}

    q.push({root, 0, 0});

    while(!q.empty()) {
        auto [node, row, col] = q.front();
        q.pop();

        nodes[col][row].insert(node->val);

        if(node->left) q.push({node->left, row + 1, col - 1});
        if(node->right) q.push({node->right, row + 1, col + 1});
    }

    vector<vector<int>> result;
    for(auto& [col, rows] : nodes) {
        vector<int> column;
        for(auto& [row, values] : rows) {
            column.insert(column.end(), values.begin(), values.end());
        }
        result.push_back(column);
    }
    return result;
}
```

### Pattern 4: Construction Problems

**Build Tree from Inorder + Preorder**:
```cpp
TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd,
                unordered_map<int, int>& inMap) {
    if(preStart > preEnd || inStart > inEnd) return nullptr;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart + 1, preStart + numsLeft,
                       inorder, inStart, inRoot - 1, inMap);
    root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                        inorder, inRoot + 1, inEnd, inMap);

    return root;
}
```

### Pattern 5: Validation

**Valid BST**:
```cpp
bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) {
    if(!root) return true;

    if(root->val <= min || root->val >= max) return false;

    return isValidBST(root->left, min, root->val) &&
           isValidBST(root->right, root->val, max);
}
```

**Same Tree**:
```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;

    return p->val == q->val &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
```

**Symmetric Tree**:
```cpp
bool isSymmetric(TreeNode* left, TreeNode* right) {
    if(!left && !right) return true;
    if(!left || !right) return false;

    return left->val == right->val &&
           isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return root ? isSymmetric(root->left, root->right) : true;
}
```

### Pattern 6: Serialization

**Serialize/Deserialize**:
```cpp
string serialize(TreeNode* root) {
    if(!root) return "null,";
    return to_string(root->val) + "," +
           serialize(root->left) +
           serialize(root->right);
}

TreeNode* deserialize(queue<string>& q) {
    string val = q.front();
    q.pop();

    if(val == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserialize(q);
    root->right = deserialize(q);
    return root;
}
```

### Pattern 7: Morris Traversal
**Space O(1) traversal** using threaded binary tree
```cpp
vector<int> morris(TreeNode* root) {
    vector<int> result;
    TreeNode* curr = root;

    while(curr) {
        if(!curr->left) {
            result.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* pre = curr->left;
            while(pre->right && pre->right != curr) {
                pre = pre->right;
            }

            if(!pre->right) {
                pre->right = curr; // Create thread
                curr = curr->left;
            } else {
                pre->right = nullptr; // Remove thread
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return result;
}
```

## 📋 Common Problem Categories

### 1. Traversal Problems
- Binary Tree Inorder/Preorder/Postorder
- Level Order Traversal
- Zigzag Level Order
- Vertical Order Traversal

### 2. Property Problems
- Maximum Depth
- Minimum Depth
- Diameter of Binary Tree
- Balanced Binary Tree
- Count Complete Tree Nodes

### 3. Path Problems
- Binary Tree Paths
- Path Sum I, II, III
- Sum Root to Leaf Numbers
- Maximum Path Sum

### 4. View Problems
- Right Side View
- Left Side View
- Top View
- Bottom View

### 5. Ancestor Problems
- Lowest Common Ancestor
- Kth Ancestor
- All Ancestors of a Node

### 6. Construction Problems
- Construct from Inorder + Preorder
- Construct from Inorder + Postorder
- Construct from Level Order

### 7. BST Problems
- Validate BST
- Kth Smallest Element
- Two Sum IV
- Convert Sorted Array to BST
- Recover BST

### 8. Modification Problems
- Invert Binary Tree
- Flatten to Linked List
- Merge Two Trees
- Trim a BST

### 9. Comparison Problems
- Same Tree
- Symmetric Tree
- Subtree of Another Tree
- Is Balanced

### 10. Serialization
- Serialize and Deserialize Binary Tree
- Serialize and Deserialize BST

## 🧠 When to Use Trees

| Use Case | Tree Type | Why |
|----------|-----------|-----|
| Fast search/insert/delete | BST/AVL/Red-Black | O(log N) operations |
| Hierarchical data | General Tree | Natural hierarchy |
| Priority operations | Heap (Complete Binary Tree) | O(log N) extract-min/max |
| Expression parsing | Binary Tree | Natural recursion |
| File systems | N-ary Tree | Multiple children |
| Autocomplete | Trie | Prefix matching |
| Range queries | Segment Tree | O(log N) queries |
| Database indexing | B-Tree/B+ Tree | Balanced, disk-friendly |

## 💡 Key Insights

1. **Recursion is Natural**: Trees are recursive structures - most problems solved recursively

2. **Base Case**: Always handle `nullptr` (empty tree/subtree)

3. **Choice of Traversal**:
   - **Preorder**: Create/copy structure
   - **Inorder**: BST in sorted order
   - **Postorder**: Delete/calculate from bottom-up
   - **Level Order**: Level-by-level processing

4. **DFS vs BFS**:
   - DFS: Memory efficient (O(H) stack), good for deep trees
   - BFS: Better for wide trees, finds shortest path

5. **Time Complexity**:
   - Traversal: O(N) - visit each node once
   - Height: O(N) worst case, O(log N) balanced
   - Search in BST: O(log N) average, O(N) worst

6. **Space Complexity**:
   - Recursion: O(H) stack space
   - BFS: O(W) where W is max width
   - Morris: O(1) but modifies tree temporarily

7. **Common Mistakes**:
   - Forgetting null checks
   - Not returning values in recursion
   - Confusing height (edges) vs depth (nodes)
   - Not handling edge cases (single node, empty tree)

## 🎯 Interview Tips

1. **Clarify Requirements**:
   - Binary tree or BST?
   - Complete/balanced/full?
   - Null nodes allowed?
   - Value ranges?

2. **Start with Traversal**: Most problems require some form of traversal

3. **Think Recursively**: What do I need from left/right subtrees?

4. **Consider Both Approaches**: Recursive (cleaner) vs Iterative (explicit control)

5. **Edge Cases to Test**:
   - Empty tree (nullptr)
   - Single node
   - Skewed tree (all left or all right)
   - Perfect binary tree

6. **Optimization**:
   - Can you solve in one pass?
   - Can you avoid extra space? (Morris traversal)
   - Can you prune unnecessary subtrees?

7. **Common Techniques**:
   - Helper function with extra parameters
   - Return multiple values (tuple/struct)
   - Pass by reference for global state
   - Post-process after recursion

## 📚 Advanced Topics

- **Self-Balancing Trees**: AVL, Red-Black, Splay
- **Segment Trees**: Range query problems
- **Fenwick Tree (BIT)**: Prefix sum queries
- **Trie**: Prefix-based problems
- **B-Trees**: Database indexing
- **Treap**: Randomized BST
- **Expression Trees**: Compiler design
- **Huffman Tree**: Data compression

## 🔗 Tree vs Other Structures

| Structure | Access | Search | Insert | Delete | Use Case |
|-----------|--------|--------|--------|--------|----------|
| Array | O(1) | O(N) | O(N) | O(N) | Random access |
| Linked List | O(N) | O(N) | O(1) | O(1) | Sequential |
| BST | O(log N) | O(log N) | O(log N) | O(log N) | Dynamic sorted data |
| Hash Table | O(1) | O(1) | O(1) | O(1) | Key-value pairs |
| Heap | O(1) peek | O(N) | O(log N) | O(log N) | Priority queue |

**Choose Trees When**: You need hierarchical structure + efficient search/insert/delete operations
