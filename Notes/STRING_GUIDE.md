# String Data Structure - Complete Guide

## 📚 What is a String?

A **String** is a sequence of characters, typically used to represent text. In most programming languages, strings are immutable or have specific handling rules.

**Key Properties**:
- **Immutable** in many languages (Java, Python, JavaScript)
- **Mutable** in C/C++ (char arrays) and StringBuilder in Java
- **Indexed**: Access characters by position (0-based)
- **Length**: Number of characters in string

## 🏗️ String Representation

### C++ String
```cpp
string s = "hello";
char c = s[0];           // Access: O(1)
s += "world";            // Concatenation: O(N)
int len = s.length();    // or s.size()
string sub = s.substr(1, 3); // substring from index 1, length 3
```

### C-Style String
```cpp
char str[] = "hello";
char* ptr = "world";
int len = strlen(str);   // O(N)
strcpy(dest, src);       // Copy
strcat(dest, src);       // Concatenate
strcmp(str1, str2);      // Compare
```

## 🎯 String Operations & Complexity

| Operation | C++ String | C-Style | Complexity |
|-----------|------------|---------|------------|
| Access char | s[i] | str[i] | O(1) |
| Length | s.length() | strlen(str) | O(1) / O(N) |
| Concatenate | s1 + s2 | strcat | O(N) |
| Substring | substr() | Custom | O(N) |
| Compare | ==, compare() | strcmp | O(N) |
| Search | find() | strstr | O(N*M) |
| Insert | insert() | Custom | O(N) |
| Delete | erase() | Custom | O(N) |

## 🎨 Common String Patterns

### Pattern 1: Two Pointers

**Valid Palindrome**:
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while(left < right) {
        if(!isalnum(s[left])) {
            left++;
        } else if(!isalnum(s[right])) {
            right--;
        } else if(tolower(s[left]) != tolower(s[right])) {
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}
```

**Reverse String**:
```cpp
void reverseString(string& s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        swap(s[left++], s[right--]);
    }
}
```

**Reverse Words**:
```cpp
string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int n = s.length();
    int start = 0, end = 0;

    while(end < n) {
        while(end < n && s[end] != ' ') end++;
        reverse(s.begin() + start, s.begin() + end);
        end++;
        start = end;
    }
    return s;
}
```

### Pattern 2: Sliding Window

**Longest Substring Without Repeating Characters**:
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int maxLen = 0, start = 0;

    for(int end = 0; end < s.length(); end++) {
        if(map.count(s[end])) {
            start = max(start, map[s[end]] + 1);
        }
        map[s[end]] = end;
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}
```

**Minimum Window Substring**:
```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> map, window;
    for(char c : t) map[c]++;

    int left = 0, right = 0;
    int required = map.size();
    int formed = 0;
    int minLen = INT_MAX, minStart = 0;

    while(right < s.length()) {
        char c = s[right];
        window[c]++;

        if(map.count(c) && window[c] == map[c]) {
            formed++;
        }

        while(formed == required && left <= right) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char leftChar = s[left];
            window[leftChar]--;
            if(map.count(leftChar) && window[leftChar] < map[leftChar]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}
```

**Longest Repeating Character Replacement**:
```cpp
int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int maxCount = 0, maxLen = 0, start = 0;

    for(int end = 0; end < s.length(); end++) {
        maxCount = max(maxCount, ++count[s[end] - 'A']);

        // If we need to replace more than k characters
        while(end - start + 1 - maxCount > k) {
            count[s[start] - 'A']--;
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}
```

### Pattern 3: Hashing & Frequency Count

**Anagram Check**:
```cpp
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    vector<int> count(26, 0);
    for(int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for(int c : count) {
        if(c != 0) return false;
    }
    return true;
}
```

