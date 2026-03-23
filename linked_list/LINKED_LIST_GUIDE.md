# Linked List Data Structure - Complete Guide

## 📚 What is a Linked List?

A **Linked List** is a linear data structure where elements (nodes) are connected using pointers. Unlike arrays, elements are not stored in contiguous memory locations.

**Key Components**:
- **Node**: Contains data and pointer(s) to next node(s)
- **Head**: Pointer to first node
- **Tail**: Pointer to last node (optional)

## 🏗️ Node Structure

### Singly Linked List
```cpp
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};
```

### Doubly Linked List
```cpp
struct DoublyNode {
    int val;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};
```

### Circular Linked List
Last node points back to head instead of nullptr

## 🎯 Types of Linked Lists

### 1. Singly Linked List
Each node points to the next node only

**Advantages**:
- Simple implementation
- Less memory per node
- Efficient insertion/deletion at beginning

**Disadvantages**:
- Can't traverse backwards
- Harder to delete a node (need previous node)

**Operations**:
```cpp
class SinglyLinkedList {
    ListNode* head;
public:
    // Insert at beginning - O(1)
    void insertFront(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end - O(N)
    void insertEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if(!head) {
            head = newNode;
            return;
        }
        ListNode* curr = head;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // Delete node - O(N)
    void deleteNode(int val) {
        if(!head) return;

        if(head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* curr = head;
        while(curr->next && curr->next->val != val) {
            curr = curr->next;
        }

        if(curr->next) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    // Search - O(N)
    bool search(int val) {
        ListNode* curr = head;
        while(curr) {
            if(curr->val == val) return true;
            curr = curr->next;
        }
        return false;
    }
};
```

### 2. Doubly Linked List
Each node points to both next and previous nodes

**Advantages**:
- Can traverse in both directions
- Easier deletion (don't need to track previous)
- Efficient reverse traversal

**Disadvantages**:
- More memory (extra pointer)
- More complex insertion/deletion

**Operations**:
```cpp
class DoublyLinkedList {
    DoublyNode* head;
    DoublyNode* tail;
public:
    // Insert at end - O(1) with tail pointer
    void insertEnd(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if(!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete node - O(1) if node pointer given
    void deleteNode(DoublyNode* node) {
        if(!node) return;

        if(node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }

        if(node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }

        delete node;
    }
};
```

### 3. Circular Linked List
Last node points back to first node (forms a circle)

**Use Cases**:
- Round-robin scheduling
- Multiplayer games (turn-based)
- Music playlists (repeat mode)
- Buffer implementations

## 🔄 Common Operations & Complexities

| Operation | Singly | Doubly | Array |
|-----------|--------|--------|-------|
| Access by index | O(N) | O(N) | O(1) |
| Search | O(N) | O(N) | O(N) |
| Insert at beginning | O(1) | O(1) | O(N) |
| Insert at end | O(N) or O(1)* | O(1)** | O(1) |
| Insert at middle | O(N) | O(N) | O(N) |
| Delete at beginning | O(1) | O(1) | O(N) |
| Delete at end | O(N) | O(1)** | O(1) |
| Delete at middle | O(N) | O(1)*** | O(N) |

\* O(1) if tail pointer maintained
\** With tail pointer
\*** If node pointer provided

## 🎨 Essential Patterns & Techniques

### Pattern 1: Two Pointer (Fast & Slow)

**Detect Cycle** (Floyd's Algorithm):
```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}
```

**Find Cycle Start**:
```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Find meeting point
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(!fast || !fast->next) return nullptr;

    // Move slow to head, both move one step at a time
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

**Find Middle**:
```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // Middle node
}
```

**Find Nth from End**:
```cpp
ListNode* nthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast n steps ahead
    for(int i = 0; i < n; i++) {
        if(!fast) return nullptr;
        fast = fast->next;
    }

    // Move both until fast reaches end
    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

### Pattern 2: Reversal

**Reverse Entire List** (Iterative):
```cpp
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // New head
}
```

**Reverse Entire List** (Recursive):
```cpp
ListNode* reverse(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

**Reverse Between Positions**:
```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || left == right) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    // Move to left-1 position
    for(int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Reverse the sublist
    ListNode* curr = prev->next;
    for(int i = 0; i < right - left; i++) {
        ListNode* next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy.next;
}
```

**Reverse in K Groups**:
```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;

    // Check if k nodes exist
    while(curr && count < k) {
        curr = curr->next;
        count++;
    }

    if(count < k) return head;

    // Reverse k nodes
    curr = head;
    ListNode* prev = nullptr;
    for(int i = 0; i < k; i++) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Recursive call for remaining list
    head->next = reverseKGroup(curr, k);
    return prev;
}
```

### Pattern 3: Merge

**Merge Two Sorted Lists**:
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while(l1 && l2) {
        if(l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```

**Merge K Sorted Lists** (Using Min Heap):
```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

    // Add first node of each list
    for(ListNode* list : lists) {
        if(list) pq.push(list);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while(!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();

        tail->next = node;
        tail = tail->next;

        if(node->next) pq.push(node->next);
    }

    return dummy.next;
}
```

### Pattern 4: Reorder/Rearrange

**Reorder List** (L0 → Ln → L1 → Ln-1 → ...):
```cpp
void reorderList(ListNode* head) {
    if(!head || !head->next) return;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* second = reverse(slow->next);
    slow->next = nullptr;

    // Merge two halves
    ListNode* first = head;
    while(second) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}
```

**Odd Even List**:
```cpp
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while(even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}
```

### Pattern 5: Palindrome Check

**Check if Palindrome**:
```cpp
bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* second = reverse(slow->next);
    ListNode* first = head;

    // Compare
    while(second) {
        if(first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }
    return true;
}
```

### Pattern 6: Intersection & Union

**Intersection of Two Lists**:
```cpp
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if(!headA || !headB) return nullptr;

    ListNode* a = headA;
    ListNode* b = headB;

    // Both will travel same distance
    while(a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}
```

### Pattern 7: Remove/Delete Nodes

**Remove Nth From End**:
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // Move fast n+1 steps ahead
    for(int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both until fast reaches end
    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete node
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy.next;
}
```

**Remove Duplicates** (Sorted List):
```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;

    while(curr && curr->next) {
        if(curr->val == curr->next->val) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
```

**Remove All Duplicates**:
```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    while(head) {
        if(head->next && head->val == head->next->val) {
            // Skip all duplicates
            while(head->next && head->val == head->next->val) {
                head = head->next;
            }
            prev->next = head->next;
        } else {
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy.next;
}
```

### Pattern 8: Copy List with Random Pointer

**Deep Copy with Random Pointer**:
```cpp
Node* copyRandomList(Node* head) {
    if(!head) return nullptr;

    // Step 1: Create copy nodes interleaved
    Node* curr = head;
    while(curr) {
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Assign random pointers
    curr = head;
    while(curr) {
        if(curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate lists
    curr = head;
    Node* copyHead = head->next;
    Node* copy = copyHead;

    while(curr) {
        curr->next = curr->next->next;
        copy->next = copy->next ? copy->next->next : nullptr;
        curr = curr->next;
        copy = copy->next;
    }

    return copyHead;
}
```

## 📋 Common Problem Categories

### 1. Basic Operations
- Insert/Delete at beginning/end/middle
- Search element
- Get length
- Print list

### 2. Traversal Problems
- Nth node from end
- Middle of list
- Last node

### 3. Reversal Problems
- Reverse entire list
- Reverse in groups of K
- Reverse between positions

### 4. Detection Problems
- Detect cycle
- Find cycle start
- Detect intersection

### 5. Sorting & Merging
- Merge two sorted lists
- Merge K sorted lists
- Sort list (merge sort)

### 6. Reordering
- Reorder list
- Odd-even list
- Swap nodes in pairs
- Rotate list

### 7. Deletion Problems
- Remove duplicates
- Remove Nth from end
- Delete node (given only node pointer)

### 8. Comparison
- Compare two lists
- Check palindrome
- Identical lists

### 9. Mathematical
- Add two numbers
- Multiply two numbers
- Partition list

### 10. Advanced
- Copy list with random pointer
- Flatten multilevel list
- LRU Cache implementation

## 💡 Key Insights & Tips

### When to Use Linked Lists

**Use Linked Lists When**:
- Frequent insertions/deletions at beginning
- Don't know size beforehand (dynamic size)
- Don't need random access
- Memory is fragmented
- Implementing stacks, queues, graphs

**Avoid Linked Lists When**:
- Need random access by index
- Memory overhead is concern (pointers)
- Frequent search operations
- Cache performance matters (arrays are cache-friendly)
- Small, fixed-size data

### Common Techniques

1. **Dummy Node**: Simplifies edge cases (empty list, deletion of head)
```cpp
ListNode dummy(0);
dummy.next = head;
```

2. **Two Pointers**: Fast/slow, previous/current
```cpp
ListNode* slow = head;
ListNode* fast = head;
```

3. **Store Previous**: Track previous node for deletion
```cpp
ListNode* prev = nullptr;
ListNode* curr = head;
```

4. **Use Reference/Pointer to Pointer**: Modify head easily
```cpp
void func(ListNode*& head) { ... }
```

5. **Draw It Out**: Visualize pointer changes on paper

### Common Mistakes to Avoid

1. **Losing References**: Save next pointer before modifying
```cpp
ListNode* next = curr->next; // Save before modification
curr->next = prev;
```

2. **Null Pointer Dereference**:
```cpp
if(!head || !head->next) return head; // Check before access
```

3. **Memory Leaks**: Delete unused nodes
```cpp
ListNode* temp = head;
head = head->next;
delete temp;
```

4. **Cycle Creation**: Be careful when reversing
```cpp
head->next = nullptr; // Break cycle
```

5. **Off-by-One Errors**: Count carefully in loops
```cpp
for(int i = 0; i < n; i++) // Not i <= n
```

### Interview Tips

1. **Clarify Requirements**:
   - Singly or doubly linked?
   - Can we modify original list?
   - Circular linked list?
   - Any cycles present?

2. **Check Edge Cases**:
   - Empty list (nullptr)
   - Single node
   - Two nodes
   - Cycles present

3. **Draw Diagrams**: Visual representation helps

4. **State Complexity**: Time and space

5. **Test Edge Cases**: Walk through with examples

## 🔗 Linked List vs Array

| Feature | Linked List | Array |
|---------|-------------|-------|
| Memory | Non-contiguous | Contiguous |
| Size | Dynamic | Fixed (or expensive resize) |
| Access Time | O(N) | O(1) |
| Insert/Delete (beginning) | O(1) | O(N) |
| Insert/Delete (end) | O(1)* | O(1) |
| Insert/Delete (middle) | O(N) | O(N) |
| Memory Overhead | Extra (pointers) | None |
| Cache Performance | Poor | Good |
| Random Access | No | Yes |

\* With tail pointer

## 📚 Advanced Topics

- **Skip Lists**: O(log N) search in linked list
- **XOR Linked List**: Memory-efficient doubly linked list
- **Unrolled Linked List**: Hybrid of array and linked list
- **Self-Organizing Lists**: Move-to-front, transpose
- **Memory Pool**: Efficient node allocation
- **Lock-Free Lists**: Concurrent programming

## 🎯 Time Complexity Summary

| Operation | Time | Space |
|-----------|------|-------|
| Traverse | O(N) | O(1) |
| Search | O(N) | O(1) |
| Access by index | O(N) | O(1) |
| Insert at head | O(1) | O(1) |
| Insert at tail | O(N) or O(1)* | O(1) |
| Delete | O(N) | O(1) |
| Reverse | O(N) | O(1) |
| Detect cycle | O(N) | O(1) |
| Find middle | O(N) | O(1) |
| Merge two lists | O(N+M) | O(1) |
| Sort | O(N log N) | O(log N) |

\* O(1) with tail pointer

Remember: **Practice drawing pointer changes on paper** - it's the best way to master linked list problems!