**Group Anagrams**:
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;

    for(string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }

    vector<vector<string>> result;
    for(auto& [key, group] : map) {
        result.push_back(group);
    }
    return result;
}
```

**First Unique Character**:
```cpp
int firstUniqChar(string s) {
    vector<int> count(26, 0);
    for(char c : s) {
        count[c - 'a']++;
    }

    for(int i = 0; i < s.length(); i++) {
        if(count[s[i] - 'a'] == 1) return i;
    }
    return -1;
}
```

### Pattern 4: String Manipulation

**String Compression**:
```cpp
string compress(string s) {
    string result;
    int i = 0, n = s.length();

    while(i < n) {
        char c = s[i];
        int count = 0;

        while(i < n && s[i] == c) {
            i++;
            count++;
        }

        result += c;
        if(count > 1) {
            result += to_string(count);
        }
    }

    return result.length() < s.length() ? result : s;
}
```

**String Rotation**:
```cpp
bool isRotation(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    string doubled = s1 + s1;
    return doubled.find(s2) != string::npos;
}
```

**Remove Duplicates**:
```cpp
string removeDuplicates(string s) {
    string result;
    for(char c : s) {
        if(result.empty() || result.back() != c) {
            result.push_back(c);
        } else {
            result.pop_back(); // Remove adjacent duplicate
        }
    }
    return result;
}
```

### Pattern 5: String Matching (Pattern Search)

**Naive Pattern Matching**: O((N-M+1) * M)
```cpp
int naiveSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();

    for(int i = 0; i <= n - m; i++) {
        int j = 0;
        while(j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if(j == m) return i; // Pattern found
    }
    return -1;
}
```

**KMP Algorithm**: O(N + M)
```cpp
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m);
    int len = 0, i = 1;

    while(i < m) {
        if(pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if(len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

int KMPSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while(i < n) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == m) {
            return i - j; // Pattern found
        } else if(i < n && text[i] != pattern[j]) {
            if(j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}
```

**Rabin-Karp Algorithm**: O(N + M) average, O(N*M) worst
```cpp
int rabinKarp(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    int prime = 101;
    long long patternHash = 0, textHash = 0;
    long long h = 1;

    // Calculate h = pow(256, m-1) % prime
    for(int i = 0; i < m - 1; i++) {
        h = (h * 256) % prime;
    }

    // Calculate initial hash
    for(int i = 0; i < m; i++) {
        patternHash = (256 * patternHash + pattern[i]) % prime;
        textHash = (256 * textHash + text[i]) % prime;
    }

    // Slide pattern over text
    for(int i = 0; i <= n - m; i++) {
        if(patternHash == textHash) {
            bool match = true;
            for(int j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if(match) return i;
        }

        if(i < n - m) {
            textHash = (256 * (textHash - text[i] * h) + text[i + m]) % prime;
            if(textHash < 0) textHash += prime;
        }
    }
    return -1;
}
```

### Pattern 6: Palindrome Problems

**Longest Palindromic Substring** (Expand Around Center):
```cpp
string expandAroundCenter(string s, int left, int right) {
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if(s.empty()) return "";
    string longest;

    for(int i = 0; i < s.length(); i++) {
        string odd = expandAroundCenter(s, i, i);     // Odd length
        string even = expandAroundCenter(s, i, i + 1); // Even length

        string current = odd.length() > even.length() ? odd : even;
        if(current.length() > longest.length()) {
            longest = current;
        }
    }
    return longest;
}
```

**Longest Palindromic Substring** (DP):
```cpp
string longestPalindrome(string s) {
    int n = s.length();
    if(n == 0) return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    // All single characters are palindromes
    for(int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for length 2
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check for lengths > 2
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if(s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
}
```

**Palindrome Partitioning**:
```cpp
bool isPalindrome(string s, int left, int right) {
    while(left < right) {
        if(s[left++] != s[right--]) return false;
    }
    return true;
}

void backtrack(string s, int start, vector<string>& current,
               vector<vector<string>>& result) {
    if(start >= s.length()) {
        result.push_back(current);
        return;
    }

    for(int end = start; end < s.length(); end++) {
        if(isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    backtrack(s, 0, current, result);
    return result;
}
```

### Pattern 7: Subsequence Problems

**Longest Common Subsequence (LCS)**:
```cpp
int longestCommonSubsequence(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
```

**Is Subsequence**:
```cpp
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;

    while(i < s.length() && j < t.length()) {
        if(s[i] == t[j]) i++;
        j++;
    }
    return i == s.length();
}
```

**Longest Increasing Subsequence (LIS) in String**:
```cpp
int lengthOfLIS(string s) {
    vector<int> dp;

    for(char c : s) {
        auto it = lower_bound(dp.begin(), dp.end(), c);
        if(it == dp.end()) {
            dp.push_back(c);
        } else {
            *it = c;
        }
    }
    return dp.size();
}
```

### Pattern 8: String DP Problems

**Edit Distance**:
```cpp
int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],     // Delete
                                     dp[i][j - 1],     // Insert
                                     dp[i - 1][j - 1]}); // Replace
            }
        }
    }
    return dp[m][n];
}
```

**Wildcard Matching**:
```cpp
bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    // Handle patterns like *, **, etc.
    for(int j = 1; j <= n; j++) {
        if(p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else if(p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[m][n];
}
```

### Pattern 9: String Parsing & Tokenization

**Split String by Delimiter**:
```cpp
vector<string> split(string s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;

    while(getline(ss, token, delimiter)) {
        if(!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}
```

**Custom String Parser**:
```cpp
string simplifyPath(string path) {
    vector<string> stack;
    stringstream ss(path);
    string dir;

    while(getline(ss, dir, '/')) {
        if(dir.empty() || dir == ".") continue;
        if(dir == "..") {
            if(!stack.empty()) stack.pop_back();
        } else {
            stack.push_back(dir);
        }
    }

    string result;
    for(string d : stack) {
        result += "/" + d;
    }
    return result.empty() ? "/" : result;
}
```

## 📋 Common Problem Categories

### 1. Basic Operations
- Reverse string
- Check palindrome
- Count characters/words
- String comparison

### 2. Pattern Matching
- Find substring
- KMP algorithm
- Rabin-Karp algorithm
- Regular expression matching

### 3. Sliding Window
- Longest substring without repeating
- Minimum window substring
- Longest repeating character replacement

### 4. Two Pointers
- Valid palindrome
- Reverse words
- Container with most water

### 5. Hashing
- Anagram problems
- Group anagrams
- First unique character
- Frequency count

### 6. DP Problems
- Longest common subsequence
- Edit distance
- Longest palindromic substring
- Word break

### 7. Manipulation
- String compression
- Remove duplicates
- Encode/decode strings

### 8. Parsing
- Parse expressions
- Simplify paths
- IP address validation

### 9. Backtracking
- Generate parentheses
- Letter combinations
- Palindrome partitioning

### 10. Trie-based
- Implement Trie
- Word search II
- Autocomplete

## 💡 Key Insights & Tips

### String Immutability

**Immutable (Java, Python)**:
```java
String s = "hello";
s += "world"; // Creates new string object
```

**Mutable (StringBuilder)**:
```java
StringBuilder sb = new StringBuilder("hello");
sb.append("world"); // Modifies existing object
```

### Character Operations

```cpp
// C++ character functions
isalpha(c)   // Check if alphabetic
isdigit(c)   // Check if digit
isalnum(c)   // Check if alphanumeric
tolower(c)   // Convert to lowercase
toupper(c)   // Convert to uppercase
isspace(c)   // Check if whitespace
```

### Common Techniques

1. **Use StringBuilder/StringBuffer** for multiple concatenations
2. **Two Pointers** for palindrome/reversal
3. **Sliding Window** for substring problems
4. **Hashing** for anagram/frequency problems
5. **DP** for subsequence/matching problems
6. **Trie** for prefix/dictionary problems

### Time Complexity Tips

| Operation | Complexity |
|-----------|------------|
| String concatenation | O(N) |
| Substring | O(N) |
| String comparison | O(N) |
| Character access | O(1) |
| Find substring (naive) | O(N*M) |
| Find substring (KMP) | O(N+M) |
| Sort string | O(N log N) |

### Interview Tips

1. **Ask about character set**: ASCII (128), Extended ASCII (256), Unicode?
2. **Clarify case sensitivity**: "Hello" == "hello"?
3. **Handle spaces and special characters**
4. **Consider string size**: Small strings vs large text
5. **Test edge cases**: Empty string, single character, all same characters

### Common Edge Cases

- Empty string: `""`
- Single character: `"a"`
- All same characters: `"aaaa"`
- No matching pattern
- Entire string is pattern
- Special characters: spaces, punctuation
- Case sensitivity
- Unicode characters

## 📚 Advanced Topics

### 1. Suffix Array
- Used for pattern matching
- Construction: O(N log N)
- Pattern search: O(M log N)

### 2. Suffix Tree
- Fast pattern matching
- Longest repeated substring
- Construction: O(N)

### 3. Aho-Corasick Algorithm
- Multiple pattern matching
- Used in grep, antivirus
- O(N + M + Z) where Z is matches

### 4. Z-Algorithm
- Linear time pattern matching
- Z-array construction

### 5. Manacher's Algorithm
- Find longest palindrome in O(N)

### 6. Regular Expressions
- Pattern matching with wildcards
- Dynamic programming solution

## 🎯 When to Use Strings

**Use Strings When**:
- Text processing
- Pattern matching
- Data serialization
- User input handling
- File path manipulation
- URL parsing
- DNA sequence analysis
- Lexical analysis

**Consider Alternatives**:
- **Large datasets**: Use Trie for prefix searches
- **Frequent mutations**: Use char array or StringBuilder
- **Pattern matching**: Use specialized algorithms (KMP, Rabin-Karp)
- **Storage**: Consider compression for large texts

## Summary Table

| Problem Type | Common Approach | Time Complexity |
|--------------|----------------|-----------------|
| Palindrome | Two pointers | O(N) |
| Anagram | Hashing/Sorting | O(N) / O(N log N) |
| Substring search | KMP/Rabin-Karp | O(N + M) |
| Longest palindrome | DP / Expand center | O(N²) / O(N²) |
| Edit distance | DP | O(M × N) |
| Group anagrams | Hashing | O(N × K log K) |
| Sliding window | Two pointers | O(N) |
| Pattern matching | KMP | O(N + M) |

Remember: **Strings are fundamental** - master these patterns and you'll handle most string problems efficiently!
